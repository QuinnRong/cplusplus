#include <cstdio>
#include <iostream>

using namespace std;

int GetNumOfDays(int year, int month, int day)
{
    bool run = false;   // leap year or not
    if (year % 400 == 0)
    {
        run = true;
    }
    else if ((year % 100) != 0 && (year % 4) == 0)
    {
        run = true;
    }

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int res = 0;
    for (int i = 0; i < month - 1; ++i)
    {
        res += days[i];
    }
    res += day;
    if (run) res += 1;  // if leap year
    return res;
}

int main()
{
    freopen("4.txt", "r", stdin);
    int year, month, day;
    cin >> year >> month >> day;

    int num = GetNumOfDays(year, month, day);
    
    printf("%d\n", num);

    fclose(stdin);
    return 0;
}