#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <io.h>
#include <string.h>
#include "moviFloat32.h"

using namespace std;

unsigned short f32Tof16(float v)
{   /*
    input: float(4 bytes)
    output: unsigned short(2 bytes)
    */
    unsigned int x = *(unsigned int *)&v;
    unsigned int rnd_mode = 0;
    unsigned int exceptions;
    unsigned int res = f32_to_f16_conv(x, rnd_mode, &exceptions);
    return (unsigned short)res;
}

float f16Tof32(unsigned short v)
{   /*
    input: unsigned short(2 bytes)
    output: float(4 bytes)
    */
    unsigned int x = (unsigned int)v;
    unsigned int exceptions;
    unsigned int res = f16_to_f32_conv(x, &exceptions);
    return *(float *)&res;
}

void read_fp16_bin(const string& name, const int& end, const int& start = 0)
{   /*
    input: bin file containing fp16
    output: corresponding floats in the range start~end
    */
    unsigned short *pos = new unsigned short[end];

    ifstream f("bin/" + name, ios::binary);
    f.read((char* )pos, end * sizeof(unsigned short));
    for(int i = start; i < end; ++i)
    {
        printf("unsigned int: %6d, float: %f\n", pos[i], f16Tof32(pos[i]));
    }
    f.close();

    delete[] pos;
}

void load_fp16_bin(const string& name, vector<float> &vf)
{   /*
    input: bin file containing fp16
    output: vector of corresponding floats
    */
    ifstream f("bin/" + name, ios::binary);
    f.seekg(0, ios::end);
    int size = f.tellg();
    int num = size / sizeof(unsigned short);
    printf("file size: %d bytes, num of fp16: %d\n", size, num);
    f.clear();
    f.seekg(0, ios::beg);

    unsigned short *pos = new unsigned short[num];

    f.read((char* )pos, size);
    for(int i = 0; i < num; ++i)
    {
        vf.push_back(f16Tof32(pos[i]));
    }
    f.close();

    delete[] pos;
}

float get_norm(vector<float> &vf)
{   /*
    input: vector of float
    output: norm of the vector
    */
    float sum = 0;
    for (auto i : vf)
    {
        sum += i * i;
    }
    return sqrt(sum);
}

void get_files(const string& path, vector<string>& files)
{   /*
    input: a directory
    output: vector of string containing all files in the directory and its sub-directory
    */
    long  hFile = 0; 
    struct _finddata_t fileinfo;
    string p;
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) !=  -1)
    {
        do
        {
            if((fileinfo.attrib &  _A_SUBDIR))
            {
                if(strcmp(fileinfo.name, ".") != 0  &&  strcmp(fileinfo.name, "..") != 0)
                    get_files(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            else
            {
                files.push_back(fileinfo.name);
            }
        }while(_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

void get_norm_folder(const string& folder, const string& suf)
{   /*
    calculate the norm of each file with suf in the folder
    */
    vector<string> files;
    get_files(folder, files);
    for (auto file : files)
    {
        if (strstr(file.c_str(), suf.c_str()))
        {
            vector<float> vf;
            load_fp16_bin(file, vf);
            printf("%s: %f\n", file.c_str(), get_norm(vf));
        }
    }
}

void test()
{
    float x = 123.5;
    unsigned short y = f32Tof16(x);
    float z = f16Tof32(y);
    printf("%f %d %f\n", x, y, z);
}

int main()
{
    // test();

    // vector<float> vf;
    // read_fp16_bin("ft_lib", 2298*1024 + 10, 2298*1024);

    // vector<float> vf;
    // load_fp16_bin("xiaohong.ft", vf);
    // printf("norm: %f\n", get_norm(vf));

    get_norm_folder("bin", ".ft");
}