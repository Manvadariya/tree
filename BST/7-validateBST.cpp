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

bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
{
    if (root == NULL) return true;
    if (minNode != NULL && root->val <= minNode->val) return false;
    if (maxNode != NULL && root->val >= maxNode->val) return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

// do an in-order traversal and 
// check if the elements are in ascending order
void valid(TreeNode* root,vector<int> &v){
    if(root==NULL)return;
    valid(root->left,v);
    v.push_back(root->val);
    valid(root->right,v);
}
bool isValidBST(TreeNode* root) {
    vector<int>v;
    valid(root,v);
    for(int i=1;i<v.size();i++){
        if(v[i]<=v[i-1])return false;
    }
    return true;
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

    cout << isValidBST(root, NULL, NULL) << endl;

    return 0;
}