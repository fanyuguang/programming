#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int search_start(vector<int>& nums, int target, int p, int q)
    {
        if (p > q)
        {
            return -1;
        }
        else if (p == q)
        {
            if (nums[p] == target)
            {
                return p;
            }
            else
            {
                return -1;
            }
        }

        int mid = (p + q) / 2;
        if (nums[mid] >= target)
        {
            return search_start(nums, target, p, mid);
        }
        else
        {
            return search_start(nums, target, mid + 1, q);
        }
    }

    int search_end(vector<int>& nums, int target, int p, int q)
    {
        if (p > q)
        {
            return -1;
        }
        else if (p == q)
        {
            if (nums[p] == target)
            {
                return p;
            }
            else
            {
                return -1;
            }
        }

        int mid = ceil((p + q) / (2 * 1.0));
        if (nums[mid] <= target)
        {
            return search_end(nums, target, mid, q);
        }
        else
        {
            return search_end(nums, target, p, mid - 1);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty() || nums[0] > target || nums.back() < target)
        {
            return vector<int>({-1, -1});
        }
        int start = search_start(nums, target, 0, nums.size() - 1);
        int end = search_end(nums, target, 0, nums.size() - 1);
        return vector<int>({start, end});
    }
};

int main()
{
    // vector<int> nums = {5, 7, 7, 8, 8, 10};
    // int target = 8;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 6;

    Solution s;
    vector<int> result = s.searchRange(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
