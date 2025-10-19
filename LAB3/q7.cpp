#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void PrintList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* DeleteAtPos(Node* head, int pos) {
    if (head == NULL) {
        cout << "List is Empty" << endl;
        return head;
    }

    // Case 1: Delete first node
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        return head;
    }

    // Traverse to the position
    Node* temp = head;
    int count = 1;
    while (count < pos && temp != NULL) {
        temp = temp->next;
        count++;
    }

    // Case 2: Invalid position
    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return head;
    }

    // Case 3: Delete last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        delete temp;
        return head;
    }

    // Case 4: Delete middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;

    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;


    cout << "Original List: ";
    PrintList(head);

    head = DeleteAtPos(head, 4);  // Delete last node
    cout << "After Deletion: ";
    PrintList(head);

    head = DeleteAtPos(head, 2);  // Delete at position 2
    cout << "After Deletion: ";
    PrintList(head);

    return 0;
}
