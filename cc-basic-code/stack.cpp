#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty())
    {
        int temp = s.top();
        cout << temp << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
