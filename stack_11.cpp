Stack using Linked List
#include <iostream>
using namespace std;
struct Node {
 int id;
 Node* next;
};
Node* TOP = NULL;
void push(int id) {
 Node* newNode = new Node;
 newNode->id = id;
 newNode->next = TOP;
 TOP = newNode;
 cout << "Kit inserted: " << id << endl;
}
void pop() {
 if (TOP == NULL) {
 cout << "Stack is empty" << endl;
 return;
 }
 Node* temp = TOP;
 cout << "Kit removed: " << temp->id <<
endl;
 TOP = TOP->next;
 delete temp;
}
void peek() {
 if (TOP == NULL)
 cout << "Stack is empty" << endl;
 else
 cout << "Top kit: " << TOP->id <<
endl;
}
void display() {
 if (TOP == NULL) {
 cout << "Stack is empty" << endl;
 return;
 }
 Node* temp = TOP;
 cout << "Stack: ";
 while (temp != NULL) {
 cout << temp->id << " ";
 temp = temp->next;
 }
 cout << endl;
}
void search(int id) {
 Node* temp = TOP;
 int pos = 1;
 while (temp != NULL) {
 if (temp->id == id) {
 cout << "Kit found at position " <<
pos << endl;
 return;
 }
 temp = temp->next;
 pos++;
 }
 cout << "Kit not found" << endl;
}
void isEmpty() {
 if (TOP == NULL)
 cout << "Stack is empty" << endl;
 else
 cout << "Stack is not empty" <<
endl;
}
void size() {
 int count = 0;
 Node* temp = TOP;
 while (temp != NULL) {
 count++;
 temp = temp->next;
 }
 cout << "Total kits: " << count << endl;
}
int main() {
 int choice, id;
 do {
 cout << "\n--- STACK MENU ---\n";
 cout << "1. Push\n";
 cout << "2. Pop\n";
 cout << "3. Top/Peek\n";
 cout << "4. Display\n";
 cout << "5. Search\n";
 cout << "6. IsEmpty\n";
 cout << "7. Size\n";
 cout << "8. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter kit ID: ";
 cin >> id;
 push(id);
 break;
 case 2:
 pop();
 break;
 case 3:
 peek();
 break;
 case 4:
 display();
 break;
 case 5:
 cout << "Enter kit ID to search: ";
 cin >> id;
 search(id);
 break;
 case 6:
 isEmpty();
 break;
 case 7:
 size();
 break;
 case 8:
 cout << "Exiting stack program"
<< endl;
 break;
 default:
 cout << "Invalid choice" << endl;
 }
 } while (choice != 8);
 while (TOP != NULL) {
 Node* temp = TOP;
 TOP = TOP->next;
 delete temp;
 }
 return 0;
}
