#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int remove_star(string& str)
{
    int len = str.size();
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '*')
        {
            str = str.substr(0, i);
        }
    }
    return len - str.size();
}

void remove_col(string& str)
{
    int len = str.size();
    for (int i = len - 1; i > 0; --i)
    {
        if (str[i] == ';')
        {
            str = str.substr(0, i);
        }
    }
}

int main()
{
    map<string, string> tpye_map;

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    stringstream ss(line1);

    string def, src, dst;
    bool valid = true;
    while (ss >> def >> src >> dst)
    {
        if (def != "typedef")
        {
            valid = false;
            break;
        }
        if (dst[dst.size() - 1] != ';')
        {
            valid = false;
            break;
        }
        remove_col(dst);
        int num_star = remove_star(src);
        if (num_star > 0 && tpye_map[src] != "")
        {
            src = tpye_map[src];
        }
        for (int i = 0; i < num_star; ++i)
        {
            src += " *";
        }
        tpye_map[dst] = src;
    }
    // for (auto p : tpye_map)
    // {
    //  cout << p.first << "->" << p.second << endl;
    // }
    if (valid && tpye_map[line2] != "")
    {
        cout << tpye_map[line2] << endl;
    }
    else
    {
        cout << "none" << endl;
    }
}