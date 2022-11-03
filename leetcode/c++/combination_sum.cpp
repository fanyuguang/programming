#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    void combination_sum_deep(vector<int>& candidates, int target, int start, vector<int> cur_res, vector<vector<int>>& sum_res)
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
            cur_res.push_back(candidates[i]);
            combination_sum_deep(candidates, target - candidates[i], i, cur_res, sum_res);
            cur_res.pop_back();
        }
    }

	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> sum_res;
        vector<int> cur_res;
        combination_sum_deep(candidates, target, 0, cur_res, sum_res);
        return sum_res;
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution s;
    vector<vector<int>> result = s.combinationSum(candidates, target);
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
