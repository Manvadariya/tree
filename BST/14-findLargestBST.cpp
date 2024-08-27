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

class NodeValue{
public:
    int maxNode, minNode, maxBSTSize;
    NodeValue(int minNode, int maxNode, int maxBSTSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxBSTSize = maxBSTSize;
    }
};
NodeValue largestBSThelper(TreeNode* root){
    if(root == NULL) return NodeValue(INT_MAX, INT_MIN, 0);
    NodeValue left = largestBSThelper(root->left);
    NodeValue right = largestBSThelper(root->right);
    if(left.maxNode < root->val && right.minNode > root->val)
        return NodeValue(min(left.minNode, root->val), max(right.maxNode, root->val),
                left.maxBSTSize + right.maxBSTSize + 1);
    else
        return NodeValue(INT_MIN, INT_MAX, max(left.maxBSTSize, right.maxBSTSize));
}
int largestBST(TreeNode* root){
    return largestBSThelper(root).maxBSTSize;
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
    
    cout << "Size of the largest BST is " << largestBST(root);
    return 0;
}