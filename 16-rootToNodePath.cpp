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

bool getPath(TreeNode* root, vector<int>& ans, int x){
    if(!root) return false;
    ans.push_back(root->val);
    if(root->val == x) return true;
    if(getPath(root->left, ans, x)) return true;
    if(getPath(root->right, ans, x)) return true;
    ans.pop_back();
    return false;
}
// all the path to the leaf node
// void getPath(Node* root, vector<vector<int>>& ans, vector<int>& a) {
//     if (root == NULL) return;
//     a.push_back(root->data);
//     if (root->left == NULL && root->right == NULL) {
//         ans.push_back(a);
//     } else {
//         if (root->left) getPath(root->left, ans, a);
//         if (root->right) getPath(root->right, ans, a);
//     }
//     a.pop_back();
// }

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> a;
        getPath(root, ans, a);
        return ans;
    }
};

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

    vector<int> ans;
    getPath(root, ans, 13);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}