#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == NULL || head->next == NULL || k == 1)
        {
            return head;
        }

        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre_node = new_head;

        while(pre_node != NULL)
        {
            ListNode* next_node = pre_node;
            for (int i = 0; i < k && next_node != NULL; i++)
            {
                next_node = next_node->next;
            }
            if (next_node == NULL)
            {
                break;
            }

            ListNode* node = pre_node->next;
            pre_node->next = next_node;
            pre_node = node;
            next_node = next_node->next;

            ListNode* pre = next_node;
            while(node != next_node)
            {
                ListNode* tmp = node->next;
                node->next = pre;
                pre = node;
                node = tmp;
            }
        }
        
        pre_node = new_head->next;
        delete new_head;
        return pre_node;
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
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution s;
    ListNode* node = s.reverseKGroup(node1, 3);
    while(node != NULL)
    {
        cout << node->val;
        if (node->next != NULL)
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
    delete node5;

    return 0;
}
