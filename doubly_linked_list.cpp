#include <iostream>
#include <string>
using namespace std;
struct Node {
    string folderName;
    Node* prev;
    Node* next;
};
Node* HEAD = NULL;     
Node* CURRENT = NULL; 
void addAtBeginning() {
    string name;
    cout << "Enter folder name: ";
    cin >> name;
    Node* newNode = new Node();
    newNode->folderName = name;
    newNode->prev = NULL;
    newNode->next = HEAD;
    if (HEAD != NULL) {
        HEAD->prev = newNode;
    }
    HEAD = newNode;
    CURRENT = newNode;
    cout << "Folder added successfully at the beginning.\n";
}
void addAtEnd() {
    string name;
    cout << "Enter folder name: ";
    cin >> name;
    Node* newNode = new Node();
    newNode->folderName = name;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (HEAD == NULL) {
        HEAD = newNode;
        CURRENT = newNode;
    } else {
        Node* temp = HEAD;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Folder added successfully at the end.\n";
}
void addAtPosition() {
    int position;
    cout << "Enter position: ";
    cin >> position;
    if (position <= 0) {
        cout << "Invalid position.\n";
        return;
    }
    if (position == 1) {
        addAtBeginning();
        return;
    }
    Node* temp = HEAD;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }
    string name;
    cout << "Enter folder name: ";
    cin >> name;
    Node* newNode = new Node();
    newNode->folderName = name;
    Node* nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    if (nextNode != NULL) {
        nextNode->prev = newNode;
    }
    temp->next = newNode;

    cout << "Folder added successfully at position " << position << ".\n";
}
void deleteFirst() {
    if (HEAD == NULL) {
        cout << "Navigation history is empty.\n";
        return;
    }
    Node* temp = HEAD;
    HEAD = HEAD->next;
    if (HEAD != NULL) {
        HEAD->prev = NULL;
    }
    if (CURRENT == temp) CURRENT = HEAD;
    delete temp;
    cout << "First folder deleted successfully.\n";
}
void deleteLast() {
    if (HEAD == NULL) {
        cout << "Navigation history is empty.\n";
        return;
    }
    if (HEAD->next == NULL) {
        if (CURRENT == HEAD) CURRENT = NULL;
        delete HEAD;
        HEAD = NULL;
        cout << "Last folder deleted successfully.\n";
        return;
    }
    Node* temp = HEAD;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* prevNode = temp->prev;
    prevNode->next = NULL;
    if (CURRENT == temp) CURRENT = prevNode;
    delete temp;
    cout << "Last folder deleted successfully.\n";
}
void deleteAtPosition() {
    if (HEAD == NULL) {
        cout << "Navigation history is empty.\n";
        return;
    }
    int position;
    cout << "Enter position: ";
    cin >> position;
    if (position == 1) {
        deleteFirst();
        return;
    }
    Node* temp = HEAD;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }
    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;
    prevNode->next = nextNode;
    if (nextNode != NULL) {
        nextNode->prev = prevNode;
    }
    if (CURRENT == temp) CURRENT = prevNode;
    delete temp;

    cout << "Folder at position " << position << " deleted successfully.\n";
}
void searchFolder() {
    if (HEAD == NULL) {
        cout << "Navigation history is empty.\n";
        return;
    }
    string name;
    cout << "Enter folder name to search: ";
    cin >> name;
    Node* temp = HEAD;
    int position = 1;
    while (temp != NULL) {
        if (temp->folderName == name) {
            cout << "Folder found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Folder not found.\n";
}
void displayFolders() {
    if (HEAD == NULL) {
        cout << "Navigation history is empty.\n";
        return;
    }
    cout << "Folder Navigation History: ";
    Node* temp = HEAD;
    while (temp != NULL) {
        cout << temp->folderName;
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << "\n";
}
void movePrevious() {
    if (CURRENT == NULL) {
        cout << "Navigation history is empty.\n";
        return;
    }
    if (CURRENT->prev == NULL) {
        cout << "No previous folder available.\n";
        return;
    }
    CURRENT = CURRENT->prev;
    cout << "Moved to previous folder: " << CURRENT->folderName << "\n";
}
void moveNext() {
    if (CURRENT == NULL) {
        cout << "Navigation history is empty.\n";
        return;
    }
    if (CURRENT->next == NULL) {
        cout << "No next folder available.\n";
        return;
    }
    CURRENT = CURRENT->next;
    cout << "Moved to next folder: " << CURRENT->folderName << "\n";
}

int main() {
    int choice;

    do {
        cout << "\n----- Folder Navigation (Doubly Linked List) -----\n";
        cout << "1. Add Folder at Beginning\n";
        cout << "2. Add Folder at End\n";
        cout << "3. Add Folder at Specific Position\n";
        cout << "4. Delete First Folder\n";
        cout << "5. Delete Last Folder\n";
        cout << "6. Delete Folder at Specific Position\n";
        cout << "7. Search Folder\n";
        cout << "8. Display Folder Navigation History\n";
        cout << "9. Move to Previous Folder\n";
        cout << "10. Move to Next Folder\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addAtBeginning(); break;
            case 2: addAtEnd(); break;
            case 3: addAtPosition(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteAtPosition(); break;
            case 7: searchFolder(); break;
            case 8: displayFolders(); break;
            case 9: movePrevious(); break;
            case 10: moveNext(); break;
            case 11: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);

    return 0;
}