#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        unordered_set<string> parenthesis;
        if (n == 0)
        {
            parenthesis.insert("");
        }
        else
        {
            vector<string> pre = generateParenthesis(n - 1);
            for (string cur_parenthesis : pre)
            {
                for (int i = 0; i < cur_parenthesis.size(); ++i)
                {
                    if (cur_parenthesis[i] == '(')
                    {
                        string tmp = cur_parenthesis;
                        tmp.insert(i + 1, "(");
                        tmp.insert(i + 2, ")");
                        parenthesis.insert(tmp);
                    }
                }
                string tmp = "()" + cur_parenthesis;
                parenthesis.insert(tmp);
            }
        }
        return vector<string>(parenthesis.begin(), parenthesis.end());
    }
};

int main()
{
    int n = 3;

    Solution s;
    vector<string> result = s.generateParenthesis(n);
    for (auto item : result)
    {
        cout << item << endl;
    }
    return 0;
}
