#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    result.push_back(root->val);
    preOrder(root->left, result);
    preOrder(root->right, result);
}

void inOrder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    inOrder(root->left, result);
    result.push_back(root->val);
    inOrder(root->right, result);
}

void postOrder(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->val);
}

int main() {
    int n;
    cin >> n;

    unordered_map<int, TreeNode*> nodes;
    unordered_set<int> children;

    for (int i = 1; i <= n; ++i) {
        nodes[i] = new TreeNode(i);
    }

    for (int i = 0; i < n; ++i) {
        int node, left, right;
        cin >> node >> left >> right;

        if (left != 0) {
            if (children.count(left)) {
                cout << "Left node is already a child node" << endl;
                return 0;
            }
            nodes[node]->left = nodes[left];
            children.insert(left);
        }

        if (right != 0) {
            if (children.count(right)) {
                cout << "Right node is already a child node" << endl;
                return 0;
            }
            nodes[node]->right = nodes[right];
            children.insert(right);
        }

        if (node == left || node == right) {
            cout << "Tree can not contain loop" << endl;
            return 0;
        }
    }

    TreeNode* root = nullptr;
    for (int i = 1; i <= n; ++i) {
        if (children.find(i) == children.end()) {
            root = nodes[i];
            break;
        }
    }
    vector<int> preOrderResult, inOrderResult, postOrderResult;

    preOrder(root, preOrderResult);
    inOrder(root, inOrderResult);
    postOrder(root, postOrderResult);

    for (int val : preOrderResult) cout << val << " ";
    cout << endl;
    for (int val : inOrderResult) cout << val << " ";
    cout << endl;
    for (int val : postOrderResult) cout << val << " ";
    cout << endl;

    return 0;
}