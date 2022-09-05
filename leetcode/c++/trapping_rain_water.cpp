#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        if (height.size() <= 2)
        {
            return 0;
        }

        int trap_area = 0;
        int left = 0;
        int right = height.size() - 1;
        int left_max = height[left];
        int right_max = height[right];
        while(left <= right)
        {
            left_max = height[left] > left_max ? height[left] : left_max;
            right_max = height[right] > right_max ? height[right] : right_max;
            if (left_max <= right_max)
            {
                trap_area += left_max - height[left];
                left++;
            }
            else
            {
                trap_area += right_max - height[right];
                right--;
            }
        }
        return trap_area;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution s;
    int result = s.trap(height);
    cout << result << endl;
    return 0;
}
