#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int partition(vector<int>& nums, int p, int r)
    {
        int i = p - 1;
        for (int j = p; j <= r; j++)
        {
            if (nums[j] <= nums[r])
            {
                int temp = nums[++i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        return i;
    }

    void quick_sort(vector<int>& nums, int p, int r)
    {
        if (p < r)
        {
            int q = partition(nums, p, r);
            quick_sort(nums, p, q - 1);
            quick_sort(nums, q + 1, r);
        }
    }

    int triangleNumber(vector<int>& nums)
    {
        quick_sort(nums, 0, nums.size() - 1);
        int tri_num = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int l = 0;
            int r = i - 1;
            while(l < r)
            {
                if (nums[l] + nums[r] > nums[i])
                {
                    tri_num += r - l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return tri_num;
    }
};

int main()
{
    vector<int> nums = {5, 2, 2, 3, 4};
    Solution s;
    int result = s.triangleNumber(nums);
    cout << result << endl;
    return 0;
}
