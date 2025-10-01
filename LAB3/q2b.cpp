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

Node* InsertAtEnd(Node* head, int val){
    Node* newNode = new Node(val);
    Node* temp = head;
    if(head == NULL){
        head = newNode;
        return head;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head = InsertAtEnd(head, 3);
    PrintList(head);
    
    return 0;
}