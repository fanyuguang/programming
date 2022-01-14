#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        long num = 0;
        int pos_neg_flag = 1;
        int pos_neg_cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] == '+')
            {
                pos_neg_cnt += 1;
                continue;
            }
            else if (s[i] == '-')
            {
                pos_neg_flag = -1;
                pos_neg_cnt += 1;
                continue;
            }

            if (pos_neg_cnt > 1)
            {
                break;
            }

            if (s[i] >= '0' && s[i] <= '9')
            {
                num *= 10;
                num += s[i] - '0';
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.')
            {
                break;
            }
            else if (num != 0 && s[i] == ' ')
            {
                break;
            }
        }
        num *= pos_neg_flag;

        if (num < INT_MIN)
        {
            return INT_MIN;
        }
        else if (num > INT_MAX)
        {
            return INT_MAX;
        }
        else
        {
            return int(num);
        }
    }
};

int main()
{
    // string s = "   -42";
    // string s = "4193 with words";
    // string s = "3.14159";
    string s = "+-12";
    Solution solution;
    int result = solution.myAtoi(s);
    cout << result << endl;
    return 0;
}
