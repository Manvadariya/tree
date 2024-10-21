const int MAXSIZE = 10;

typedef struct list_node {
    int item;
    struct list_node *next;
} node;

void insert_at_end(node **head_addr, int value) {
    node* temp = new node;
    temp->item = value;
    temp->next = nullptr;
    
    if (*head_addr == nullptr) {
        *head_addr = temp;
    } else {
        node* last = *head_addr;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = temp;
    }
}

void print_list(node **head_addr) {
    if (*head_addr == nullptr) {
        cout << "List is Empty";
        return;
    }
    
    node* temp = *head_addr;
    while (temp) {
        cout << temp->item << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse_list(node **head_addr) {
    if (*head_addr == nullptr) {
        cout << "List is Empty";
        return;
    }
    
    vector<int> value;
    node* temp = *head_addr;
    while (temp) {
        value.push_back(temp->item);
        temp = temp->next;
    }
    
    for (auto it = value.rbegin(); it != value.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    node* head = nullptr;
    string input;
    int value, node_count = 0;

    getline(cin, input);
    if (input.empty()) {
        cout << "List is Empty";
        return 0;
    }

    stringstream ss(input);
    while (ss >> value) {
        if (node_count >= MAXSIZE) {
            cout << "List can not accommodate more than " << MAXSIZE << " elements";
            return 0;
        }
        insert_at_end(&head, value);
        node_count++;
    }

    print_list(&head);
    print_reverse_list(&head);

    return 0;
}