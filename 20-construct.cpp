#include <iostream>
#include <vector>
#include <map>

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

TreeNode* buildTreeInPost(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, map<int, int>& m){
    if(inStart > inEnd || postStart > postEnd) return NULL;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int rootIndex = m[root->val];
    int leftSize = rootIndex - inStart;
    root->left = buildTreeInPost(inorder, postorder, inStart, rootIndex-1, postStart, postStart+leftSize-1, m);
    root->right = buildTreeInPost(inorder, postorder, rootIndex+1, inEnd, postStart+leftSize, postEnd-1, m);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() != postorder.size()) return NULL;
    map<int, int> m;
    for(size_t i=0; i<inorder.size(); i++)
        m[inorder[i]] = i;
    return buildTreeInPost(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, m);
}

// TreeNode* buildTreeInPre(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd, map<int, int>& m){
//     if(inStart > inEnd || preStart > preEnd) return NULL;
//     TreeNode* root = new TreeNode(preorder[preStart]);
//     int rootIndex = m[root->val];
//     int leftSize = rootIndex - inStart;
//     root->left = buildTreeInPre(inorder, preorder, inStart, rootIndex-1, preStart+1, preStart+leftSize, m);
//     root->right = buildTreeInPre(inorder, preorder, rootIndex+1, inEnd, preStart+leftSize+1, preEnd, m);
//     return root;
// }
// TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
//     if(inorder.size() != preorder.size()) return NULL;
//     map<int, int> m;
//     for(size_t i=0; i<inorder.size(); i++)
//         m[inorder[i]] = i;
//     return buildTreeInPre(inorder, preorder, 0, inorder.size()-1, 0, preorder.size()-1, m);
// }

int main(){
    // inorder = [40, 20, 50, 10, 60, 30]
    // postorder = [40, 50, 20, 60, 30, 10]
    // preorder = [10, 20, 40, 50, 30, 60]
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    vector<int> preorder = {10, 20, 40, 50, 30, 60};

    TreeNode* root = buildTree(inorder, postorder);

    // TreeNode* root = buildTree(inorder, preorder);
    
    // print tree in level order
    vector<TreeNode*> q;
    q.push_back(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.erase(q.begin());
        if(node == NULL){
            cout << "null ";
            continue;
        }
        cout << node->val << " ";
        q.push_back(node->left);
        q.push_back(node->right);
    }
    cout << endl;
    return 0;
}