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

// TreeNode* insertNode(TreeNode* root, int val){
//     if(root == NULL) return new TreeNode(val);
//     if(val < root->val) root->left = insertNode(root->left, val);
//     else root->right = insertNode(root->right, val);
//     return root;
// }

TreeNode* insertNode(TreeNode* root, int val){
    if(root == NULL) return new TreeNode(val);
    TreeNode* current = root;
    while(root){
        if(current->val < val){
            if(current->right != NULL) current = current->right;
            else{
                current->right = new TreeNode(val);
                break;
            }
        }
        else{
            if(current->left != NULL) current = current->left;
            else{
                current->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
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

    root = insertNode(root, 15);
    return 0;
}