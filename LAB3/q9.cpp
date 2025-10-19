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

Node* MergeTwoDLL(Node* head1, Node* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node* tail = head1;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = head2;
    head2->prev = tail;

    return head1;
}

int main(){

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->prev = head1;
    head1->next->next = new Node(3);
    head1->next->next->prev = head1->next;


    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->prev = head2;
    head2->next->next = new Node(6);
    head2->next->next->prev = head2->next;

    Node* mergedHead = MergeTwoDLL(head1, head2);
    cout << "Merged List: ";
    PrintList(mergedHead);

    return 0;
}