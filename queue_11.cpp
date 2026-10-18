Queue using Linked List
#include <iostream>
using namespace std;
struct Node {
 int id;
 Node* next;
};
Node* FRONT = NULL;
Node* REAR = NULL;
void enqueue(int id) {
 Node* newNode = new Node;
 newNode->id = id;
 newNode->next = NULL;
 if (FRONT == NULL) {
 FRONT = REAR = newNode;
 } else {
 REAR->next = newNode;
 REAR = newNode;
 }
 cout << "Student registered: " << id <<
endl;
}
void dequeue() {
 if (FRONT == NULL) {
 cout << "Queue is empty" << endl;
 return;
 }
 Node* temp = FRONT;
 cout << "Student removed: " << temp-
>id << endl;
 FRONT = FRONT->next;
 if (FRONT == NULL)
 REAR = NULL;
 delete temp;
}
void frontElement() {
 if (FRONT == NULL)
 cout << "Queue is empty" << endl;
 else
 cout << "Front student: " << FRONT-
>id << endl;
}
void rearElement() {
 if (REAR == NULL)
 cout << "Queue is empty" << endl;
 else
 cout << "Rear student: " << REAR->id
<< endl;
}
void display() {
 if (FRONT == NULL) {
 cout << "Queue is empty" << endl;
 return;
 }
 Node* temp = FRONT;
 cout << "Queue: ";
 while (temp != NULL) {
 cout << temp->id << " ";
 temp = temp->next;
 }
 cout << endl;
}
void search(int id) {
 Node* temp = FRONT;
 int pos = 1;
 while (temp != NULL) {
 if (temp->id == id) {
 cout << "Student found at position
" << pos << endl;
 return;
 }
 temp = temp->next;
 pos++;
 }
 cout << "Student not found" << endl;
}
void isEmpty() {
 if (FRONT == NULL)
 cout << "Queue is empty" << endl;
 else
 cout << "Queue is not empty" <<
endl;
}
void size() {
 int count = 0;
 Node* temp = FRONT;
 while (temp != NULL) {
 count++;
 temp = temp->next;
 }
 cout << "Total students: " << count <<
endl;
}
int main() {
 int choice, id;
 do {
 cout << "\n--- QUEUE MENU ---\n";
 cout << "1. Enqueue\n";
 cout << "2. Dequeue\n";
 cout << "3. Front\n";
 cout << "4. Rear\n";
 cout << "5. Display\n";
 cout << "6. Search\n";
 cout << "7. IsEmpty\n";
 cout << "8. Size\n";
 cout << "9. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter student ID: ";
 cin >> id;
 enqueue(id);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 frontElement();
 break;
 case 4:
 rearElement();
 break;
 case 5:
 display();
 break;
 case 6:
 cout << "Enter student ID to
search: ";
 cin >> id;
 search(id);
 break;
 case 7:
 isEmpty();
 break;
 case 8:
 size();
 break;
 case 9:
 cout << "Exiting queue program"
<< endl;
 break;
 default:
 cout << "Invalid choice" << endl;
 }
 } while (choice != 9);
 while (FRONT != NULL) {
 Node* temp = FRONT;
 FRONT = FRONT->next;
 delete temp;
 }
 REAR = NULL;
 return 0;
}
