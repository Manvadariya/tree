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
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);

    cout << height(root);
    return 0;
}