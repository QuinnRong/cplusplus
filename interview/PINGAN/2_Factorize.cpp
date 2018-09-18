#include <cstdio>
#include <iostream>

using namespace std;

void Factorize(int x)
{   /*
    input: 10
    output: 2*5
    */
    for (int i = 2; i < x; ++i)
    {
        while (x % i == 0 && x != i)
        {
            x /= i;
            cout << i << '*';
        }
    }
    cout << x << endl;
}

int main()
{
    freopen("2.txt", "r", stdin);

    int x;
    cin >> x;

    Factorize(x);

    fclose(stdin);

    return 0;
}