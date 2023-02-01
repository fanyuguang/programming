#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return is_match_inner(s, p, 0, 0) > 0;
    }

    int is_match_inner(string s, string p, int i, int j)
    {
        if (i == s.size() && j == p.size())
        {
            return 1;
        }
        if (i== s.size() && j < p.size() && p[j] != '*')
        {
            return 0;
        }
        if (i < s.size() && j == p.size())
        {
            return -1;
        }

        if (i < s.size() && j < p.size() && p[j] != '*')
        {
            if (s[i] == p[j] || p[j] == '?')
            {
                return is_match_inner(s, p, i + 1, j + 1);
            }
            else
            {
                return -1;
            }
        }

        if (j < p.size() && p[j] == '*')
        {
            while (j + 1 < p.size() && p[j + 1] == '*')
            {
                j++;
            }
            for (int k = i; k <= s.size(); k++)
            {
                int cur_res = is_match_inner(s, p, k, j + 1);
                if (cur_res == 0 || cur_res == 1)
                {
                    return cur_res;
                }
            }
        }

        return -1;
    }
};

int main()
{
    // string s = "ca";
    // string p = "?a";
    // string s = "aa";
    // string p = "*";
    string s = "a";
    string p = "a*";
    // string s = "adceb";
    // string p = "*a*b";
    // string s = "abefcdgiescdfimde";
    // string p = "ab*cd?i*de";
    // string s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    // string p = "a*******b";
    // string s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
    // string p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";

    Solution solution;
    bool result = solution.isMatch(s, p);
    if (result)
    {
        cout << "Match" << endl;
    }
    else
    {
        cout << "Not match" << endl;
    }
    return 0;
}
