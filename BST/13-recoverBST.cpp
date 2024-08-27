#include <iostream>
#include <vector>
#include <climits>

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
TreeNode* first;
TreeNode* pre;
TreeNode* mid;
TreeNode* last;
void inorder(TreeNode* root){
    if(!root)return;
    inorder(root->left);
    if(pre!=NULL && (root->val < pre->val)){
        if(first == NULL){
            first = pre;
            mid = root;
        }
        else last = root;
    }
    pre = root;
    inorder(root->right);
}
void recoverTree(TreeNode* root) {
    first = pre = mid = last = NULL;
    pre = new TreeNode(INT_MIN);
    inorder(root);
    if(first && last) swap(first->val, last->val);
    else if(first && mid) swap(first->val, mid->val);
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
    
    recoverTree(root);
    
    return 0;
}