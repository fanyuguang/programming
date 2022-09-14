#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int binary_search(int left, int right, function<bool(int)> func)
    {
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if (func(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    int findNumberOfLIS(vector<int>& nums)
    {
        vector<vector<int>> mins;
        vector<vector<int>> cusum;
        for (int num : nums)
        {
            int i = binary_search(0, mins.size(), [&](int mid) -> bool { return mins[mid].back() >= num; });  // find the first element that >= num in increaseing seq mins[0 ~ n].back()
            int pre_cusum = 1;
            if (i > 0)
            {
                int j = binary_search(0, mins[i - 1].size(), [&](int mid) -> bool { return mins[i - 1][mid] < num; });  // find the first element < num in decreasing seq mins[i - 1][0 ~ n]
                pre_cusum = cusum[i - 1].back();
                if (j > 0)
                {
                    pre_cusum -= cusum[i - 1][j - 1];
                }
            }
            
            if (i >= mins.size())
            {
                mins.push_back({num});
                cusum.push_back({pre_cusum});
            }
            else
            {
                mins[i].push_back(num);
                cusum[i].push_back(pre_cusum + cusum[i].back());
            }
        }
        return cusum.back().back();
    }
};

int main()
{
    // vector<int> nums = {1, 3, 5, 4, 7};
    vector<int> nums = {1, 2, 4, 3, 5, 4, 7, 2};
    Solution s;
    int result = s.findNumberOfLIS(nums);
    cout << result << endl;
    return 0;
}
