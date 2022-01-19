#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> str_to_char(string s)
{
    vector<string> c_list;
    for (int i = 0, len = 0; i < s.size(); i += len)
    {
        unsigned char c = s[i];
        if (c > 0xFC)
        {
            len = 6;
        }
        else if (c > 0xF8)
        {
            len = 5;
        }
        else if (c > 0xF0)
        {
            len = 4;
        }
        else if (c > 0xE0)
        {
            len = 3;
        }
        else if (c > 0xC0)
        {
            len = 2;
        }
        else
        {
            len = 1;
        }
        string cur_str = s.substr(i, len);
        cout << "i: " << i << ", len: " << len << ", cur_str: " << cur_str << endl;
        c_list.push_back(cur_str);
    }
    return c_list;
}

int main()
{
    string s = "希望你happy[开心][开心][开心]";
    vector<string> res = str_to_char(s);
    for (auto c : res)
    {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
