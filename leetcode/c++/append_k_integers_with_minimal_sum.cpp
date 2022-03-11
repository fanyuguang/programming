#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long minimalKSum_1(vector<int>& nums, int k)
    {
        unordered_set<int> num_set;
        for (int num : nums)
        {
            num_set.insert(num);
        }
        long long k_sum = 0;
        int k_cnt = 0;
        int i = 1;
        while(k_cnt < k)
        {
            if (num_set.find(i) == num_set.end())
            {
                k_sum += i;
                k_cnt++;
            }
            i++;
        }
        return k_sum;
    }

    long long minimalKSum(vector<int>& nums, int k)
    {
        long long k_sum = (long long)k * (1 + k) / 2;

        unordered_map<int, int> num_map;
        for (int num : nums)
        {
            num_map[num] = 1;
        }

        int max_num = k + 1;
        bool flag = true;
        while(flag)
        {
            flag = false;
            for (auto item : num_map)
            {
                int num = item.first;
                if (num < max_num && item.second == 1)
                {
                    k_sum += max_num - num;
                    max_num++;
                    flag = true;
                    num_map[num] = 0;
                }
            }
        }
        return k_sum;
    }
};

int main()
{
    vector<int> nums = {1, 4, 25, 10, 25};
    int k = 2;
    // vector<int> nums = {53,41,90,33,84,26,50,32,63,47,66,43,29,88,71,28,83};
    // int k = 76;
    Solution s;
    long long result = s.minimalKSum(nums, k);
    cout << result << endl;
    return 0;
}
