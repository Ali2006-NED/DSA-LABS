#include<iostream>
using namespace std;


template <typename T>
struct Node {
    T data;
    Node* next;
};


template <typename T>
class LinkedListStack {
private:
    Node<T>* top;  

public:
    
    LinkedListStack() {
        top = nullptr;
    }

    
    void push() {
        T val;
        cout << "Enter value to push: ";
        cin >> val;

        Node<T>* newNode = new Node<T>();
        newNode->data = val;
        newNode->next = top;
        top = newNode;

        cout << val << " pushed into stack.\n";
    }

    
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        cout << top->data << " popped from stack.\n";
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }


    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements (top to bottom): ";
        Node<T>* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    bool isEmpty() {
        return top == nullptr;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Top element is: " << top->data << endl;
    }
};

int main(){
    LinkedListStack<int> s;
    s.push();
    s.push();
    cout << "Top element: ";
    s.peek();
    return 0;

}