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
        int i = 0;
        while (s[i] == ' ' and i < s.size())
        {
            i++;
        }
        if (s[i] == '+')
        {
           i++;
        }
        else if (s[i] == '-')
        {
            pos_neg_flag = -1;
            i++;
        }

        while (s[i] >= '0' and s[i] <= '9' and i < s.size())
        {
            num *= 10;
            num += s[i] - '0';
            if ((pos_neg_flag == 1 && num > INT_MAX) || (pos_neg_flag == -1 && pos_neg_flag * num < INT_MIN))
            {
                break;
            }
            i++;
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
    // string s = "+-12";
    string s = "20000000000000000000";

    Solution solution;
    int result = solution.myAtoi(s);
    cout << result << endl;
    return 0;
}
