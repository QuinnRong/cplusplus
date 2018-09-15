#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("1.in","r",stdin);
	int N, M, P;
	cin >> N >> M >> P;
	vector<int> data;

	int num;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		data.push_back(num);
	}

	// for (auto i : data)
	// 	cout << i << " ";
	// cout << endl;

	char str;
	int idx;
	for (int i = 0; i < M; ++i)
	{
		cin >> str >> idx;
		if (str == 'A') ++data[idx - 1];
		if (str == 'B') --data[idx - 1];
	}

	// for (auto i : data)
	// 	cout << i << " ";
	// cout << endl;

	int val = data[P - 1];
	int rank = 1;

	for (auto i : data)
	{
		if (i > val) ++rank;
	}

	cout << rank << endl;

    return 0;
}