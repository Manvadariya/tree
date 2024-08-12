#include <iostream>
#include <climits>

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

// int height(node *root){
//     if(root == NULL) return 0;
//     int lh = height(root->left);
//     int rh = height(root->right);
//     return 1 + max(lh, rh);
// }

// int maxPathSum(node *root, int &res){
//     if(root == NULL) return 0;
//     int lh = maxPathSum(root->left, res);
//     int rh = maxPathSum(root->right, res);
//     int temp = max(max(lh, rh) + root->data, root->data);
//     int ans = max(temp, lh + rh + root->data);
//     res = max(res, ans);
//     return temp;
// }

// streturgy: take every node as root and find the max path sum


int determine(TreeNode* root, int& maxx){
    if(!root) return 0;
    int lsum = max(0,determine(root->left, maxx));
    int rsum = max(0,determine(root->right, maxx));
    cout << "Preious maxx: " << maxx << "\t";
    maxx = max(maxx,lsum+rsum+root->val);
    cout << maxx << endl;
    return root->val + max(lsum, rsum);
}

int maxPathSum(TreeNode* root) {
    int maxx=INT_MIN;
    determine(root, maxx);
    return maxx;
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

    maxPathSum(root);
    return 0;
}