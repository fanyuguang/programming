#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if (sum % 2 != 0)
        {
            return false;
        }

        int target = sum >> 1;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : nums)
        {
            for (int i = target; i >= num; --i)
            {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};

int main()
{
    // vector<int> nums = {1, 5, 11, 5};
    // vector<int> nums = {1, 2, 3, 5};
    vector<int> nums = {100, 100, 100, 100, 100, 100, 100, 100};

    Solution s;
    bool result = s.canPartition(nums);
    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
