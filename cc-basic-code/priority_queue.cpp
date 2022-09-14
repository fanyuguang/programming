#include <iostream>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare
{
    bool operator()(ListNode* a, ListNode* b)
    {
        // min heap
        return a->val > b->val;
    }
};



int main()
{
    // max_heap
    priority_queue<int> q1;
    // min_heap
    priority_queue<int, vector<int>, greater<int>> q2;
    
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    q2.push(5);

    while(!q1.empty())
    {
        int temp = q1.top();
        cout << temp << " ";
        q1.pop();
    }
    cout << endl;
    while(!q2.empty())
    {
        int temp = q2.top();
        cout << temp << " ";
        q2.pop();
    }
    cout << endl;


    priority_queue<ListNode*, vector<ListNode*>, compare> q3;

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(4);
    q3.push(node1);
    q3.push(node2);
    q3.push(node3);
    q3.push(node4);

    while(!q3.empty())
    {
        ListNode* cur_node = q3.top();
        cout << cur_node->val << " ";
        q3.pop();
    }
    cout << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
