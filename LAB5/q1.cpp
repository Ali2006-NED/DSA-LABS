#include <iostream>
using namespace std;

// Template Node structure
template <typename T>
struct Node {
    T data;
    Node* next;
};

// Template LinkedListStack class
template <typename T>
class LinkedListStack {
private:
    Node<T>* top;  // pointer to top node

public:
    // Constructor
    LinkedListStack() {
        top = nullptr;
    }

    // PUSH operation (takes input inside the function)
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

    // POP operation
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


    // DISPLAY operation
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

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    LinkedListStack<int> stack; // Can change type (e.g., string, float, etc.)
    int choice;

    do {
        cout << "\n------ STACK MENU ------\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                stack.push();
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
