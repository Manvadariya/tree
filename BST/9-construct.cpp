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

// TreeNode* bstFromPreorder(vector<int>& preorder) {
//     if (preorder.size() == 0) return NULL;
//     struct TreeNode *root = new TreeNode(preorder[0]);
//     vector<int> left, right;
//     for (int i = 1; i < preorder.size(); i++) {
//         if (preorder[i] < preorder[0]) left.push_back(preorder[i]);
//         else right.push_back(preorder[i]);
//     }
//     root->left = bstFromPreorder(left);
//     root->right = bstFromPreorder(right);
//     return root;
// }

TreeNode* bstFromPreorder(vector<int>& A) {
    int i = 0;
    return build(A, i, INT_MAX);
}
TreeNode* build(vector<int>& A, int& i, int bound) {
    if (i >= A.size() || A[i] > bound) return NULL;
    TreeNode* root = new TreeNode(A[i++]);
    root->left = build(A, i, root->val);
    root->right = build(A, i, bound);
    return root;
}


int main()
{
    // struct TreeNode *root = new TreeNode(8);
    // root->left = new TreeNode(3);
    // root->right = new TreeNode(10);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(6);
    // root->right->left = new TreeNode(9);
    // root->right->right = new TreeNode(14);
    // root->left->right->left = new TreeNode(4);
    // root->left->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(13);
    // root->right->right->right = new TreeNode(18);
    // root->left->right->left->right = new TreeNode(5);
    
    // 8 3 1 6 4 5 7 10 9 14 13 18
    vector<int> preorder = {8, 3, 1, 6, 4, 5, 7, 10, 9, 14, 13, 18};
    struct TreeNode *root = bstFromPreorder(preorder);
    return 0;
}