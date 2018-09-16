#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int MaxProductOfCuttedRopes(int length)
{
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;

	int timesOf3 = length / 3;
	int timesOf2 = 0;
	if (length % 3)
	{
		--timesOf3;
		timesOf2 = 2;
	}
	return int(pow(3, timesOf3) * pow(2, timesOf2));
}

int main()
{
	for (int length = 0; length <= 10; ++length)
		cout << setw(2) << length << ": "
		<< MaxProductOfCuttedRopes(length) << endl;
}

/*
results:
 0: 0
 1: 0
 2: 1
 3: 2
 4: 4
 5: 4
 6: 9
 7: 12
 8: 12
 9: 27
10: 36
*/