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

// TreeNode* findLastRightNode(TreeNode* root){
//     if(root->right == NULL) return root;
//     return findLastRightNode(root->right);
// }

// TreeNode* helper(TreeNode* root){
//     if(root->left == NULL) return root->right;
//     if(root->right == NULL) return root->left;
//     TreeNode* rightNode = root->right;
//     TreeNode* lastRightNode = findLastRightNode(root->left);
//     lastRightNode->right = rightNode;
//     return root->left;
// }

// TreeNode* deleteNode(TreeNode* root, int target){
//     if(root == NULL) return NULL;
//     if(root->val == target){
//         return helper(root);
//     }
//     TreeNode* current = root;
//     while(current){
//         if(current->val > target){
//             if(current->left != NULL && current->left->val == target){
//                 current->left = helper(current->left);
//                 break;
//             }
//             else current = current->left;
//         }
//         else{
//             if(current->right != NULL && current->right->val == target){
//                 current->right = helper(current->right);
//                 break;
//             }
//             else current = current->right;
//         }
//     }
//     return root;
// }

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val == key)
    {
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        TreeNode *rightNode = root->right;
        TreeNode *lastRightNode = root->left;
        while (lastRightNode->right)
            lastRightNode = lastRightNode->right;
        lastRightNode->right = rightNode;
        return root->left;
    }
    TreeNode *current = root;
    while (current)
    {
        if (current->val > key)
        {
            if (current->left && current->left->val == key)
            {
                current->left = deleteNode(current->left, key);
                break;
            }
            else
                current = current->left;
        }
        else
        {
            if (current->right && current->right->val == key)
            {
                current->right = deleteNode(current->right, key);
                break;
            }
            else
                current = current->right;
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

    root = deleteNode(root, 6);

    return 0;
}