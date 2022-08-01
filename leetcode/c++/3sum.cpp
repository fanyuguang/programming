#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        quick_sort(nums, 0, nums.size() - 1);
        unordered_map<int, vector<int>> num_map;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (num_map.find(nums[i]) == num_map.end())
            {
                vector<int> indexes;
                num_map[nums[i]] = indexes;
            }
            num_map[nums[i]].push_back(i);
        }

        vector<vector<int>> three_sum_result;
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0;)
        {
            for (int j = i + 1; j < nums.size() - 1;)
            {
                int rest = 0 - nums[i] - nums[j];
                if (num_map.find(rest) != num_map.end() && num_map[rest][0] > j)
                {
                    vector<int> cur_three_sum = {nums[i], nums[j], rest};
                    three_sum_result.push_back(cur_three_sum);
                }

                int j_tmp = j;
                while(nums[j] == nums[j_tmp] && j < nums.size() - 1) 
                {
                    j++;
                }
            }

            int i_tmp = i;
            while(nums[i] == nums[i_tmp] && i < nums.size() - 1) 
            {
                i++;
            }
        }
        return three_sum_result;
    }

private:
    int partition(vector<int>& nums, int p, int q)
    {
        int j = p - 1;
        for (int i = p; i <= q; i++)
        {
            if (nums[i] <= nums[q])
            {
                int temp = nums[++j];
                nums[j] = nums[i];
                nums[i] = temp;
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
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

