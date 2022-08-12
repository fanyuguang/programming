#include <iostream>
#include <vector>
#include <unordered_map>

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
    bool isValidBST(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (!isValidBST(root->left) || !isValidBST(root->right))
        {
            return false;
        }

        int cur_min = root->val;
        int cur_max = root->val;
        if (root->left != NULL)
        {
            if (min_max_val[root->left][1] >= root->val)
            {
                return false;
            }
            cur_min = min_max_val[root->left][0];
        }
        if (root->right != NULL)
        {
            if (min_max_val[root->right][0] <= root->val)
            {
                return false;
            }
            cur_max = min_max_val[root->right][1];
        }
        vector<int> cur_node_min_max = {cur_min, cur_max};
        min_max_val[root] = cur_node_min_max;
        // cout << "cur_node: " << root->val << ", min: " << cur_min << ", max: " << cur_max << endl;

        return true;
    }

private:
    unordered_map<TreeNode*, vector<int>> min_max_val;
};

int main()
{
    // TreeNode* node1 = new TreeNode(5);
    // TreeNode* node2 = new TreeNode(1);
    // TreeNode* node3 = new TreeNode(4);
    // TreeNode* node4 = new TreeNode(3);
    // TreeNode* node5 = new TreeNode(6);
    // node1->left = node2;
    // node1->right = node3;
    // node3->left = node4;
    // node3->right = node5;

    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    node1->left = node2;
    node1->right = node3;

    Solution s;
    bool result = s.isValidBST(node1);
    if (result)
    {
        cout << "is valid BST" << endl;
    }
    else
    {
        cout << "is not valid BST" << endl;
    }

    delete node1;
    delete node2;
    delete node3;
    // delete node4;
    // delete node5;
    return 0;
}
