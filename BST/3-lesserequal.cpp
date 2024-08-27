#include <iostream>

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

int findFloor(TreeNode* root, int target){
    int floor = -1;
    while(root != NULL){
        if(root->val == target){
            floor = target;
            return floor;
        }
        if(target < root->val) root = root->left;
        else{
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
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
    
    cout << findFloor(root, 12) << endl;

    return 0;
}