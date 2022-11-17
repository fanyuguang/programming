#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push(make_pair(root, 1));
        int max_width = 1;

        while(!q.empty())
        {
            unsigned long long left = q.front().second;
            unsigned long long right;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* cur_node = q.front().first;
                right = q.front().second;
                q.pop();

                if (n == 1)
                {
                    right = 1;
                }
                if (cur_node->left)
                {
                    q.push(make_pair(cur_node->left, 2 * right));
                }
                if (cur_node->right)
                {
                    q.push(make_pair(cur_node->right, 2 * right + 1));
                }
            }
            if (int(right - left + 1) > max_width)
            {
                max_width = int(right - left + 1);
            }
        }
        return max_width;
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(9);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;

    Solution s;
    int result = s.widthOfBinaryTree(node1);
    cout << result << endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0;
}
