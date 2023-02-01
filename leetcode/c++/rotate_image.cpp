#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][m - j - 1];
                matrix[i][m - j - 1] = temp;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m - i; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m - j - 1][m - i - 1];
                matrix[m - j - 1][m - i - 1] = temp;
            }
        }
        int a = 0;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s;
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
