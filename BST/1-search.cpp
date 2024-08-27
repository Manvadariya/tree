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

// TreeNode* search(TreeNode* root, int target){
//     if(root == NULL) return NULL;
//     if(root->val == target) return root;
//     if(root->val > target) return search(root->left, target);
//     return search(root->right, target);
// }

TreeNode* search(TreeNode* root, int target){
    while(root != NULL && root->val != target){
        root = target < root->val ? root->left : root->right;
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
    
    cout << search(root, 6)->val << endl;

    return 0;
}