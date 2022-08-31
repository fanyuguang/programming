#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.size() == 0)
        {
            return res;
        }

        vector<string> next = letterCombinations(digits.substr(1));
        if (next.empty())
        {
            next.push_back("");
        }
        for (string str : next)
        {
            for (string item : digits_map[digits[0]])
            {
                res.push_back(item + str);
            }
        }
        return res;
    }

private:
    unordered_map<char, vector<string>> digits_map = {
        {'2', vector<string>({"a", "b", "c"})}, 
        {'3', vector<string>({"d", "e", "f"})},
        {'4', vector<string>({"g", "h", "i"})},
        {'5', vector<string>({"j", "k", "l"})},
        {'6', vector<string>({"m", "n", "o"})},
        {'7', vector<string>({"p", "q", "r", "s"})},
        {'8', vector<string>({"t", "u", "v"})},
        {'9', vector<string>({"w", "x", "y", "z"})}
    };
};

int main()
{
    // string digits = "23";
    string digits = "";

    Solution s;
    vector<string> result = s.letterCombinations(digits);
    for (string item : result)
    {
        cout << item << endl;
    }
    return 0;
}
