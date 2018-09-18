#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const string &str1, const string str2)
{	/*
	input: 121 12
	output: true (12112 < 12121)
	*/
	string tmp1 = str1 + str2;
	string tmp2 = str2 + str1;
	return (tmp1 < tmp2);
}

void PrintMinNumber(int* numbers, int length)
{	/*
	concate the numbers to get minimum total value
	*/
	if (numbers == nullptr || length <= 0) return;

	vector<string> strVec;
	for (int i = 0; i < length; ++i)
		strVec.push_back(to_string(numbers[i]));

	sort(strVec.begin(), strVec.end(), compare);

	for (auto item : strVec)
		cout << item;
	cout << endl;
}

int main()
{
	int arr[3] = {3, 324, 321};
	PrintMinNumber(arr, 3);
}

/*
result: 3213243
*/