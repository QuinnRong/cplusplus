#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	freopen("3.txt", "r", stdin);
	int a, b, c;
	cin >> a >> b >> c;

	int tmp;
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b > c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	
	printf("[%d, %d, %d]\n", a, b, c);

	fclose(stdin);
	return 0;
}