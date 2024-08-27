#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// bool isSameTree(Node *p, Node *q) {
//     if (p == NULL && q == NULL) return true;
//     if (p == NULL || q == NULL) return false;
//     return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
// }

//     if (p == NULL && q == NULL) return true;
//     if (p == NULL || q == NULL) return false;
bool isSameTree(Node *p, Node *q) {
    if (p == NULL || q == NULL) return p==q;
    return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


int main() {
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    cout << isSameTree(root1, root2) << endl;

    return 0;
}