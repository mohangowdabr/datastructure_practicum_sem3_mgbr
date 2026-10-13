
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << "ID=" << value << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "The Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        cout << "Delete the Last kit: " << temp->data << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Current available kit" << endl;
            cout << top->data << endl;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";

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
                cout << "Kit found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Kit not found" << endl;
    }

    void size() {
        int count = 5;
        Node* temp = top;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Total number of Kits = "
             << count << endl;
    }

    void isEmpty() {
        if (top == NULL) {
            cout << "Check the Stack: Stack is empty" << endl;
        } else {
            cout << "Check the Stack: Stack has elements" << endl;
        }
    }

    void isFull() {
        cout << "Check the Stack: Stack is not full" << endl;
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n===== STACK USING LINKED LIST =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Display" << endl;
        cout << "5. Search" << endl;
        cout << "6. Size" << endl;
        cout << "7. IsEmpty" << endl;
        cout << "8. IsFull" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter kit ID: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Enter kit ID to search: ";
                cin >> value;
                s.search(value);
                break;

            case 6:
                s.size();
                break;

            case 7:
                s.isEmpty();
                break;

            case 8:
                s.isFull();
                break;

            case 9:
                cout << "Program ended" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 9);

    return 0;
}
