struct qNode
{
    int data;
    qNode* next;
};

struct Queue
{
    qNode* front;
    qNode* rear;
};

void enqueue(Queue* q, int value){
    qNode* temp = new qNode;
    temp->data = value;
    temp->next = nullptr;
    if (q->front == nullptr)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;  
}
int dequeue(Queue* q){
    qNode* temp = q->front;
    if(q->front == q->rear){
        q->front = q->rear = nullptr;
    }
    else{
        q->front = q->front->next;
    }
    int dequedata=temp->data;
    delete temp;
    return dequedata;
}
void display(Queue* q){
    qNode* temp = q->front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Queue* q = new Queue;
    q->front = q->rear = nullptr;
    int code, value, count = 0;
    while (cin >> code)
    {
        if(code == 1){
            cin >> value;
            if(count >= 10){
                cout<< "Queue Overflow";
                exit(0);
            }
            enqueue(q,value);
            count++;
        }
        else if(code == 2){
            if (count == 0)
            {
                cout<< "Queue Underflow";
                exit(0);
            }
            dequeue(q);
            count--;
        }
        else if (code==3)
        {
            if (count == 0)
            {
                cout<< "Queue is empty";
                exit(0);
            }
            display(q);
        }
        else{
            cout<< "Operation not supported";
        }
    }
    return 0;
}
