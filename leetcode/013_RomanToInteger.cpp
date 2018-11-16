#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        if (len == 0)
            return 0;

        int hash[26];
        hash['I' - 'A'] = 1;
        hash['V' - 'A'] = 5;
        hash['X' - 'A'] = 10;
        hash['L' - 'A'] = 50;
        hash['C' - 'A'] = 100;
        hash['D' - 'A'] = 500;
        hash['M' - 'A'] = 1000;

        int res = 0;
        int curr, next;
        for (int i = 0; i < len - 1; ++i)
        {
            curr = hash[s[i] - 'A'];
            next = hash[s[i + 1] - 'A'];
            res += ((curr < next) ? -curr : curr);
        }
        res += hash[s[len - 1] - 'A'];
        
        return res;
    }

    int charToNum(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:
                break;
        }
        return 0;
    }
    int romanToInt0(string s) {
        int res = 0;
        int curr, next;
        int i, len = s.size();
        for (i = 0; i < len - 1; ++i)
        {
            curr = charToNum(s[i]);
            next = charToNum(s[i + 1]);
            if (curr < next)
            {
                res = res - curr + next;
                ++i;
            }
            else
            {
                res += curr;
            }
        }
        if (i == len - 1)
            res += charToNum(s[i]);
        return res;
    }
};

int main()
{
    Solution sol;
    string arr[] = {"III", "IV", "IX", "LVIII", "MCMXCIV", ""};
    for (auto s : arr)
    {
        cout << s << " -> " << sol.romanToInt(s) << " " << sol.romanToInt0(s) << endl;
    }
}