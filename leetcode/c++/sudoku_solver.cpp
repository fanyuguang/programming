#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool solver_sudoku_in_deep(vector<vector<char>>& board, int i, int j, vector<unordered_set<char>>& row_nums, vector<unordered_set<char>>& col_nums, vector<unordered_set<char>>& sub_box_nums)
    {
        if (i == 9 && j == 0)
        {
            return true;
        }
        int next_i = i;
        int next_j = j;
        if (next_j < 8)
        {
            next_j++;
        }
        else
        {
            next_i++;
            next_j = 0;
        }
        
        if (board[i][j] == '.')
        {
            for (int k = 0; k < 9; k++)
            {
                char cur_c = '1' + k;
                if (row_nums[i].find(cur_c) == row_nums[i].end() && col_nums[j].find(cur_c) == col_nums[j].end() && sub_box_nums[(i / 3) * 3 + j / 3].find(cur_c) == sub_box_nums[(i / 3) * 3 + j / 3].end())
                {
                    row_nums[i].insert(cur_c);
                    col_nums[j].insert(cur_c);
                    sub_box_nums[(i / 3) * 3 + j / 3].insert(cur_c);
                    board[i][j] = cur_c;

                    if (solver_sudoku_in_deep(board, next_i, next_j, row_nums, col_nums, sub_box_nums))
                    {
                        return true;
                    }

                    row_nums[i].erase(cur_c);
                    col_nums[j].erase(cur_c);
                    sub_box_nums[(i / 3) * 3 + j / 3].erase(cur_c);
                    board[i][j] = '.';
                }
            }
        }
        else
        {
            if (solver_sudoku_in_deep(board, next_i, next_j, row_nums, col_nums, sub_box_nums))
            {
                return true;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        vector<unordered_set<char>> row_nums(9, unordered_set<char>({}));
        vector<unordered_set<char>> col_nums(9, unordered_set<char>({}));
        vector<unordered_set<char>> sub_box_nums(9, unordered_set<char>({}));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    row_nums[i].insert(board[i][j]);
                    col_nums[j].insert(board[i][j]);
                    sub_box_nums[(i / 3) * 3 + j / 3].insert(board[i][j]);
                }
            }
        }

        solver_sudoku_in_deep(board, 0, 0, row_nums, col_nums, sub_box_nums);
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution s;
    s.solveSudoku(board);
    for (auto items : board)
    {
        for (char c : items)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
