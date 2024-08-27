#include <iostream>
#include <stack>
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

class BSTIterator {
private:
    stack<TreeNode*> s;
    void pushAll(TreeNode* root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushAll(temp->right);
        return temp->val;
    }
    bool hasNext() {
        return !s.empty();
    }
};

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

    BSTIterator i = BSTIterator(root);
    while (i.hasNext())
        cout << i.next() << " ";
    cout << endl;
    return 0;
}