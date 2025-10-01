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

Node* InsertAtPos(Node* head, int val,int pos){

    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return head;
    }
    if(pos == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    Node* temp = head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Position out of range" << endl;
        return head;
    }
    newNode->next = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head = InsertAtPos(head, 0,2); // (Node, value, position)
    PrintList(head);
    
    return 0;
}