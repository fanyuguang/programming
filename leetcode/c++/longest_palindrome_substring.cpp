#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string longest_str = s.substr(0, 1);
        int longest = 1;
        vector<vector<bool> > dp_array(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++)
        {
            dp_array[i][i] = true;
        }

        for (int span = 2; span <= s.size(); span++)
        {
            for (int i = 0; i <= s.size() - span; i++)
            {
                int j = i + span - 1;
                if (((span == 2) || (span > 2 && dp_array[i + 1][j - 1] == true)) && (s[i] == s[j]))
                {
                    dp_array[i][j] = true;
                    if (j - i + 1 > longest)
                    {
                        longest = span;
                        longest_str = s.substr(i, span);
                    }
                }
            }
        }
        return longest_str;
    }
};

int main()
{
    // string s = "babad";
    // string s = "cbbd";
    // string s = "aaaa";
    string s = "abaca";
    Solution solution;
    string result = solution.longestPalindrome(s);
    cout << result << endl;
    return 0;
}

