#include <iostream>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    int rand10()
    {
        int num = -1;
        do
        {
            num = (rand7() - 1) * 7 + rand7();
        } while (num > 40);
        num = num % 10 + 1;
        return num;
    }

private:
    int rand7()
    {
        int num = rand() % 7 + 1;
        return num;
    }
};

int main()
{
    Solution s;
    for (int i = 0; i < 50; i++)
    {
        int random_num = s.rand10();
        cout << random_num << endl;
    }
    return 0;
}
