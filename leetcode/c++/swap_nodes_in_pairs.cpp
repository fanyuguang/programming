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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;

        ListNode* node_pre = new_head;
        ListNode* node = head;
        while(node != NULL && node->next != NULL)
        {
            if (node_pre != NULL)
            {
                node_pre->next = node->next;
            }

            ListNode* tmp = node->next->next;
            node->next->next = node;
            node->next = tmp;

            node_pre = node;
            node = node->next;
        }
        node = new_head->next;
        delete new_head;
        return node;
    }
};

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution s;
    ListNode* node = s.swapPairs(node1);
    while(node)
    {
        cout << node->val;
        if (node->next)
        {
            cout << "->";
        }
        node = node->next;
    }
    cout << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
