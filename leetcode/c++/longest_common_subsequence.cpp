#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> matrix(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                int cur_longest = matrix[i][j + 1] > matrix[i + 1][j] ? matrix[i][j + 1] : matrix[i + 1][j];
                if (text1[i] == text2[j])
                {
                    cur_longest = cur_longest > matrix[i][j] + 1 ? cur_longest : matrix[i][j] + 1;
                }
                matrix[i + 1][j + 1] = cur_longest;
            }
        }
        return matrix[text1.size()][text2.size()];
    }
};

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    Solution s;
    int result = s.longestCommonSubsequence(text1, text2);
    cout << result << endl;
    return 0;
}
