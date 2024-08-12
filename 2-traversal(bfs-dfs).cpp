#include <iostream>
#include <vector>
#include <queue>

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


// preorder dfs traversal
void preorder(node *root)
{
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// inorder dfs traversal
void inorder(node *root)
{
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// postorder dfs traversal
void postorder(node *root)
{
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// bfs traversal (level order traversal)
vector<vector<int>> bfs(node *root){
    vector<vector<int>> ans;
    if(root == NULL)  return ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            node *curr = q.front();
            q.pop();
            level.push_back(curr->data);
            if(curr->left)  q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        ans.push_back(level);
    }
    return ans;
}
void levelNodes(node* root, vector<vector<int>>& answer, int level){
    if(root == NULL) return;
    // if(answer.size() <= level){
    //     answer.push_back({});
    // }
    // this is compulsory if we are not initializing the answer vector with empty vectors
    answer[level].push_back(root->data);
    levelNodes(root->left, answer, level + 1);
    levelNodes(root->right, answer, level + 1);
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
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    vector<vector<int>> ans = bfs(root);
    for(auto level : ans){
        for(auto ele : level){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
