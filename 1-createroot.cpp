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

int main()
{
    struct node *root = new node(1); // root
    root->left = new node(2); // left child
    root->right = new node(3); // right child
    root->left->left = new node(4); // left child of left child
    return 0;
}
