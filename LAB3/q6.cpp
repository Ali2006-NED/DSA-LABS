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

Node* InsertAtPos(Node* head, int val, int pos) {
    Node* newNode = new Node(val);

    
    if (head == NULL) {
        head = newNode;
        return head;
    }

    
    if (pos == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
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
        return head;
    }

    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head = InsertAtPos(head, 3,3); // Insert 3 at position 3 (end)
    PrintList(head);
    head = InsertAtPos(head, 0, 2); // Insert 0 at position 2 
    PrintList(head);
    return 0;
}
