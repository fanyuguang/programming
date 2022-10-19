#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int longest = 0;
        stack<char> c_stack;
        stack<int> c_indexes;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (!c_stack.empty() && c == ')' && c_stack.top() == '(')
            {
                c_stack.pop();
                c_indexes.pop();

                int cur_long;
                if (c_indexes.empty())
                {
                    cur_long = i + 1;
                }
                else
                {
                    cur_long = i - c_indexes.top();
                }
                if (cur_long > longest)
                {
                    longest = cur_long;
                }
            }
            else
            {
                c_stack.push(c);
                c_indexes.push(i);
            }
        }
        return longest;
    }
};

int main()
{
    // string s = ")()())";
    // string s = "(()";
    string s = "";

    Solution solution;
    int result = solution.longestValidParentheses(s);
    cout << result << endl;

    return 0;
}
