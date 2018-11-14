#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int prev = result;
        while (x != 0)
        {
            prev = result;
            result *= 10;
            if (result / 10 != prev)
                return 0;
            result += x % 10;
            x /= 10;
        }
        return result;
    }
    int reverse0(int x) {
        int result = 0;
        int k = INT_MIN / 10;
        int m = INT_MAX / 10;
        while (x != 0)
        {
            if (result < k || result > m)
                return 0;
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int x = 1463847412; // INT_MAX + 1 = 2147483648
    std::cout << x << std::endl;
    std::cout << sol.reverse(x) << std::endl;
    std::cout << sol.reverse0(x) << std::endl;
}