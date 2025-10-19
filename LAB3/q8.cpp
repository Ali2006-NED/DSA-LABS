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

Node* ReverseDoublyLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        curr->prev = next; // Update prev pointer
        prev = curr;
        curr = next;
    }
    return prev; // New head of the reversed list
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original List: ";
    PrintList(head);
    head = ReverseDoublyLL(head);
    cout << "Reversed List: ";
    PrintList(head);
    
    return 0;
}