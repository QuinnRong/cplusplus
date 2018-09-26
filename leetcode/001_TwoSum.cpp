#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{	/*
	input:
		nums: unordered
		target: sum of two numbers
	output:
		vector of the indices
	time: O(n)
	*/
    vector<int> res = {};
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i)
    {
        int remain = target - nums[i];
        if (hash.find(remain) != hash.end())
        {
            res.push_back(hash[remain]);
            res.push_back(i);
            return res;
        }
        else
        {
            hash.insert({nums[i], i});
        }
    }
    throw runtime_error("No two sum solution");
}

int main()
{
	vector<int> nums = {3, 2, 4};
	int target = 6;

	vector<int> res = twoSum(nums, target);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
}

/*
result: 1 2
(nums[1] + nums[2] == target)
*/