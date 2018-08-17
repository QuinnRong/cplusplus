#include <iostream>
#include <typeinfo>

using namespace std;

template<typename Dtype>
void printType(Dtype& input)
{
    if (typeid(input) == typeid(int))
    {
        cout << "int" << endl;
    }
    else if (typeid(input) == typeid(float))
    {
        cout << "float" << endl;
    }
    
}

int main()
{
    int x;
    printType(x);
    float y;
    printType(y);
}