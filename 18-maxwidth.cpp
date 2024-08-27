#include <iostream>
#include <queue>

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

int maxWidth(TreeNode *root){
    if(root == NULL) return 0;
    int maxWidth = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first, last;
        for(int i = 0; i < size; i++){
            TreeNode *curr = q.front().first;
            int idx = q.front().second - mmin;
            q.pop();
            if(i == 0) first = idx;
            if(i == size - 1) last = idx;
            if(curr->left) q.push({curr->left, 2*idx + 1});
            if(curr->right) q.push({curr->right, 2*idx + 2});
        }
        maxWidth = max(maxWidth, last - first + 1);
    }
    return maxWidth;
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

    cout << "Max width of tree is: " << maxWidth(root) << endl;
    return 0;
}