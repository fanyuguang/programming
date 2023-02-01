#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        int m = num1.size();
        int n = num2.size();
        vector<int> res1(m + n, 0);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int cur_multiply = (num1[i] - '0') * (num2[j] - '0') + res1[i + j + 1];
                res1[i + j] += cur_multiply / 10;
                res1[i + j + 1] = cur_multiply % 10;
            }
        }

        string res = "";
        int i = res1[0] != 0 ? -1 : 0;
        while (++i < m + n)
        {
            res += res1[i] + '0';
        }
        return res;
    }
};

int main()
{
    string num1 = "123";
    string num2 = "456";

    Solution s;
    string result = s.multiply(num1, num2);
    cout << result << endl;
    return 0;
}
