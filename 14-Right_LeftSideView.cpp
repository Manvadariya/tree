#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

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


// right side view
void RRL(TreeNode* root, int level, vector<int>& ans){
    if(!root) return;
    if(ans.size() == level) ans.push_back(root->val);
    RRL(root->right, level+1, ans);
    RRL(root->left, level+1, ans);
}

// left side view
void RLR(TreeNode* root, int level, vector<int>& ans){
    if(!root) return;
    if(ans.size() == level) ans.push_back(root->val);
    RLR(root->left, level+1, ans);
    RLR(root->right, level+1, ans);
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

    vector<int> ans;
    RRL(root, 0, ans);
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}