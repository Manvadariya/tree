#include <iostream>
#include <vector>
#include <stack>

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

vector<int> priorder(node *root){
    vector<int> ans;
    if(root == NULL)  return ans;
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node *curr = s.top();
        s.pop();
        ans.push_back(curr->data);
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
    return ans;
}

vector<int> inorder(node *root){
    vector<int> ans;
    if(root == NULL)  return ans;
    stack<node*> s;
    node *curr = root;
    while (true)
    {
        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }else if(!s.empty()){
            curr = s.top();
            s.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            break;
        }
    }
    return ans;
}
// 2 satck
// vector<int> postorder(node *root){
//     vector<int> ans;
//     if(root == NULL)  return ans;
//     stack<node*> s1, s2;
//     s1.push(root);
//     while(!s1.empty()){
//         node *curr = s1.top();
//         s1.pop();
//         s2.push(curr);
//         if(curr->left) s1.push(curr->left);
//         if(curr->right) s1.push(curr->right);
//     }
//     while(!s2.empty()){
//         ans.push_back(s2.top()->data);
//         s2.pop();
//     }
//     return ans;
// }

// 1 stack
vector<int> postorder(node *root){
    vector<int> ans;
    if(root == NULL)  return ans;
    stack<node*> s;
    node *curr = root;
    while(curr != NULL || !s.empty()){
        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }else{
            node *temp = s.top()->right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                curr = temp;
            }
        }
    }
    return ans;
}

// using 1 stack all 3 traversal

vector<vector<int>> traversal(node *root){
    stack<pair<node*, int>> s;
    s.push({root, 1});
    vector<int> pre, in, post;
    if(root == NULL)  return {};
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left!=NULL) s.push({it.first->left, 1});
        }else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right!=NULL) s.push({it.first->right, 1});
        }else{
            post.push_back(it.first->data);
        }
    }
    return {pre, in, post};
}
void print(vector<int> ans){
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
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
    // vector<int> ans = priorder(root);
    // print(ans);
    // cout<<endl;
    // ans = inorder(root);
    // print(ans);

    vector<vector<int>> ans = traversal(root);
    for(int i = 0; i < ans.size(); i++){
        print(ans[i]);
        cout<<endl;
    }
    return 0;
}
