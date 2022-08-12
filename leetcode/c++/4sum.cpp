#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        quick_sort(nums, 0, nums.size() - 1);
        int nums_size = nums.size();
        for (int i = 0; i < nums_size - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums_size - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = nums_size - 1;
                while(left < right)
                {
                    long cur_sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (cur_sum == target)
                    {
                        vector<int> cur_res = {nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(cur_res);
                        while(left < right && nums[left + 1] == nums[left])
                        {
                            left++;
                        }
                        while(left < right && nums[right - 1] == nums[right])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if (cur_sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return res;
    }

private:
    int partition(vector<int>& nums, int p, int q)
    {
        int j = p - 1;
        for (int i = p; i <= q; i++)
        {
            if (nums[i] <= nums[q])
            {
                int temp = nums[i];
                nums[i] = nums[++j];
                nums[j] = temp;
            }
        }
        return j;
    }

    void quick_sort(vector<int>& nums, int p, int q)
    {
        if (p < q)
        {
            int r = partition(nums, p, q);
            quick_sort(nums, p, r - 1);
            quick_sort(nums, r + 1, q);
        }
    }
};

int main()
{
    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    // int target = 0;
    // vector<int> nums = {2, 2, 2, 2, 2};
    // int target = 8;
    vector<int> nums = {0};
    int target = 0;

    Solution s;
    vector<vector<int>> result = s.fourSum(nums, target);
    for (auto items : result)
    {
        for (int item : items)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}
