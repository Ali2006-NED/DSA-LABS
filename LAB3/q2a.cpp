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

Node* InsertAtBeginning(Node* head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return head;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    cout << "Original List: ";
    PrintList(head);
    head = InsertAtBeginning(head, 5);
    cout << "After Inserting: ";
    PrintList(head);
    return 0;
}