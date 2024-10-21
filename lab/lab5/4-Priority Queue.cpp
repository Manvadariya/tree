#include <iostream>

using namespace std;

struct qNode { 
    int data ; // value of the node 
    int priority ; // priority of the node 
    struct qNode* next; //address to next node in queue 
};

struct Queue { 
    struct qNode* front ; //address of the front qNode 
    struct qNode* rear ; //address of the rear qNode 
};

void enqueue(struct Queue *Q, int data, int priority)
{
    struct qNode *temp = new qNode();
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    if(Q->front == NULL){
        Q->front = Q->rear = temp;
        return;
    }
    if(Q->front->priority > priority){
        temp->next = Q->front;
        Q->front = temp;
        return;
    }
    struct qNode *curr = Q->front;
    while(curr->next != NULL && curr->next->priority <= priority){
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

int dequeue(struct Queue *Q)
{
    if(Q->front == NULL){
        cout << "Queue Underflow" << endl;
        exit(0);
    }
    struct qNode *temp = Q->front;
    Q->front = Q->front->next;
    int data = temp->data;
    delete temp;
    return data;
}

void display(struct Queue *Q)
{
    if(Q->front == NULL){
        cout << "Queue is empty" << endl;
        exit(0);
    }
    struct qNode *curr = Q->front;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    struct Queue *Q = new Queue();
    Q->front = Q->rear = NULL;
    int code;
    while(cin >> code){
        if(code == 1){
            int data, priority;
            cin >> data >> priority;
            enqueue(Q, data, priority);
        }
        else if(code == 2){
            dequeue(Q);
        }
        else if(code == 3){
            display(Q);
        }
        else{
            cout << "Operation not supported" << endl;
            exit(0);
        }
    }
    return 0;
}