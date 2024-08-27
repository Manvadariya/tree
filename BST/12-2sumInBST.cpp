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
void inorder(TreeNode* root, vector<int>& v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> v;
    inorder(root, v);

    int s=0, e=v.size()-1;
    while(s<e){
        if(v[s]+v[e] == k) return true;
        else if(v[s]+v[e] < k) s++;
        else e--;
    }
    return false;
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

    cout << findTarget(root, 10) << endl;
    
    return 0;
}