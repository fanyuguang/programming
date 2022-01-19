#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                int cur = dp[i][j - 1] > dp[i + 1][j] ? dp[i][j - 1] : dp[i + 1][j];
                if (s[i] == s[j])
                {
                    cur = cur > dp[i + 1][j - 1] + 2 ? cur : dp[i + 1][j - 1] + 2;
                }
                dp[i][j] = cur;
            }
        }
        return dp[0][s.size() - 1];
    }
};

int main()
{
    string str = "bbbab";
    Solution s;
    int result = s.longestPalindromeSubseq(str);
    cout << result << endl;
    return 0;
}
