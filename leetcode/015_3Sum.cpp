#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{	/*
	input:
		nums: unordered
	output:
		unique triplets that give the sum of zero (must not contain duplicate triplets)
	time: O(n^2)
	*/
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    for (int i = 0; i < nums.size();)
    {
        int target = -nums[i];
        int start = i + 1;
        int end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] + nums[end] == target)
            {
                res.push_back({nums[i], nums[start], nums[end]});
                while (nums[start] == nums[++start]);
                while (nums[end] == nums[--end]);
            }
            else if (nums[start] + nums[end] < target)
                while (nums[start] == nums[++start]);
            else
                while (nums[end] == nums[--end]);
        }
        while (nums[i] == nums[++i]);
    }
    
    return res;
}

int main()
{
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> res = threeSum(nums);
	for (auto item : res)
	{
		for (auto val : item)
			cout << val << " ";
		cout << endl;
	}
}

/*
result:
-1 -1 2
-1 0 1
*/