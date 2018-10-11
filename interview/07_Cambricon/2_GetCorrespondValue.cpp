#include <cstdio>
#include <iostream>

using namespace std;

long long getVal(long long t)
{
	long long len = 3;

	while (t > len)
	{
		t -= len;
		len *= 2;
	}

	return len - t + 1;
}

int main()
{
    freopen("2.txt", "r", stdin);
    long long t;
    cin >> t;
    // cout << t << endl;

    cout << getVal(t) << endl;

    fclose(stdin);
    return 0;
}