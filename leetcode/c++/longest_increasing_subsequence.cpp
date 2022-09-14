#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> mins;
        for (int num : nums)
        {
            if (mins.empty() || num > mins[mins.size() - 1])
            {
                mins.push_back(num);
                continue;
            }

            int left = 0;
            int right = mins.size() - 1;
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                if (mins[mid] < num)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            mins[right] = num;
        }
        return mins.size();
    }
};


int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    int result = s.lengthOfLIS(nums);
    cout << result << endl;
    return 0;
}
