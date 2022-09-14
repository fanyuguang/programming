#include <iostream>
#include <vector>
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

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (ListNode* node : lists)
        {
            if (node)
            {
                q.push(node);
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while(!q.empty())
        {
            ListNode* cur_node = q.top();
            node->next = cur_node;
            node = node->next;
            q.pop();
            if(cur_node->next)
            {
                q.push(cur_node->next);
            }
        }
        node = head->next;
        delete head;
        return node;
    }
};

int main()
{
    ListNode* node1_1 = new ListNode(1);
    ListNode* node1_2 = new ListNode(4);
    ListNode* node1_3 = new ListNode(5);

    ListNode* node2_1 = new ListNode(1);
    ListNode* node2_2 = new ListNode(3);
    ListNode* node2_3 = new ListNode(4);

    ListNode* node3_1 = new ListNode(2);
    ListNode* node3_2 = new ListNode(6);

    node1_1->next = node1_2;
    node1_2->next = node1_3;
    node2_1->next = node2_2;
    node2_2->next = node2_3;
    node3_1->next = node3_2;

    vector<ListNode*> lists = {node1_1, node2_1, node3_1};

    Solution s;
    ListNode* result = s.mergeKLists(lists);
    ListNode* iter = result;
    while(iter != NULL)
    {
        cout << iter->val;
        if (iter->next != NULL)
        {
            cout << " -> ";
        }
        iter = iter->next;
    }
    cout << endl;

    delete node1_1;
    delete node1_2;
    delete node1_3;
    delete node2_1;
    delete node2_2;
    delete node2_3;
    delete node3_1;
    delete node3_2;
    return 0;
}
