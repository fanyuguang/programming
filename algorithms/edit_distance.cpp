#include <iostream>
#include <string>

using namespace std;

int min(int a, int b, int c)
{    
    a = a < b ? a : b;
    return a < c ? a : c;
}

int get_min_cost(string a, string b, int x, int y, int z)
{
    // Add cost x, delete cost y, modify cost z
    int dp[a.length() + 1][b.length() + 1];
    for(int i = 0; i <= a.length(); i++)
    {
        dp[i][0] = i * y;
    }
    for(int j = 1; j <= b.length(); j++)
    {
        dp[0][j] = j * x;
    }
    for(int i = 0; i < a.length(); i++)
    {
        for(int j = 0; j < b.length(); j++)
        {
            if(a[i] == b[j])
            {
                dp[i+1][j+1] = dp[i][j];
            }
            else
            {
                dp[i+1][j+1] = min(dp[i][j + 1] + y, dp[i + 1][j] + x, dp[i][j] + z);
            }
        }
    }
    return dp[a.length()][b.length()];
}

int main() 
{
    string a = "abc";
    string b = "be";
    int cost = get_min_cost(a, b, 1, 1, 1);
    cout << cost << endl;
    return 0;
}
