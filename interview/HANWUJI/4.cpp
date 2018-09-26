#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int gmin = -1;

int distance(vector<int>& intVector1, vector<int>& intVector2)
{
	int sum = 0;
	for (int i = 0; i < intVector1.size(); ++i)
	{
		for (int j = 0; j < intVector2.size(); ++j)
			sum += abs(intVector1[i] - intVector2[j]);
	}
	return sum;
}

void CombinationCore(int* arr, int len, int curr, int k, vector<int>& intVector1, vector<int>& intVector2)
{
	if (intVector1.size() == k)
	{
		// for (const auto& i : intVector1) printf("%d ", i);
		// printf("\n\n");
		// for (const auto& i : intVector2) printf("%d ", i);
		for (int i = curr; i < len; ++i)
		{
			intVector2.push_back(arr[i]);
			// printf("%d ", arr[i]);
		}
		// printf("\n\n");
		int dis = distance(intVector1, intVector2);
		if (gmin < 0 || dis < gmin) gmin = dis;
		return;
	}
	if (curr >= len) return;

	intVector1.push_back(arr[curr]);
	CombinationCore(arr, len, curr + 1, k, intVector1, intVector2);
	intVector1.pop_back();
	intVector2.push_back(arr[curr]);
	CombinationCore(arr, len, curr + 1, k, intVector1, intVector2);
	intVector2.pop_back();
}

void Combination(int* arr, int n, int k)
{
	if (arr == nullptr) return;
	vector<int> intVector1, intVector2;
	CombinationCore(arr, n, 0, k, intVector1, intVector2);
}

int main()
{
	freopen("4.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i)
    	cin >> arr[i];

	Combination(arr, n, k);

	cout << gmin << endl;

    delete[] arr;
    fclose(stdin);
    return 0;
}