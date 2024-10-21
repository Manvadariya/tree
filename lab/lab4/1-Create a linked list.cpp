#include <bits/stdc++.h>
const int MAX = 10;
using namespace std;

typedef struct list_node {
    int item;
    struct list_node *next;
} node;

void insert_at_beginning(node **head_addr, int value) {
    node* temp = new node;
    temp->item = value;
    temp->next = *head_addr;
    *head_addr = temp;
}

void insert_at_end(node **head_addr, int value) {
    node* temp = new node;
    temp->item = value;
    temp->next = nullptr;
    if((*head_addr) == nullptr) {
        (*head_addr) = temp;
    } else {
        node* last = *head_addr;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = temp;        
    }
}

void delete_from_beginning(node **head_addr) {
    node* temp = *head_addr;
    *head_addr = (*head_addr)->next;
    delete temp;
}

void delete_from_end(node **head_addr) {
    if((*head_addr)->next == nullptr) {
        delete *head_addr;
        *head_addr = nullptr;
    } else {
        node* last = *head_addr;
        while (last->next->next != nullptr) {
            last = last->next;
        }
        delete last->next;
        last->next = nullptr;
    }
}

void print_list(node **head_addr) {
    node* temp = *head_addr;
    while (temp) {
        cout << temp->item << " ";
        temp = temp->next;
    }
}

int main() {
    node* head = nullptr;
    int node_Count = 0;
    int code, value;
    while (cin >> code) {
        if(code == 4) {
            if(head == nullptr) {
                cout << "List is Empty";
                break;
            }
            print_list(&head);
            break;
        } else if(code == 0 || code == 1) {
            cin >> value;
            if(node_Count >= MAX) {  // Changed from max to MAX
                cout << "List can not accommodate more than 10 elements";
                break;
            }
            if(code == 0) {
                insert_at_beginning(&head, value);
            } else if (code == 1) {
                insert_at_end(&head, value);
            }
            node_Count++;
        } else if(code == 2 || code == 3) {
            if(head == nullptr) {
                cout << "INVALID SEQUENCE OF COMMANDS";
                break;
            }
            if(code == 2) {
                delete_from_beginning(&head);
            } else if(code == 3) {
                delete_from_end(&head);
            }
            node_Count--;
        } else {
            cout << "INVALID SEQUENCE OF COMMANDS";
            break;
        }
    }
    return 0;
}