#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <cstring>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
bool isSubStr(string S, string T, int start, bool* isTaken_0, char* map_0) {
	bool isTaken[26];
	memcpy(isTaken, isTaken_0, sizeof(bool) * 26);
	char map[26];
	memcpy(map, map_0, sizeof(char) * 26);

	for (int i = 0; i < T.size(); ++i) {
		if (!isTaken[S[start + i] - 'a'] && map[T[i] - 'a'] == 0) {
			map[T[i] - 'a'] = S[start + i];
			isTaken[S[start + i] - 'a'] = true;
		}
		else if (S[start + i] != map[T[i] - 'a']) {
			return false;
		}
	}

	memcpy(isTaken_0, isTaken, sizeof(bool) * 26);
	memcpy(map_0, map, sizeof(char) * 26);

	return true;
}

int solve(string S, string T) {
	int diff = S.size() - T.size();
	if (diff < 0) return 0;

	bool isTaken[26];
	memset(isTaken, false, sizeof(bool) * 26);
	char map[26];
	memset(map, 0, sizeof(char) * 26);

	int res = 0;
	for (int i = 0; i <= diff; ++i) {
		if (isSubStr(S, T, i, isTaken, map)) ++res;
	}
	return res;
}
/******************************结束写代码******************************/


int main() {
    int res;

    string _S;
    getline(cin, _S);
    string _T;
    getline(cin, _T);
    
    res = solve(_S, _T);
    cout << res << endl;
    
    return 0;

}