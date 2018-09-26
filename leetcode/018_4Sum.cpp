#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{   /*
    input:
        nums: unordered
    output:
        unique quadruplets that give the sum of zero (must not contain duplicate quadruplets)
    time: O(n^3)
    */
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
        
    if (nums.size() < 4) return res;
    
    for (int j = 0; j < nums.size() - 3;)
    {
        for (int i = j + 1; i < nums.size() - 2;)
        {
            int target2 = target - nums[i] - nums[j];
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end)
            {
                int sum = nums[start] + nums[end];
                if (sum == target2)
                {
                    res.push_back({nums[j], nums[i], nums[start], nums[end]});
                    while (nums[start] == nums[++start]);
                    while (nums[end] == nums[--end]);
                }
                else if (sum < target2)
                    while (nums[start] == nums[++start]);
                else
                    while (nums[end] == nums[--end]);
            }
            while (nums[i] == nums[++i]);
        }
        while (nums[j] == nums[++j]);
    }
    
    return res;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = fourSum(nums, 3);
    for (auto item : res)
    {
        for (auto val : item)
            cout << val << " ";
        cout << endl;
    }
}

/*
result:
-2 -1 1 2
-2 0 0 2
-1 0 0 1
*/