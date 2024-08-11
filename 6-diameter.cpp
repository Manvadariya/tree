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

int height(node *root){
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}

// // Time complexity: O(n^2)
// void diameter(node *root, int &res){
//     if(root == NULL) return ;
//     int lh = height(root->left);
//     int rh = height(root->right);
//     res = max(res, lh + rh);
//     diameter(root->left, res);
//     diameter(root->right, res);
// }

// Time complexity: O(n)
int diameter(node *root, int &res){
    if(root == NULL) return 0;
    int lh = diameter(root->left, res);
    int rh = diameter(root->right, res);
    res = max(res, lh + rh);
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

    int res = 0;
    diameter(root, res);
    cout << res << endl;
    return 0;
}