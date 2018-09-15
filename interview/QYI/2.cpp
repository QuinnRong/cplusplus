#include <iostream>
#include <vector>

using namespace std;

bool overlap(vector<vector<int>>& data, int idx, vector<bool>& flag)
{
	if (!flag[idx]) return false;

	for (int i = 0; i < idx; ++i)
		if (flag[i] && !(data[idx][0] >= data[i][1] || data[idx][1] <= data[i][0]))
				return true;

	return false;
}

void FindMaxNumCore(vector<vector<int>>& data, int idx, vector<bool>& flag, int& sum, int& max, bool choose)
{
	if (idx >= data.size()) return;

	flag.push_back(choose);
	if (choose) sum += 1;

	if (!overlap(data, idx, flag))
	{
		if (idx == data.size() - 1 && sum > max) 
		{
			max = sum;
		}
		FindMaxNumCore(data, idx + 1, flag, sum, max, true);
		FindMaxNumCore(data, idx + 1, flag, sum, max, false);
	}

	if (idx == data.size() - 1)
	{
		cout << (overlap(data, idx, flag) ? "[0]" : "[1]");
		for (auto i : flag)
			cout << "-" << i;
		printf("    sum = %d, max = %d\n\n", sum, max);
	}

	flag.pop_back();
	if (choose) sum -= 1;
}

int FindMaxNum(vector<vector<int>>& data)
{
	int sum = 0;
	vector<bool> flag;
	int max = 0;
	FindMaxNumCore(data, 0, flag, sum, max, true);
	FindMaxNumCore(data, 0, flag, sum, max, false);
	return max;
}

int main(){
    freopen("2.in","r",stdin);
	int N;
	cin >> N;
	vector<vector<int>> data;

	int left, right;
	for (int i = 0; i < N; ++i)
	{
		cin >> left >> right;
		vector<int> pair;
		if (left > right)
		{
			pair.push_back(right);
			pair.push_back(left);
		}
		else
		{
			pair.push_back(left);
			pair.push_back(right);
		}
		data.push_back(pair);
	}

	int res = FindMaxNum(data);
	cout << res << endl;

    return 0;
}