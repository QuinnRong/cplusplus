#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        if (len == 1) return strs[0];
        string s0 = strs[0];
        for (int idx = 0; idx < s0.size(); ++idx)
        {
            char c = s0[idx];
            for (int i = 1; i < len; ++i)
            {
                if (idx == strs[i].size() || strs[i][idx] != c)
                {
                    return s0.substr(0, idx);
                }
            }
        }
        return s0;
    }

    string longestCommonPrefix0(vector<string>& strs) {
        if (strs.empty())
            return "";
        string s0 = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            int idx;
            for (idx = 0; idx < s0.size(); ++idx)
            {
                if (strs[i][idx] != s0[idx])
                {
                    break;
                }
            }
            if (idx == 0)
                return "";
            if (idx < s0.size())
                s0 = s0.substr(0, idx);
        }
        return s0;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(strs) << " " << sol.longestCommonPrefix0(strs) << endl;
}