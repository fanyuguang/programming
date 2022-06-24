#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int countPrefixes(vector<string>& words, string s)
    {
        unordered_map<string, int> words_map;
        for (string word : words)
        {
            if (words_map.find(word) == words_map.end())
            {
                words_map[word] = 1;
            }
            else
            {
                words_map[word] += 1;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= s.size(); i++)
        {
            string sub_word = s.substr(0, i);
            if (words_map.find(sub_word) != words_map.end())
            {
                cnt += words_map[sub_word];
            }
        }
        return cnt;
    }
};

int main()
{
    vector<string> words = {"a", "b", "c", "ab", "bc", "abc"};
    string s = "abc";

    Solution solution;
    int result = solution.countPrefixes(words, s);
    cout << result << endl;
    return 0;
}
