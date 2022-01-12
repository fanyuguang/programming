#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int> in_degree_stats(n, 0);
        vector<int> out_degree_stats(n, 0);
        for (vector<int> items : trust)
        {
            out_degree_stats[items[0] - 1]++;
            in_degree_stats[items[1] - 1]++;
        }
        int judge_no = -1;
        for (int i = 0; i < n; i++)
        {
            if (in_degree_stats[i] == n - 1 && out_degree_stats[i] == 0)
            {
                if (judge_no != -1)
                {
                    return -1;
                }
                judge_no = i + 1;
            }
        }
        return judge_no;
    }
};

int main()
{
    // vector<vector<int>> trust = {{1, 3}, {2, 3}};
    vector<vector<int>> trust = {{1, 3}, {2, 3}, {3, 1}};
    Solution s;
    int result = s.findJudge(3, trust);
    cout << result << endl;
    return 0;
}
