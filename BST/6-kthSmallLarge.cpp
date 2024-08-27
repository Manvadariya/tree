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

// like in-order traversal
void KthSmall(TreeNode *root, int k, int &ans, int &count)
{
    if (root == NULL) return;
    KthSmall(root->left, k, ans, count);
    count++;
    if (count == k) ans = root->val;
    KthSmall(root->right, k, ans, count);
}

// like reverse in-order traversal
void KthLarge(TreeNode *root, int k, int &ans, int &count)
{
    if (root == NULL) return;
    KthLarge(root->right, k, ans, count);
    count++;
    if (count == k) ans = root->val;
    KthLarge(root->left, k, ans, count);
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
    
    return 0;
}