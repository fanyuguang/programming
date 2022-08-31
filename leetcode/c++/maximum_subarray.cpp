#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide_subarray(nums, 0, nums.size() - 1);
    }

    int maxSubArray2(vector<int>& nums) {
        int max_sum = nums[0];
        int pre_max = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (pre_max < 0)
            {
                pre_max = nums[i];
            }
            else
            {
                pre_max += nums[i];
            }
            if (pre_max > max_sum)
            {
                max_sum = pre_max;
            }
        }
        return max_sum;
    }


private:
    int divide_subarray(vector<int>& nums, int first, int last)
    {
        if (first >= last)
            return nums[first];
        int mid = (first + last) / 2;
        int lmax = divide_subarray(nums, first, mid);
        int rmax = divide_subarray(nums, mid + 1, last);
        int pre_midmax = nums[mid];
        int left_temp = nums[mid];
        for (int i = mid - 1; i >= first; i--)
        {
            left_temp += nums[i];
            if (left_temp > pre_midmax)
                pre_midmax = left_temp;
        }
        int next_midmax = nums[mid + 1];
        int right_temp = nums[mid + 1];
        for (int j = mid + 2; j <= last; j++)
        {
            right_temp += nums[j];
            if (right_temp > next_midmax)
                next_midmax = right_temp;
        }
        int temp_max = lmax > rmax ? lmax : rmax;
        int max = temp_max > pre_midmax + next_midmax ? temp_max : pre_midmax + next_midmax;
        return max;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    int result = s.maxSubArray2(nums);
    cout << result << endl;
    return 0;
}
