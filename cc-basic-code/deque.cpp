#include <iostream>
#include <queue>

using namespace std;

int main()
{
    deque<int> q;
    q.push_front(1);
    q.push_front(2);
    q.push_back(3);
    q.push_back(4);
    
    for(int item : q)
    {
        cout << item << " ";
    }
    cout << endl;

    cout << "pop front: ";
    while(!q.empty() && q.size() > 2)
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop_front();
    }
    cout << endl;

    cout << "pop back: ";
    while(!q.empty())
    {
        int temp = q.back();
        cout << temp << " ";
        q.pop_back();
    }
    cout << endl;


    return 0;
}
