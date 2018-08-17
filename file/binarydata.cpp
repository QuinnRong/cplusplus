#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

void txt2bin(const string& name)
{   /*
    input: txt data(int or float 0~255, float 0~1)
    n c h w
    val val ...
    output: bin data(float 0~255)
    */
    ifstream in("txt/" + name + ".txt");
    int n, c, h, w;
    in >> n >> c >> h >> w;
    printf("n=%d, c=%d, h=%d, w=%d\n", n, c, h, w);
    int num = n*c*h*w;

    float *pos = new float[num];
    float tmp, max = 0;
    for (int i = 0; i < num; ++i)
    {
        in >> tmp;
        pos[i] = tmp;
        if (tmp > max) max = tmp;
    }
    if (max > 1)
    {
        printf("input format: int or float 0~255\n");
    }
    else
    {
        printf("input format: float 0~1\n");
        for (int i = 0; i < num; ++i)
        {
            pos[i] *= 255;
        }
    }
    in.close();

    ofstream out("bin/" + name + ".bin", ios::binary);
    out.write((char* )pos, num * sizeof(float));
    out.close();

    delete[] pos;
}

void bin2txt(const string& name, const int& n, const int& c, const int& h, const int& w)
{   /*
    input: bin data(int or float 0~255, float 0~1)
    output: txt data(int 0~255)
    n c h w
    val val ...
    */
    int num = n*c*h*w;

    ifstream in("bin/" + name + ".bin", ios::binary);
    float *pos = new float[num];
    in.read((char* )pos, num * sizeof(float));
    in.close();

    float tmp, max = 0;
    for (int i = 0; i < num; ++i)
    {
        tmp = pos[i];
        if (tmp > max) max = tmp;
    }
    if (max > 1)
    {
        printf("input format: int or float 0~255\n");
    }
    else
    {
        printf("input format: float 0~1\n");
        for (int i = 0; i < num; ++i)
        {
            pos[i] *= 255;
        }
    }
    
    ofstream out("txt/" + name + ".txt");
    cout << "write " << name << ".txt" << endl;
    out << n << " " << c << " " << h << " " << w << endl;
    for (int i = 0; i < num; ++i)
    {
        out << round(pos[i]) << " ";
    }
    out.close();
}

void read_bin(const string& name, const int& end, const int& start = 0)
{   /*
    input: bin data(float)
    output: float val from start(default 0) to end(not included)
    */
    float *pos = new float[end];

    ifstream f("bin/" + name + ".bin", ios::binary);
    f.read((char* )pos, end * sizeof(float));
    for(int i = start; i < end; ++i)
    {
        cout << pos[i] <<endl;
    }
    f.close();

    delete[] pos;
}

void bin2txt_folder(const int& n, const int& c, const int& h, const int& w)
{
    for (int i = 1; i <=10; ++i)
    {
        bin2txt(to_string(i), n, c, h, w);
    }
}

int main()
{
    bin2txt_folder(1, 3, 248, 248);
}
