#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

double CalEntropy(int a, int b)
{	/*
	input:
		two frequencies
	output:
		entropy
	*/
	double entropy, p;
	if (a == 0 || b == 0)
	{
		entropy = 0;
	}
	else
	{
		p = a * 1.0 / (a + b);
		entropy = - p * log2(p) - (1 - p) * log2(1 - p);
	}
	return entropy;
}

double InformationGain(unordered_map<int, pair<int, int>>& data, int sum0, int sum1)
{   /*
    input:
        map: key, <frequency0, frequency1>
        sum0: sum of frequency0
        sum1: sum of frequency1
    output:
        IG = Entropy<sum0, sum1> - sum(Entropy<frequency0, frequency1>)
    */
	double initEntropy = CalEntropy(sum0, sum1);

	double currEntropy = 0;
	for (auto item : data)
		currEntropy += CalEntropy(item.second.first, item.second.second);

	return initEntropy - currEntropy;
}

int main()
{
	unordered_map<int, pair<int, int>> data;

	freopen("2.txt", "r", stdin);
	int n;
	cin >> n;

	int key, flag;
	string str;
	int sum0 = 0, sum1 = 0;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, str, ',');
		key = stoi(str);
		cin >> flag;
		if (data.find(key) == data.end())
		{
			data[key].first = 0;
			data[key].second = 0;
		}
		if (flag == 0)
		{
			++data[key].first;
			++sum0;
		}
		else if (flag == 1)
		{
			++data[key].second;
			++sum1;
		}
		else
		{
			cout << "Invalid flag!" << endl;
			break;
		}
	}

	// for (auto item : data)
	// {
	// 	cout << item.first << ": " << item.second.first << " " << item.second.second << endl;
	// }

	double res = InformationGain(data, sum0, sum1);
	
	// 四折五入保留两位小数输出
	int ans = (res + 0.005) * 100;
	res = ans / 100.0;
	printf("%.2f\n", res);

	fclose(stdin);
	return 0;
}