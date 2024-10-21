#include<bits/stdc++.h>
using namespace std;

class Node 
{
    public:  
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) 
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) 
{
    if (root == NULL)
        return newNode(data);
        
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int search(Node* root, int x) 
{
    if (root == NULL)
        return -1;

    if (root->data == x)
        return x;

    if (root->data < x)
        return search(root->right, x);
    else
        return search(root->left, x);
}

Node* predecessor(Node* root) 
{
    if (root->left == NULL)
        return NULL;

    Node* pred = root->left;

    while(pred->right != NULL)
    {
        pred = pred->right;
    }
    return pred;
}

Node* successor(Node* root) 
{
    if (root->right == NULL)
        return NULL;

    Node* succ = root->right;

    while(succ->left != NULL)
    {
        succ = succ->left;
    }
    return succ;
}

Node* deleteNode(Node* root, int key) 
{
    if(root == NULL)
        return NULL;
    if(root->data == key)
    {
        // 0 Child Node
        if(root->left==NULL && root->right==NULL)
            return NULL;
            
        // 1 Child Node
        if(root->left==NULL || root->right==NULL)
        {
            if(root->left==NULL)
                return root->right;
            else
                return root->left;
        }
        else
        {
            Node* const pred = predecessor(root);
            root->data = pred->data;
            root->left = deleteNode(root->left , pred->data);
        }
    }
    else if(root->data > key)
        root->left = deleteNode(root->left , key); 
    else
        root->right = deleteNode(root->right , key); 
    return root;
}

int maxInTree(Node* root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int minInTree(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

void inorder(Node* root)
{
    if(root->left)
        inorder(root->left);
    cout << root->data << " ";
    if(root->right)
        inorder(root->right);  
}

int main()
{
    int n;
    cin>>n;
    if(n>10)
    {
        cout<<"-1";
        exit(0);
    }
    Node* root = NULL;
    for(int i=0 ; i<n ; i++)
    {
        int key,value;
        cin>>key>>value;
        if(i==0)
        {
            root = insert(root,value);
        }
        else
        {
            insert(root,value);
        }
    }
    
    int c;
    while(cin>>c)
    {
        switch(c)
        {
            case 1:
                {   
                    int val1;
                    cin>>val1;
                    int ans = search(root,val1);
                    if(ans == -1)
                    {
                        cout<<"INVALID SEQUENCE OF COMMANDS";
                        exit(0);
                    }
                    root = deleteNode(root,val1); 
                    break;
                }
            case 2:
                {
                    if(root==NULL)
                    {
                        cout<<"Tree is Empty";
                        exit(0);
                    }
                    int ans1 = maxInTree(root);
                    cout<<ans1<<endl;
                    break;
                }
            case 3:
                {   
                    if(root==NULL)
                    {
                        cout<<"Tree is Empty";
                        exit(0);
                    }
                    int ans2 = minInTree(root);
                    cout<<ans2<<endl;
                    break;
                }
            case 5:
                {   
                    int val2;
                    cin>>val2;
                    int ans3 = search(root,val2);
                    cout<<ans3<<endl;
                    break;
                }
            case 6:
                {
                    if(root==NULL)
                    {
                        cout<<"Tree is Empty";
                        exit(0);
                    }
                    inorder(root);
                    break;
                }
            default:
                cout<<"INVALID SEQUENCE OF COMMANDS";
                exit(0);
        }
    }
    
    return 0;
}