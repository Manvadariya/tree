#include <iostream>
#include <vector>
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

vector<vector<int>> zigzag(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    bool LtoR = true;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);
        for(int i=0; i<size; i++){
            TreeNode* current = q.front();
            q.pop();
            // for left to right, index will be i
            // for right to left, index will be size-i-1
            int index = LtoR ? i : (size-i-1);
            row[index] = current->val;
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        LtoR = !LtoR;
        ans.push_back(row);
    }
    return ans;
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

    vector<vector<int>> ans = zigzag(root);
    for(auto row: ans){
        for(auto ele: row){
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}