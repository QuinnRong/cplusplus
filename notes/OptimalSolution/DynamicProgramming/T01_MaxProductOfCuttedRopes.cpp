#include <iostream>
#include <iomanip>

using namespace std;

int MaxProductOfCuttedRopes(int length)
{
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;

	int* res = new int[length + 1];
	for (int i = 0; i <= length; ++i)
	{
		res[i] = i;
		for (int j = 1; j < i; ++j)
		{
			if (j * res[i - j] > res[i])
				res[i] = j * res[i - j];
		}
	}
	delete[] res;
	return res[length];
}

int main()
{
	for (int length = 0; length <= 10; ++length)
		cout << setw(2) << length << ": "
		<< MaxProductOfCuttedRopes(length) << endl;
}

/*
time: O(n^2)
space: O(n)
results:
 0: 0
 1: 0
 2: 1
 3: 2
 4: 4
 5: 6
 6: 9
 7: 12
 8: 18
 9: 27
10: 36
*/