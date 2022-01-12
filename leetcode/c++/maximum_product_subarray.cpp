#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;


class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
	{
        int product_max = nums[0];
        int cur_max = nums[0];
        int cur_min = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(cur_max, cur_min);
            }
            cur_max = max(cur_max * nums[i], nums[i]);
            cur_min = min(cur_min * nums[i], nums[i]);
            if (cur_max > product_max)
            {
                product_max = cur_max;
            }
        }
        return product_max;
    }
};

int main()
{
    vector<int> nums = {2, 3, -1, 4};
    Solution s;
    int result = s.maxProduct(nums);
    cout << result << endl;
	return 0;
}
