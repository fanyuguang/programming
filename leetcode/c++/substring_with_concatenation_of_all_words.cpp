#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool is_substring(string substring, unordered_map<string, int> word_cnt_map)
    {
        int word_len = word_cnt_map.begin()->first.size();
        for (int i = 0; i < substring.size(); i+=word_len)
        {
            string word = substring.substr(i, word_len);
            if (word_cnt_map.find(word) == word_cnt_map.end() || word_cnt_map[word] == 0)
            {
                return false;
            }
            else
            {
                word_cnt_map[word] -= 1;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> substring_indexes;
        unordered_map<string, int> word_cnt_map;
        for (string word : words)
        {
            if (word_cnt_map.find(word) != word_cnt_map.end())
            {
                word_cnt_map[word] += 1;
            }
            else
            {
                word_cnt_map[word] = 1;
            }
        }

        int substring_len = words.size() * words[0].size();
        for (int i = 0; i <= (int)s.size() - substring_len; i++)
        {
            if (is_substring(s.substr(i, substring_len), word_cnt_map))
            {
                substring_indexes.push_back(i);
            }
        }
        return substring_indexes;
    }
};

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    // string s = "a";
    // vector<string> words = {"a", "a"};

    Solution solution;
    vector<int> result = solution.findSubstring(s, words);
    for (int item : result)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
