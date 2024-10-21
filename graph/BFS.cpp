#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define max 10
using namespace std;

typedef struct node
{
    int val;
    node *next;
}node;

int insert(node **first, int index, int value)
{
    node* temp=(*first);
    node* new_node=new node;
    new_node->val=value;
    new_node->next=nullptr;
    if(index == 0)
    {
        new_node->next = (*first);
        (*first) = new_node;
        return 0;
    }
    for(int i=0;temp!=nullptr && i<index-1;i++)
    {
        temp=temp->next;
    }
    if(temp == nullptr)
    {
        return -1;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return 0;
}

int deletel(node **first, int index)
{
    if((*first) == nullptr)
    {
        return -1;
    }
    node *temp = (*first);

    if (index == 0) {
        (*first) = temp->next;
        delete temp;
        return 0;
    }

    for(int i=0;temp!=nullptr && i<index-1;i++) {
        temp = temp->next;
    }

    if(temp == nullptr || temp->next == nullptr) {
        return -1;
    }

    node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
    return 0;
}
void print_list(node **first)
{
    node* temp=(*first);
    while(temp!=nullptr)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node *first = nullptr;
    int code, index, value;
    bool valid = true;
    int node_count = 0;

    while (cin >> code) {
        if (code == 1) {
            cin >> index >> value;
            if (index > node_count || node_count >= 10) {
                valid = false;
                break;
            }
            if (insert(&first, index, value) == 0) {
                node_count++;
            } else {
                valid = false;
                break;
            }
        } else if (code == 2) {
            cin >> index;
            if (index >= node_count) {
                valid = false;
                break;
            }
            if (deletel(&first, index) == 0) {
                node_count--;
            } else {
                valid = false;
                break;
            }
        } else if (code == 3) {
            break;
        }
    }

    if (valid) {
        print_list(&first);
    } else {
        cout << "INVALID SEQUENCE OF COMMANDS" << endl;
    }

    return 0;
}
