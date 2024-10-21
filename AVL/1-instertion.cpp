// insertion in AVL tree

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node *newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key) {
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->key << ",";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    
    // 21, 26, 30, 9, 4, 14, 28, 18, 15, 10, 2, 3, 7
    root = insert(root, 21);
    root = insert(root, 26);
    root = insert(root, 30);
    root = insert(root, 9);
    root = insert(root, 4);
    root = insert(root, 14);
    root = insert(root, 28);
    root = insert(root, 18);
    root = insert(root, 15);
    root = insert(root, 10);

    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);

    return 0;
}