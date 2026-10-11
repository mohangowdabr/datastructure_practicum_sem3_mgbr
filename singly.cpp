#include <iostream>
using namespace std;
struct Node {
    int data;     
    Node* next;   
};
Node* HEAD = NULL;  
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = HEAD;   
    HEAD = newNode;         
    cout << "Node with value " << value << " inserted at the beginning.\n";
}
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (HEAD == NULL) {          
        HEAD = newNode;
    } else {
        Node* temp = HEAD;
        while (temp->next != NULL) {   
            temp = temp->next;
        }
        temp->next = newNode;          
    }
    cout << "Node with value " << value << " inserted at the end.\n";
}
void insertAtPosition(int value, int position) {
    // count total nodes first
    int count = 0;
    Node* temp = HEAD;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    if (position < 1 || position > count + 1) {
        cout << "Invalid position!\n";
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;

    temp = HEAD;
    for (int i = 1; i < position - 1; i++) {   
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Node with value " << value << " inserted at position " << position << ".\n";
}
void deleteAtBeginning() {
    if (HEAD == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    Node* temp = HEAD;
    cout << "Deleted node with value " << temp->data << " from the beginning.\n";
    HEAD = HEAD->next;
    delete temp;
}
void deleteAtEnd() {
    if (HEAD == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    if (HEAD->next == NULL) {   // only one node
        cout << "Deleted node with value " << HEAD->data << " from the end.\n";
        delete HEAD;
        HEAD = NULL;
        return;
    }
    Node* previous = HEAD;
    Node* current = HEAD->next;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    cout << "Deleted node with value " << current->data << " from the end.\n";
    previous->next = NULL;
    delete current;
}
void deleteAtPosition(int position) {
    if (HEAD == NULL) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    int count = 0;
    Node* temp = HEAD;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (position < 1 || position > count) {
        cout << "Invalid position!\n";
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    Node* previous = HEAD;
    Node* current = HEAD->next;
    for (int i = 2; i < position; i++) {   // move until current is the node to delete
        previous = current;
        current = current->next;
    }
    cout << "Deleted node with value " << current->data << " from position " << position << ".\n";
    previous->next = current->next;
    delete current;
}
void searchNode(int value) {
    Node* temp = HEAD;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << value << " not found in the list.\n";
}
void displayList() {
    if (HEAD == NULL) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Current Linked List: ";
    Node* temp = HEAD;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << "\n";
}
int main() {
    int choice, value, position;

    cout << "===== Singly Linked List - Coding Club Membership =====\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Specific Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Specific Position\n";
        cout << "7. Search a Value\n";
        cout << "8. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                insertAtPosition(value, position);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteAtPosition(position);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;

            case 8:
                displayList();
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}