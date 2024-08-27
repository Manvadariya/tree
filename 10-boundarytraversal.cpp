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

bool isLeaf(TreeNode *root)
{
    return root->left == NULL && root->right == NULL;
}
void leftBoundary(TreeNode *root, vector<int> &ans){
    TreeNode *curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void rightBoundary(TreeNode *root, vector<int> &ans){
    TreeNode *curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->val);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size() - 1; i >= 0; i--) ans.push_back(temp[i]);
}
void leafNodes(TreeNode *root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->val);
        return;
    }
    if(root->left) leafNodes(root->left, ans);
    if(root->right) leafNodes(root->right, ans);
}
vector<int> printBoundary(TreeNode *root){
    vector<int> ans;
    if(root == NULL) return ans;
    // if root is not a leaf node
    if(!isLeaf(root)) ans.push_back(root->val);
    // left boundary
    leftBoundary(root, ans);
    // leaf nodes
    leafNodes(root, ans);
    // right boundary
    rightBoundary(root, ans);
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

    vector<int> ans = printBoundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}