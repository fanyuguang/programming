#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


void preorder_traversal(TreeNode* node)
{
    stack<TreeNode*> node_stack;
    if (node != NULL)
    {
        node_stack.push(node);
    }
    while (!node_stack.empty())
    {
        TreeNode* cur_node = node_stack.top();
        cout << cur_node->val << " ";
        node_stack.pop();
        if (cur_node->right != NULL)
        {
            node_stack.push(cur_node->right);
        }
        if (cur_node->left != NULL)
        {
            node_stack.push(cur_node->left);
        }
    }
    cout << endl;
}


void inorder_traversal(TreeNode* node)
{
    stack<TreeNode*> node_stack;
    TreeNode* cur_node = node;
    while (cur_node != NULL)
    {
        node_stack.push(cur_node);
        cur_node = cur_node->left;
    }

    while (!node_stack.empty())
    {
        cur_node = node_stack.top();
        cout << cur_node->val << " ";
        node_stack.pop();

        cur_node = cur_node->right;
        while (cur_node != NULL)
        {
            node_stack.push(cur_node);
            cur_node = cur_node->left;
        }
    }
    cout << endl;
}


void postorder_traversal(TreeNode* node)
{
    stack<TreeNode*> node_stack;
    stack<TreeNode*> nodes;
    if (node != NULL)
    {
        node_stack.push(node);
    }
    while (!node_stack.empty())
    {
        TreeNode* cur_node = node_stack.top();
        nodes.push(cur_node);
        node_stack.pop();
        if (cur_node->left != NULL)
        {
            node_stack.push(cur_node->left);
        }
        if (cur_node->right != NULL)
        {
            node_stack.push(cur_node->right);
        }
    }

    while(!nodes.empty())
    {
        TreeNode* cur_node = nodes.top();
        cout << cur_node->val << " ";
        nodes.pop();
    }
    cout << endl;
}


void level_order_traversal(TreeNode* node)
{
    queue<TreeNode*> node_queue;
    if (node != NULL)
    {
        node_queue.push(node);
    }
    while (!node_queue.empty())
    {
        TreeNode* cur_node = node_queue.front();
        cout << cur_node->val << " ";
        node_queue.pop();
        if (cur_node->left != NULL)
        {
            node_queue.push(cur_node->left);
        }
        if (cur_node->right != NULL)
        {
            node_queue.push(cur_node->right);
        }
    }
    cout << endl;
}


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


void print(TreeNode* root)
{   
    if (root == NULL)
    {   
        return;
    }   
    int height = get_tree_height(root);
    int width = pow(2, height) - 1;

    vector<vector<string> > layout_matrix(height, vector<string>(width, " "));
    traversal(layout_matrix, root, 0, 0, width - 1); 

    for (int i = 0; i < layout_matrix.size(); i++)
    {
        for (int j = 0; j < layout_matrix[i].size(); j++)
        {
            cout << layout_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


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

    print(node1);
    cout << "preorder_traversal: ";
    preorder_traversal(node1);
    cout << "inorder_traversal: ";
    inorder_traversal(node1);
    cout << "postorder_traversal: ";
    postorder_traversal(node1);
    cout << "level_order_traversal: ";
    level_order_traversal(node1);

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    return 0;
}
