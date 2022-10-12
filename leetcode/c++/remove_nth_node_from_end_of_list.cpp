#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode* node = pre_head;
        for (int i = 0; i <= n; i++)
        {
            node = node->next;
        }

        ListNode* node2 = pre_head;
        while(node)
        {
            node = node->next;
            node2 = node2->next;
        }
        node2->next = node2->next->next;
        node2 = pre_head->next;
        delete pre_head;
        return node2;
    }
};

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;

    Solution s;
    ListNode* res = s.removeNthFromEnd(node1, 2);
    while(res)
    {
        cout << res->val;
        if (res->next)
        {
            cout << " -> ";
        }
        res = res->next;
    }
    cout << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
}
