#include <iostream>
#include <queue>

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

void childrenSum(TreeNode *root)
{
    if (root == NULL) return;
    int childSum = 0;
    if (root->left) childSum += root->left->val;
    if (root->right) childSum += root->right->val;
    if(childSum>root->val) root->val = childSum;
    else{
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }
    childrenSum(root->left);
    childrenSum(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root->left || root->right) root->val = total;
}

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(10);
    root->right->right->right = new TreeNode(11);
    root->left->right->left->left = new TreeNode(12);
    root->right->right->left->right = new TreeNode(13);

    childrenSum(root);
    return 0;
}