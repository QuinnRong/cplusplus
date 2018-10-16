#include <iostream>
#include <cstdio>
#include <vector>		/* vector */
#include <algorithm>	/* sort */
#include <cstdlib>		/* rand, srand */
#include <ctime>		/* time */

using namespace std;

/*
PERMUTE-BY-SORTING(A)
n = A.length
let P[1..n] be a new array
for i = 1 to n
	P[i] = RANDOM(1, n^3)
sort A, using P as sort keys
*/

bool cmp_by_prior(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return p1.second < p2.second;
}

void PermuteBySorting(int* arr, int n)
{
	srand(time(NULL));
	vector<pair<int, int>> elem_prior_vec;

	for (int i = 0; i < n; ++i)
	{
		elem_prior_vec.push_back(make_pair(arr[i], rand()));
	}

	sort(elem_prior_vec.begin(), elem_prior_vec.end(), cmp_by_prior);

	for (int i = 0; i < n; ++i)
	{
		arr[i] = elem_prior_vec[i].first;
	}
}

/*
RANDOMIZE-IN-PLACE(A)
n = A.length
for i = 1 to n
	swap A[i] with A[RANDOM(i, n)]
*/

int rand_range(int a, int b)
{
    return a + rand() % (b - a + 1);
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void RandomizeInPlace(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		swap(arr[i], arr[rand_range(i, n)]);
	}
}

int main()
{
	freopen("03.txt", "r", stdin);
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	PermuteBySorting(arr, n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;

	RandomizeInPlace(arr, n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;

	delete[] arr;
	fclose(stdin);
	return 0;
}
