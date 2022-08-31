#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> max_sliding_nums;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!q.empty() && q.front() == i - k)
            {
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1)
            {
                max_sliding_nums.push_back(nums[q.front()]);
            }
        }
        return max_sliding_nums;
    }
};

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution s;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for(int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
