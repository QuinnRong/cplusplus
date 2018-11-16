#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        int ini = x;
        if (x < 0)
            return false;
        int rev = 0;
        while (x > 0)
        {
            rev *=10;
            rev += x % 10;
            x /= 10;
        }
        if (rev == ini)
            return true;
        return false;
    }
    bool isPalindrome0(int x) {
        if (x == 0)
            return true;
        if (x < 0 || x % 10 == 0)
            return false;
        int rev = 0;
        while (rev < x)     // 只需循环到一半
        {
            rev *= 10;
            rev += x % 10;
            x /= 10;
        }
        return (rev == x || rev / 10 == x);
    }
};

int main()
{
    Solution sol;
    int arr[] = {121, 1221, 12321, 10, 0};
    for (auto x : arr)
    {
        std::cout << x << ": ";
        std::cout << sol.isPalindrome(x) << " " << sol.isPalindrome0(x) << std::endl;
    }
}