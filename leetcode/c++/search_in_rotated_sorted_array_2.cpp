#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int>& nums, int target)
	{
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[mid] < nums[right])
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else if (nums[mid] > nums[right])
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                right--;
            }
        }
        return false;
    }
};

int main()
{
	// vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
	// int target = 3;
	// vector<int> nums = {1, 0, 1, 1, 1};
	// int target = 0;
	vector<int> nums = {3, 1};
	int target = 1;
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
