#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> nums;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (nums.find(board[i][j]) != nums.end())
                    {
                        return false;
                    }
                    nums.insert(board[i][j]);
                }
            }
        }

        for (int j = 0; j < 9; j++)
        {
            unordered_set<char> nums;
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] != '.')
                {
                    if (nums.find(board[i][j]) != nums.end())
                    {
                        return false;
                    }
                    nums.insert(board[i][j]);
                }
            }
        }

        for (int i = 0; i < 9; i+=3)
        {
            for (int j = 0; j < 9; j+=3)
            {
                unordered_set<char> nums;
                for (int i_ = i; i_ < i + 3; i_++)
                {
                    for (int j_ = j; j_ < j + 3; j_++)
                    {
                        if (board[i_][j_] != '.')
                        {
                            if (nums.find(board[i_][j_]) != nums.end())
                            {
                                return false;
                            }
                            nums.insert(board[i_][j_]);
                        }
                    }
                }
            }
        }

        return true;
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
    bool result = s.isValidSudoku(board);
    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
