#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void PrintList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* InsertAtBeginning(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    cout << "Node inserted at beginning.\n";
    return head;
}


Node* InsertAtPos(Node* head, int val, int pos) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        if (pos != 1) {
            cout << "List empty, inserting at position 1 instead.\n";
        }
        return newNode;
    }

    if (pos == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {  
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Node inserted at the end.\n";
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Node inserted at position " << pos << ".\n";
    }

    return head;
}


Node* DeleteAtPos(Node* head, int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return head;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        cout << "Node deleted from beginning.\n";
        return head;
    }

    Node* temp = head;
    int count = 1;
    while (count < pos && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range.\n";
        return head;
    }

    if (temp->next == NULL) {  
        temp->prev->next = NULL;
        cout << "Node deleted from end.\n";
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "Node deleted from position " << pos << ".\n";
    }

    delete temp;
    return head;
}


void Search(Node* head, int key) {
    Node* temp = head;
    int pos = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Value " << key << " found at position " << pos << ".\n";
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        cout << "Value " << key << " not found in list.\n";
}

int main() {
    Node* head = NULL;
    int choice, val, pos;

    do {
        cout << "\n===== Doubly Linked List Menu =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at Position\n";
        cout << "3. Delete at Position\n";
        cout << "4. Display List\n";
        cout << "5. Search for Value\n";
        cout << "6. Exit\n";
        cout << "Enter Operation no. (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                head = InsertAtBeginning(head, val);
                break;

            case 2:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                head = InsertAtPos(head, val, pos);
                break;

            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                head = DeleteAtPos(head, pos);
                break;

            case 4:
                PrintList(head);
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                Search(head, val);
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}