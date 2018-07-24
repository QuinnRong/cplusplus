#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void cos_distance(const string& file1, const string& file2)
{   /*
    format:
    [0,0,0] -134.75
    [1,0,0] -79.75
    */
    string str1, str2;
    float val1, val2;
    float norm1 = 0, norm2 = 0, product = 0;

    int num = 0;
    ifstream in1("data/" + file1);
    ifstream in2("data/" + file2);
    while(in1 >> str1 >> str1 && in2 >> str2 >> str2)
    {
        val1 = atof(str1.c_str());
        norm1 += val1 * val1;
        val2 = atof(str2.c_str());
        norm2 += val2 * val2;
        product += val1 * val2;
        num += 1;
    }
    in1.close();
    in2.close();

    norm1 = sqrt(norm1);
    norm2 = sqrt(norm2);
    cout << "dim=" << num << endl;
    cout << "norm1=" << norm1 << ", norm2=" << norm2 << endl;
    cout << "cos_distance=" << product / norm1 / norm2 << endl;
}

int main()
{
    cout << "\ndifference between NCS and tf:\n";
    cos_distance("output_1_NCS.txt", "output_1.txt");

    cout << "\ndifference between NCS and M2:\n";
    cos_distance("output_1_NCS.txt", "output_1_blob.txt");

    cout << "\ndifference between tf and M2:\n";
    cos_distance("output_1.txt", "output_1_blob.txt");
}