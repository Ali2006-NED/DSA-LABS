#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* sortList(Node* head) {    //Example 1->2->3->4->5
    if(!head || !head->next) return head;
    Node*curr = head;  //curr = 1
    Node*sorted = NULL; //sorted = NULL
    while(curr != NULL){ //curr = 1 curr = 2 curr = 3
        Node*nextnode = curr->next; //nextnode = 2 nextnode = 3 nextnode = 4
        if(sorted == NULL || sorted->data >= curr->data){ //(T||F) (F||(1>=2)F) (F||(2>=3)F)
            curr->next = sorted; //1->next = NULL
            sorted = curr; //sorted = 1
        } else {
            Node*temp = sorted; //temp = 1 temp = 1
            while(temp->next != NULL && temp->next->data < curr->data){ //(T && (2<3)T)
                temp = temp->next; 
            }
            // temp=2
            curr->next = temp->next; //2->next = NULL  3->next = NULL
            temp->next = curr; //1->next = 2 2->next = 3
        }
        curr = nextnode; //curr = 2 curr = 3

    }
    return sorted;
}

int main(){

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Unsorted Linked List: ";
    printList(head);
    cout << "Sorted Linked List: ";
    head = sortList(head);
    printList(head);
    return 0;
}