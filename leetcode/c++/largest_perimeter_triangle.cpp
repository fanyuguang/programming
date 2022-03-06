#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int max = 0;
        for (int i = nums.size() - 1; i > 1; i--)
        {
            if (nums[i] < nums[i - 1] + nums[i - 2])
            {
                max = nums[i] + nums[i - 1] + nums[i - 2];
                break;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> nums = {2, 1, 2, 4, 5};
    Solution s;
    int result = s.largestPerimeter(nums);
    cout << result << endl;
    return 0;
}
