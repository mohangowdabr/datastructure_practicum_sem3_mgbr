#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "ID=" << value << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << " the Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Delete the Last kit" << endl;
        top = top->next;
        delete temp;
    }
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Current available kit" << endl;
        cout << top->data << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Current Stack Contents:" << endl;
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void search(int value) {
        Node* temp = top;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Element found at position: " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element not found" << endl;
    }
    bool isEmpty() {
        return (top == NULL);
    }
    void printEmpty() {
        if (isEmpty()) {
            cout << "Check the Stack" << endl;
        } else {
            cout << "Stack has elements" << endl;
        }
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack stack;
    int choice, value;
    cout << "\n====Stack using Linked List=====" << endl;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Search\n6. IsEmpty\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.peek();
            break;
        case 4:
            stack.display();
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            stack.search(value);
            break;
        case 6:
            stack.printEmpty();
            break;
        case 7:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}