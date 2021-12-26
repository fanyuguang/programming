#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int word1_len = word1.size();
        int word2_len = word2.size();

        vector<vector<int> > distance_matrix(word1_len + 1, vector<int>(word2_len + 1));
        for(int i = 0; i < word1_len + 1; i++)
        {
            distance_matrix[i][0] = i;
        }
        for(int j = 0; j < word2_len + 1; j++)
        {
            distance_matrix[0][j] = j;
        }
        int cur_min_distance = 0;
        for(int i = 1; i < word1_len + 1; i++)
        {
            for(int j = 1; j < word2_len + 1; j++)
            {
                cur_min_distance = distance_matrix[i - 1][j - 1];
                if(word1[i - 1] != word2[j - 1])
                {
                     cur_min_distance++;
                }
                cur_min_distance = cur_min_distance < distance_matrix[i - 1][j] + 1 ? cur_min_distance : distance_matrix[i - 1][j] + 1;
                cur_min_distance = cur_min_distance < distance_matrix[i][j - 1] + 1 ? cur_min_distance : distance_matrix[i][j - 1] + 1;
                distance_matrix[i][j] = cur_min_distance;
           }
        }
        return distance_matrix[word1_len][word2_len];
    }
};

int main()
{
    // string word1 = "horse";
    // string word2 = "ros";
    string word1 = "zoologicoarchaeologist";
    string word2 = "zoogeologist";
    Solution s;
    int min_distance = s.minDistance(word1, word2);
    cout << min_distance << endl;
    return 0;
}
