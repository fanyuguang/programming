#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int desc_order_index = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                desc_order_index = i;
                break;
            }
        }
        cout << "desc_order_index: " << desc_order_index << endl;

        int first = desc_order_index + 1;
        int last = nums.size() - 1;
        while(first <= last)
        {
            int tmp = nums[first];
            nums[first] = nums[last];
            nums[last] = tmp;
            first++;
            last--;
        }

        if (desc_order_index != -1)
        {
            int index = nums.size() - 1;
            int min = nums[index];
            while (index > desc_order_index && nums[index] > nums[desc_order_index] && nums[index] <= min)
            {
                index--;
                min = nums[index];
                if (nums[index] < nums[desc_order_index])
                {
                    break;
                }
            }
            int tmp = nums[desc_order_index];
            nums[desc_order_index] = nums[++index];
            nums[index] = tmp;
        }
    }
};

int main()
{
    // vector<int> nums = {1, 2, 3};
    // vector<int> nums = {1, 1, 5};
    // vector<int> nums = {3, 2, 1};
    // vector<int> nums = {2, 3, 1};
    // vector<int> nums = {2, 3, 1, 3, 3};
    vector<int> nums = {2, 1, 2, 2, 2, 2, 2, 1};

    Solution s;
    s.nextPermutation(nums);
    for(int item : nums)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
