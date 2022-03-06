#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target, int p, int q)
    {
        if (p > q)
        {
            return -1;
        }

        int mid = (p + q) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[p] <= nums[mid])
        {
            if(target >= nums[p] && target < nums[mid])
            {
                return search(nums, target, p, mid - 1);
            }
            else
            {
                return search(nums, target, mid + 1, q);
            }
        }
        else
        {
            if(target > nums[mid] && target <= nums[q])
            {
                return search(nums, target, mid + 1, q);
            }
            else
            {
                return search(nums, target, p, mid - 1);
            }
        }
    }

    int search(vector<int>& nums, int target)
	{
        return search(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
	int target = 0;
	Solution s;
    bool res = s.search(nums, target);
    if (res)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
	return 0;
}
