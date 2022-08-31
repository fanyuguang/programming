#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        return quick_sort(nums, 0, nums.size() - 1, k);
    }

private:
    int partition(vector<int>& nums, int p, int q)
    {
        int i = p - 1;
        for (int j = p; j <= q; ++j)
        {
            if (nums[j] <= nums[q])
            {
                int temp = nums[++i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        return i;
    }

    int quick_sort(vector<int>& nums, int p, int q, int k)
    {
        if (p < q)
        {
            int r = partition(nums, p, q);
            if (nums.size() - r == k)
            {
                return nums[r];
            }
            else if (nums.size() - r < k)
            {
                return quick_sort(nums, p, r - 1, k);
            }
            else
            {
                return quick_sort(nums, r + 1, q, k);
            }
        }
        else
        {
            return nums[p];
        }
    }
};

int main()
{
    // vector<int> nums = {3, 2, 1, 5, 6, 4};
    // int k = 2;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    Solution s;
    int result = s.findKthLargest(nums, k);
    cout << result << endl;
    return 0;
}
