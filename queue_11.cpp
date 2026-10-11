#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Student ID " << value << " registered successfully" << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Delete the first registered student" << endl;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }
    void viewFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "View the next student" << endl;
        cout << front->data << endl;
    }
    void viewRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "View the last registered student" << endl;
        cout << rear->data << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Current Queue Contents:" << endl;
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void search(int value) {
        Node* temp = front;
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
        return (front == NULL);
    }

    void printEmpty() {
        if (isEmpty()) {
            cout << "Check the number of kits available" << endl;
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue has elements" << endl;
        }
    }
    int size() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main() {
    Queue queue;
    int choice, value;

    cout << "\n==queue operations==" << endl;
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Display\n6. Search\n7. Size\n8. IsEmpty\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter student ID to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.viewFront();
            break;
        case 4:
            queue.viewRear();
            break;
        case 5:
            queue.display();
            break;
        case 6:
            cout << "Enter student ID to search: ";
            cin >> value;
            queue.search(value);
            break;
        case 7:
            cout << "Queue size: " << queue.size() << endl;
            break;
        case 8:
            queue.printEmpty();
            break;
        case 9:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}