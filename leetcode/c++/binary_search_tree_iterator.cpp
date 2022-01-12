#include <iostream>
#include <stack>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator
{
public:
    BSTIterator(TreeNode* root) 
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() 
    {
        TreeNode* node = s.top();
        int val = node->val;
        s.pop();
        node = node->right;
        while(node)
        {
            s.push(node);
            node = node->left;
        }
        return val;
    }
    
    bool hasNext() 
    {
        return !s.empty();
    }

private:
    stack<TreeNode*> s;
};


int main()
{
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;

    BSTIterator* iter = new BSTIterator(node1);
    while(iter->hasNext())
    {
        int val = iter->next();
        cout << val << " -> ";
    }
    cout << endl;

    delete node1;
    delete node2;
    delete node3;
    delete iter;
    
    return 0;
}
