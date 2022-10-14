#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        bool flag = dividend < 0 ^ divisor < 0;
        long ldividend = abs((long)dividend);
        long ldivisor = abs((long)divisor);

        if (ldivisor == 1)
        {
            return flag ? (int)-ldividend : (int)ldividend;
        }

        int res = 0;
        while(ldividend >= ldivisor)
        {
            long p = ldivisor;
            int q = 1;
            while(ldividend >= (p << 1))
            {
                p <<= 1;
                q <<= 1;
            }
            ldividend -= p;
            res += q;
        }
        return flag ? -res : res;
    }
};

int main()
{
    Solution s;
    // int result = s.divide(-10, -3);
    // int result = s.divide(2147483647, 1);
    int result = s.divide(-2147483648, 1);
    cout << result << endl;

    return 0;
}

