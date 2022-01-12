#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


class Solution
{
public:
    int get_tree_height(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_height = get_tree_height(root->left);
        int right_height = get_tree_height(root->right);
        int height = left_height > right_height ? left_height + 1 : right_height + 1;
        return height;
    }


    void traversal(vector<vector<string>>& layout_matrix, TreeNode* node, int cur_height, int start, int end)
    {
        if (node != NULL)
        {
            int mid = (start + end) / 2;
            layout_matrix[cur_height][mid] = to_string(node->val);
            traversal(layout_matrix, node->left, cur_height + 1, start, mid - 1);
            traversal(layout_matrix, node->right, cur_height + 1, mid + 1, end);
        }
    }


    vector<vector<string>> printTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return vector<vector<string>>();
        }
        int height = get_tree_height(root);
        int width = pow(2, height) - 1;

        vector<vector<string> > layout_matrix(height, vector<string>(width, ""));
        traversal(layout_matrix, root, 0, 0, width - 1);
        return layout_matrix;
    }
};


int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    Solution s;
    vector<vector<string> > result = s.printTree(node1);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    return 0;
}
