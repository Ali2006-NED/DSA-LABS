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

Node* DeleteAtPos(Node* head,int pos){
    if(head == NULL){
        cout << "List is Empty" << endl;
        return head;
    }
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
        delete temp;
        return head;
    }
    Node* temp = head;
    for(int i=1;i<pos && temp!=NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Position out of range" << endl;
        return head;
    }
    
    temp->prev->next = temp->next;

    temp->next->prev = temp->prev;
    delete temp;
    return head;
    
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    
    head = DeleteAtPos(head,2); 
    PrintList(head);

    return 0;
}