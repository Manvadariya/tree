
using namespace std;

#define MAXSIZE 10

struct Node {
    int item;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

void insert_at_beginning(int value) {
    if (size >= MAXSIZE) {
        cout << "List can not accommodate more than 10 elements" << endl;
        exit(0);
    }

    Node* newNode = new Node();
    newNode->item = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }

    head = newNode;
    size++;
}

void insert_at_end(int value) {
    if (size >= MAXSIZE) {
        cout << "List can not accommodate more than 10 elements" << endl;
        exit(0);
    }

    Node* newNode = new Node();
    newNode->item = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }

    tail = newNode;
    size++;
}

void delete_from_beginning() {
    if (head == nullptr) {
        cout << "INVALID SEQUENCE OF COMMANDS" << endl;
        exit(0);
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    size--;
}

void delete_from_end() {
    if (tail == nullptr) {
        cout << "INVALID SEQUENCE OF COMMANDS" << endl;
        exit(0);
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
    size--;
}

void print_list() {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->item << " ";
        temp = temp->next;
    }
    cout << endl;

    temp = tail;
    while (temp != nullptr) {
        cout << temp->item << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int code, value;

    while (cin >> code) {
        switch (code) {
            case 0:
                cin >> value;
                insert_at_beginning(value);
                break;
            case 1:
                cin >> value;
                insert_at_end(value);
                break;
            case 2:
                delete_from_beginning();
                break;
            case 3:
                delete_from_end();
                break;
            case 4:
                print_list();
                exit(0);
            default:
                cout << "INVALID SEQUENCE OF COMMANDS" << endl;
                return 0;
        }
    }

    return 0;
}