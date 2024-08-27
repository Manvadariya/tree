#include <iostream>
#include <vector>

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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    if(root == NULL) return NULL;
    if(root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left == NULL) return right;
    if(right == NULL) return left;
    return root;
}


// bool getPath(TreeNode* root, vector<TreeNode*>& ans, int x) {
//     if (!root) return false;
//     ans.push_back(root);
//     if (root->val == x) return true;
//     if (getPath(root->left, ans, x) || getPath(root->right, ans, x)) return true;
//     ans.pop_back();
//     return false;
// }
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> pPath, qPath;
//         getPath(root, pPath, p->val);
//         getPath(root, qPath, q->val);
//         int minn = min(pPath.size(), qPath.size());
//         TreeNode* lca = nullptr;
//         for (int i = 0; i < minn; i++) {
//             if (pPath[i]->val != qPath[i]->val) {
//                 return pPath[i - 1];
//             }
//             lca = pPath[i];
//         }
//         return lca;
//     }
// };


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

    return 0;
}