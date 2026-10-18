Doubly Linked List operations
#include <iostream>
#include <string>
using namespace std;
struct Node {
 string folder;
 Node* prev;
 Node* next;
};
Node* HEAD = NULL;
Node* CURRENT = NULL;
void insertBeginning(string name) {
 Node* n = new Node{name, NULL,
HEAD};
 if (HEAD != NULL)
 HEAD->prev = n;
 HEAD = n;
 if (CURRENT == NULL)
 CURRENT = n;
 cout << "Folder added
successfully.\n";
}
void insertEnd(string name) {
 Node* n = new Node{name, NULL,
NULL};
 if (HEAD == NULL) {
 HEAD = CURRENT = n;
 } else {
 Node* temp = HEAD;
 while (temp->next != NULL)
 temp = temp->next;
 temp->next = n;
 n->prev = temp;
 }
 cout << "Folder added
successfully.\n";
}
int length() {
 int count = 0;
 Node* temp = HEAD;
 while (temp != NULL) {
 count++;
 temp = temp->next;
 }
 return count;
}
void insertPosition(string name, int pos)
{
 if (pos < 1 || pos > length() + 1) {
 cout << "Invalid position.\n";
 return;
 }
 if (pos == 1) {
 insertBeginning(name);
 return;
 }
 if (pos == length() + 1) {
 insertEnd(name);
 return;
 }
 Node* temp = HEAD;
 for (int i = 1; i < pos - 1; i++)
 temp = temp->next;
 Node* n = new Node{name, temp,
temp->next};
 temp->next->prev = n;
 temp->next = n;
 cout << "Folder added
successfully.\n";
}
void deleteBeginning() {
 if (HEAD == NULL) {
 cout << "Navigation history is
empty.\n";
 return;
 }
 Node* temp = HEAD;
 HEAD = HEAD->next;
 if (HEAD != NULL)
 HEAD->prev = NULL;
 else
 CURRENT = NULL;
 if (CURRENT == temp)
 CURRENT = HEAD;
 cout << "Deleted folder: " << temp-
>folder << "\n";
 delete temp;
}
void deleteEnd() {
 if (HEAD == NULL) {
 cout << "Navigation history is
empty.\n";
 return;
 }
 Node* temp = HEAD;
 while (temp->next != NULL)
 temp = temp->next;
 if (temp->prev != NULL)
 temp->prev->next = NULL;
 else
 HEAD = NULL;
 if (CURRENT == temp)
 CURRENT = temp->prev;
 cout << "Deleted folder: " << temp-
>folder << "\n";
 delete temp;
}
void deletePosition(int pos) {
 if (pos < 1 || pos > length()) {
 cout << "Invalid position.\n";
 return;
 }
 if (pos == 1) {
 deleteBeginning();
 return;
 }
 Node* temp = HEAD;
 for (int i = 1; i < pos; i++)
 temp = temp->next;
 if (temp->prev != NULL)
 temp->prev->next = temp->next;
 if (temp->next != NULL)
 temp->next->prev = temp->prev;
 if (CURRENT == temp)
 CURRENT = temp->prev;
 cout << "Deleted folder: " << temp-
>folder << "\n";
 delete temp;
}
void searchFolder(string name) {
 Node* temp = HEAD;
 int pos = 1;
 while (temp != NULL) {
 if (temp->folder == name) {
 cout << "Folder found at position "
<< pos << ".\n";
 return;
 }
 temp = temp->next;
 pos++;
 }
 cout << "Folder not found.\n";
}
void display() {
 if (HEAD == NULL) {
 cout << "Navigation history is
empty.\n";
 return;
 }
 Node* temp = HEAD;
 cout << "Folder Navigation History: ";
 while (temp != NULL) {
 cout << temp->folder << " ";
 temp = temp->next;
 }
 cout << "\n";
}
void previousFolder() {
 if (CURRENT == NULL || CURRENT-
>prev == NULL) {
 cout << "Previous folder does not
exist.\n";
 return;
 }
 CURRENT = CURRENT->prev;
 cout << "Current folder: " <<
CURRENT->folder << "\n";
}
void nextFolder() {
 if (CURRENT == NULL || CURRENT-
>next == NULL) {
 cout << "Next folder does not
exist.\n";
 return;
 }
 CURRENT = CURRENT->next;
 cout << "Current folder: " <<
CURRENT->folder << "\n";
}
void cleanup() {
 while (HEAD != NULL) {
 Node* temp = HEAD;
 HEAD = HEAD->next;
 delete temp;
 }
 CURRENT = NULL;
}
int main() {
 int choice, pos;
 string name;
 do {
 cout << "\n--- DOUBLY LINKED LIST -
--\n";
 cout << "1. Add folder at
beginning\n";
 cout << "2. Add folder at end\n";
 cout << "3. Add folder at position\n";
 cout << "4. Delete first folder\n";
 cout << "5. Delete last folder\n";
 cout << "6. Delete folder at
position\n";
 cout << "7. Search folder\n";
 cout << "8. Display history\n";
 cout << "9. Previous folder\n";
 cout << "10. Next folder\n";
 cout << "11. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 cin.ignore(10000, '\n');
 switch (choice) {
 case 1:
 cout << "Enter folder name: ";
 getline(cin, name);
 insertBeginning(name);
 break;
 case 2:
 cout << "Enter folder name: ";
 getline(cin, name);
 insertEnd(name);
 break;
 case 3:
 cout << "Enter position: ";
 cin >> pos;
 cin.ignore(10000, '\n');
 cout << "Enter folder name: ";
 getline(cin, name);
 insertPosition(name, pos);
 break;
 case 4:
 deleteBeginning();
 break;
 case 5:
 deleteEnd();
 break;
 case 6:
 cout << "Enter position: ";
 cin >> pos;
 cin.ignore(10000, '\n');
 deletePosition(pos);
 break;
 case 7:
 cout << "Enter folder name to
search: ";
 getline(cin, name);
 searchFolder(name);
 break;
 case 8:
 display();
 break;
 case 9:
 previousFolder();
 break;
 case 10:
 nextFolder();
 break;
 case 11:
 cleanup();
 cout << "Program ended.\n";
 break;
 default:
 cout << "Invalid choice.\n";
 }
 } while (choice != 11);
 return 0;
}
