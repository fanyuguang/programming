#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void combination_sum_deep(vector<int>& candidates, unordered_map<int, int>& candidates_cnt, int target, int start, vector<int> cur_res, vector<vector<int>>& sum_res)
    {
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            sum_res.push_back(cur_res);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates_cnt[candidates[i]] > 0)
            {
                candidates_cnt[candidates[i]]--;
                cur_res.push_back(candidates[i]);
                combination_sum_deep(candidates, candidates_cnt, target - candidates[i], i, cur_res, sum_res);
                cur_res.pop_back();
                candidates_cnt[candidates[i]]++;
            }
        }
    }

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<int> candidates_2;
        unordered_map<int, int> candidates_cnt;
        for (int num : candidates)
        {
            if (candidates_cnt.find(num) == candidates_cnt.end())
            {
                candidates_2.push_back(num);
                candidates_cnt[num] = 1;
            }
            else
            {
                candidates_cnt[num]++;
            }
        }

        vector<vector<int>> sum_res;
        vector<int> cur_res;
        combination_sum_deep(candidates_2, candidates_cnt, target, 0, cur_res, sum_res);
        return sum_res;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    for (auto items : result)
    {
        for (auto item : items)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}
