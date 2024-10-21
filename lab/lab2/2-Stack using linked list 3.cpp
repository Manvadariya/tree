#include <iostream>

#define MAX 10

using namespace std;
int top = -1;

struct Node {
    int data;
    Node* next;

    explicit Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
    Node* head;
    public:
    Stack() {
        head = NULL;
    }
    void push(int x) {
        if(top == MAX-1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        top++;
    }
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = head;
        head = head->next;
        int x = temp->data;
        delete temp;
        top--;
        return x;
    }
    void change(int index, int x) {
        if(top - index + 1 < 0 || top - index + 1 > top) {
            cout << "Indexed item not present in stack" << endl;
            return;
        }
        Node* temp = head;
        for(int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        temp->data = x;
    }
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int code, value, index;
    while (cin >> code) {
        switch (code) {
            case 1:
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cin >> index >> value;
                stack.change(index, value);
                break;
            case 4:
                stack.display();
                break;
            default:
                cout << "Operation not supported" << endl;
                return 0;
        }
    }
    return 0;
}