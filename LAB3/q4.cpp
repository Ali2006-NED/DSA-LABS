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

void SearchValue(Node* head, int val){
    Node* temp = head;
    int pos = 1;
    while(temp != NULL){
        if(temp->data == val){
            cout << "Value " << val << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << val << " not found in the list" << endl;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    SearchValue(head, 2);
    

    
    return 0;
}