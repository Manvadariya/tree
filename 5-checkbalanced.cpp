#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int height(node* root){
    if (root == NULL) return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return 1 + max(lheight, rheight);
}

// TC: O(n^2)
// bool isBalanced(node *root){
//     if (root == NULL) return true;
//     int lheight = height(root->left);
//     int rheight = height(root->right);
//     // return abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//     if(abs(lheight - rheight) > 1) return false;
//     bool a = isBalanced(root->left);
//     if(a==false) return false;
//     bool b = isBalanced(root->right);
//     if(b==false) return false;
//     return true;
// }

// TC: O(n)
int isBalanced(node* root){
    if(root == NULL) return 0;
    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    root->right->right->left = new node(10);
    root->right->right->right = new node(11);
    root->left->right->left->left = new node(12);
    root->right->right->left->right = new node(13);

    cout << isBalanced(root);
    return 0;
}