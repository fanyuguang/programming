#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p, int s_index, int p_index)
    {
        if (s_index == s.size() && p_index == p.size())
        {
            return true;
        }

        if (s_index < s.size() && ((p_index < p.size() - 1 && p[p_index + 1] != '*') || p_index == p.size() - 1))
        {
            if ((p[p_index] == '.' || s[s_index] == p[p_index]) && isMatch(s, p, s_index + 1, p_index + 1))
            {
                return true;
            }
        }
        else if (p_index < p.size() - 1 && p[p_index + 1] == '*')
        {
            if (isMatch(s, p, s_index, p_index + 2) || (s_index < s.size() && (p[p_index] == '.' || s[s_index] == p[p_index]) && isMatch(s, p, s_index + 1, p_index)))
            {
                return true;
            }
        }

        return false;
    }

    bool isMatch_1(string s, string p)
    {
        return isMatch(s, p, 0, 0);
    }

    bool isMatch_2(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }

        if (p.size() > 1 && p[1] == '*')
        {
            return isMatch_2(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch_2(s.substr(1), p));
        }
        else
        {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch_2(s.substr(1), p.substr(1));
        }
    }
};

int main()
{
    // string s = "aa";
    // string p = "a*";
    // string s = "abc";
    // string p = ".*";
    // string s = "aab";
    // string p = "c*a*b";
    // string s = "ab";
    // string p = ".*c";
    string s = "a";
    string p = "ab*";
    // string s = "aaaaaaaaaaaaab";
    // string p = "a*a*a*a*a*a*a*a*a*a*c";

    Solution solution;
    bool result = solution.isMatch_2(s, p);
    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
