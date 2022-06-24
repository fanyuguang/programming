#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string converted_s = "";
        for (int i = 0; i < numRows; i++)
        {
            int loop_size = numRows;
            if (numRows > 2)
            {
                loop_size += numRows - 2;
            }
            int max_loop = ceil((float)s.size() / (float)loop_size);
            for  (int j = 0; j < max_loop; j++)
            {
                int index1 = j * loop_size + i;
                if (index1 < s.size())
                {
                    converted_s += s[index1];
                }
                int index2 = (j + 1) * loop_size - i;
                if (i != 0 && i != numRows - 1 && index2 < s.size())
                {
                    converted_s += s[index2];
                }
            }
        }
        return converted_s;
    }
};

int main()
{
    // string s = "PAYPALISHIRING";
    // int numRows = 4;
    string s = "A";
    int numRows = 1;

    Solution solution;
    string result = solution.convert(s, numRows);
    cout << result << endl;
    return 0;
}
