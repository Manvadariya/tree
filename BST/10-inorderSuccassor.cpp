#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p){
    TreeNode *succassor = NULL;
    while (root)
    {
        if (p->val >= root->val) root = root->right;
        else {
            succassor = root;
            root = root->left;
        }
    }
    return succassor;
}   

int main()
{
    struct TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);
    root->right->right->right = new TreeNode(18);
    root->left->right->left->right = new TreeNode(5);

    TreeNode *p = root->left->right->left;
    TreeNode *succassor = inorderSuccessor(root, p);
    if (succassor) cout << succassor->val << endl;
    else cout << "No succassor" << endl;
    return 0;
}