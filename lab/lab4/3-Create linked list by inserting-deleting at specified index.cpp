typedef struct list_node {
    int item;
    struct list_node *next;
} node;

int insert(node **head_addr, int index, int value) {
    node *new_node = new node;
    new_node->item = value;
    new_node->next = nullptr;

    if (index == 0) {
        new_node->next = *head_addr;
        *head_addr = new_node;
        return 0;
    }

    node *current = *head_addr;
    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        delete new_node;
        return -1;
    }

    new_node->next = current->next;
    current->next = new_node;
    return 0;
}

int delete_node(node **head_addr, int index) {
    if (*head_addr == nullptr) {
        return -1;
    }

    node *temp = *head_addr;

    if (index == 0) {
        *head_addr = temp->next;
        delete temp;
        return 0;
    }

    for (int i = 0; temp != nullptr && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        return -1;
    }

    node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
    return 0;
}

void print_list(node **head_addr) {
    node *current = *head_addr;
    while (current != nullptr) {
        cout << current->item << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    node *head = nullptr;
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
            if (insert(&head, index, value) == 0) {
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
            if (delete_node(&head, index) == 0) {
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
        print_list(&head);
    } else {
        cout << "INVALID SEQUENCE OF COMMANDS" << endl;
    }

    return 0;
}