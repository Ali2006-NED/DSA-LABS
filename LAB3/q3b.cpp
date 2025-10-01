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

Node* DeleteAtEnd(Node* head){
    if(head == NULL) cout << "List is Empty"; return head;

    Node* temp = head;

    for(; temp->next != NULL; temp = temp->next);
    if(temp->prev != NULL) temp->prev->next = NULL;
    else head = NULL; 
    delete temp;
    return head; 
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->prev = head->next;
    
    head = DeleteAtEnd(head); 
    PrintList(head);

    return 0;
}