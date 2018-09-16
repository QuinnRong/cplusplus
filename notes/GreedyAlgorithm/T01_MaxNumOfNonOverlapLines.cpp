#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct line
{
	int start;
	int end;
};

bool cmp(line a, line b)
{
	return (a.end < b.end);
}

int MaxNumOfNonOverlapLines(vector<line>& lineVector)
{
	sort(lineVector.begin(), lineVector.end(), cmp);
	int res = 0;
	int curr = 0x80000000;
	for (auto item : lineVector)
	{
		if (item.start >= curr)
		{
			++res;
			curr = item.end;
		}
	}
	return res;
}

int main()
{
	ifstream ifs("1.txt");
	int N;
	ifs >> N;
	vector<line> lineVector;
	for (int i = 0; i < N; ++i)
	{
		line tmp;
		ifs >> tmp.start >> tmp.end;
		if (tmp.start > tmp.end)
		{
			int val = tmp.start;
			tmp.start = tmp.end;
			tmp.end = val;
		}
		lineVector.push_back(tmp);
	}
	ifs.close();

	// for (auto item : lineVector)
	// 	cout << item.start << " " << item.end << endl;
	// cout << endl;

	cout << MaxNumOfNonOverlapLines(lineVector) << endl;
}