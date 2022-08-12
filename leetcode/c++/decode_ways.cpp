#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        return get_num_of_decoding(s, 0);
    }

    int get_num_of_decoding(string s, int start)
    {
        if (s[start] == '0')
        {
            return 0;
        }

        if (start >= s.length() - 1)
        {
            return 1;
        }

        if (decoding_mapping.find(start) != decoding_mapping.end())
        {
            return decoding_mapping[start];
        }

        int num_of_decoding = 0;
        int one_num = stoi(s.substr(start, 1));
        if (one_num >=1 && one_num <= 26)
        {
            num_of_decoding += get_num_of_decoding(s, start + 1);
        }
        int two_num = stoi(s.substr(start, 2));
        if (two_num >= 1 && two_num <= 26)
        {
            num_of_decoding += get_num_of_decoding(s, start + 2);
        }

        decoding_mapping[start] = num_of_decoding;
        return num_of_decoding;
    }

private:
    unordered_map<int, int> decoding_mapping;
};

int main()
{
    // string s = "226";
    string s = "0";
    Solution solution;

    int num_of_decoding = solution.numDecodings(s);
    cout << num_of_decoding << endl;

    return 0;
}

