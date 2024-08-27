#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

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

struct NodeInfo {
    int x, y, value;
    NodeInfo(int x, int y, int value) : x(x), y(y), value(value) {}
};
bool compare(const NodeInfo& a, const NodeInfo& b) {
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y < b.y;
    return a.value < b.value;
}
struct QueueNode {
    TreeNode* node;
    int x;
    int y;
    QueueNode(TreeNode* node, int x, int y) : node(node), x(x), y(y) {}
};
void inorderTraversal(TreeNode* node, int x, int y, vector<NodeInfo>& nodes) {
    if (!node) return;
    inorderTraversal(node->left, x - 1, y + 1, nodes);
    nodes.push_back(NodeInfo(x, y, node->val));
    inorderTraversal(node->right, x + 1, y + 1, nodes);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<NodeInfo> nodes;
    inorderTraversal(root, 0, 0, nodes);
    sort(nodes.begin(), nodes.end(), compare);
    vector<vector<int>> ans;
    int current_x = nodes[0].x;
    ans.push_back({nodes[0].value});
    for (int i = 1; i < nodes.size(); ++i) {
        if (nodes[i].x == current_x) {
            ans.back().push_back(nodes[i].value);
        } else {
            current_x = nodes[i].x;
            ans.push_back({nodes[i].value});
        }
    }
    return ans;
}

// vector<vector<int>> verticalTraversal(TreeNode* root){
//     vector<NodeInfo> nodes;
//     queue<QueueNode> q;
//     q.push(QueueNode(root, 0, 0));
//     // Level order traversal
//     while (!q.empty()) {
//         QueueNode current = q.front();
//         q.pop();
//         TreeNode* node = current.node;
//         int x = current.x;
//         int y = current.y;
//         nodes.push_back(NodeInfo(x, y, node->val));
//         if (node->left) q.push(QueueNode(node->left, x - 1, y + 1));
//         if (node->right) q.push(QueueNode(node->right, x + 1, y + 1));
//     }
//     sort(nodes.begin(), nodes.end(), compare);
//     vector<vector<int>> ans;
//     int current_x = nodes[0].x;
//     ans.push_back({nodes[0].value});
//     for (int i = 1; i < nodes.size(); ++i) {
//         if (nodes[i].x == current_x) {
//             ans.back().push_back(nodes[i].value);
//         } else {
//             current_x = nodes[i].x;
//             ans.push_back({nodes[i].value});
//         }
//     }
//     return ans;
// }


// vector<vector<int>> verticalTraversal(TreeNode* root){
//     map<int, map<int, multiset<int>>> nodes;
//     queue<pair<TreeNode*, pair<int, int>>> q;
//     q.push({root, {0, 0}});
//     // level order traversal
//     while(!q.empty()){
//         auto current = q.front();
//         q.pop();
//         TreeNode* node = current.first;
//         int x = current.second.first;
//         int y = current.second.second;
//         nodes[x][y].insert(node->val);
//         if(node->left) q.push({node->left, {x-1, y+1}});
//         if(node->right) q.push({node->right, {x+1, y+1}});
//     }
//     vector<vector<int>> ans;
//     for(auto x: nodes){
//         vector<int> col;
//         for(auto y: x.second){
//             col.insert(col.end(), y.second.begin(), y.second.end());
//         }
//         ans.push_back(col);
//     }
//     return ans;
// }


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

    vector<vector<int>> ans = verticalTraversal(root);
    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}