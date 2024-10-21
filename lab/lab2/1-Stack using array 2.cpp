#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Stack {
    private:
        int arr[MAX_SIZE]; // Array to store stack elements
        int top; 
    public:
        Stack() {
            for(int i = 0; i < MAX_SIZE; i++)
                arr[i] = 0; // Initialize all elements to 0
            top = -1; // Initialize top index to -1 (empty stack)
        }
        bool isFull() {
            return top == MAX_SIZE - 1; // Check if stack is full
        }
        bool isEmpty() {
            return top == -1; // Check if stack is empty
        }
        void push(int value) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
                return;
            }
            arr[++top] = value;
        }
        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return arr[top--];
        }
        void change(int index, int value) {
            if(top - index + 1 < 0 || top - index + 1 > top){
                cout << "Indexed item not present in stack" << endl;
                return;
            }
            arr[top - index + 1] = value;
        }
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl; // Display message if stack is empty
                return;
            }
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " "; // Display elements from top to bottom
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
                stack.push(value); // Push value onto the stack
                break;
            case 2:
                stack.pop(); // Pop the top element from the stack
                break;
            case 3:
                cin >> index >> value;
                stack.change(index, value); // Change value at specified index
                break;
            case 4:
                stack.display(); // Display the stack
                break;
            default:
                cout << "Operation not supported" << endl; // Display error message for unsupported operation
                return 0;
        }
    }
    return 0;
}