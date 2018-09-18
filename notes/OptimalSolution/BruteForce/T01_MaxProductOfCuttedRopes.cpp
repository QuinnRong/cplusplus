#include <iostream>
#include <iomanip>

using namespace std;

void ProductCore(int pos, bool cut, int before, bool cuted, int product, int& len, int& maxProduct)
{
	if (pos == len)
	{
		if (cuted)
		{
			product *= (pos - before);
			if (product > maxProduct) maxProduct = product;
		}
		return;
	}
	cuted |= cut;
	if (cut)
	{
		product *= (pos - before);
		before = pos;
	}
	ProductCore(pos + 1, true, before, cuted, product, len, maxProduct);
	ProductCore(pos + 1, false, before, cuted, product, len, maxProduct);
}

int MaxProductOfCuttedRopes(int length)
{
	if (length < 2) return 0;
	int maxProduct = 1;
	int before = 0;
	ProductCore(1, true, before, false, 1, length, maxProduct);
	before = 0;
	ProductCore(1, false, before, false, 1, length, maxProduct);
	return maxProduct;
}

int main()
{
	for (int length = 0; length <= 10; ++length)
		cout << setw(2) << length << ": "
		<< MaxProductOfCuttedRopes(length) << endl;
}

/*
time: O(2^n)
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