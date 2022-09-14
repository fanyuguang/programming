#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void dfs(int n, int cur_row, vector<int>& positions, int& n_queens_nums)
    {
        if (cur_row == n)
        {
            n_queens_nums++;
            return;
        }
        
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
                dfs(n, cur_row + 1, positions, n_queens_nums);
                positions.pop_back();
            }
        }
    }

    int totalNQueens(int n)
    {
        int n_queens_nums = 0;
        vector<int> positions;
        dfs(n, 0, positions, n_queens_nums);
        return n_queens_nums;
    }
};

int main()
{
    int n = 4;
    Solution s;
    int result = s.totalNQueens(n);
    cout << result << endl;
    return 0;
}
