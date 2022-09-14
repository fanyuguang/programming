#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void dfs(int n, int cur_row, vector<int>& positions, vector<vector<string>>& n_queens)
    {
        if (cur_row == n)
        {
            vector<string> cur_n_queens(n, string(n, '.'));
            for (int i =0; i < n; i++)
            {
                cur_n_queens[i][positions[i]] = 'Q';
            }
            n_queens.push_back(cur_n_queens);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                bool is_valid = true;
                for (int pre_row = 0; pre_row < positions.size(); pre_row++)
                {
                    if (positions[pre_row] == i || abs(pre_row - cur_row) == abs(positions[pre_row] - i))
                    {
                        is_valid = false;
                        break;
                    }
                }
                if (is_valid)
                {
                    positions.push_back(i);
                    dfs(n, cur_row + 1, positions, n_queens);
                    positions.pop_back();
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> n_queens;
        vector<int> positions;
        dfs(n, 0, positions, n_queens);
        return n_queens;
    }
};

int main()
{
    int n = 4;
    Solution s;
    vector<vector<string>> result = s.solveNQueens(n);
    for (auto iter1 : result)
    {
        for (auto iter2 : iter1)
        {
            cout << iter2 << endl;
        }
        cout << endl;
    }
    return 0;
}
