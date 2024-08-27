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

vector<int> topview(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    map<int, int> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        TreeNode* currNode = current.first;
        int line = current.second;
        if(mpp.find(line) == mpp.end()) mpp[line] = currNode->val;
        if(currNode->left) q.push({currNode->left,line-1});
        if(currNode->right) q.push({currNode->right,line+1});
    }
    for(auto i : mpp){
        ans.push_back(i.second);
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

    vector<int> ans = topview(root);
    for(auto x: ans){
        cout << x << " ";
    }
    return 0;
}