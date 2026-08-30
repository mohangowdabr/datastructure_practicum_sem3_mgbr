#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;
string stack[MAX];
int top = -1;

bool isFull() { return top == MAX - 1; }
bool isEmpty() { return top == -1; }

void push() {
    if (isFull()) {
        cout << "Stack Overflow!\n";
        return;
    }
    string page;
    cin >> page;
    top++;
    stack[top] = page;
    cout << "Visited: " << stack[top] << "\n";
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
        return;
    }
    cout << "Back from: " << stack[top] << "\n";
    top--;
    if (!isEmpty())
        cout << "Current: " << stack[top] << "\n";
}

void peek() {
    if (!isEmpty())
        cout << "Current: " << stack[top] << "\n";
}

void display() {
    if (isEmpty()) return;
    cout << "History:\n";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << "\n";
}

int main() {
    int choice;
    do {
        cout << "1.Visit 2.Back 3.Current 4.History 5.Exit: ";
        cin >> choice;
        
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exit\n"; break;
        }
    } while (choice != 5);
    
    return 0;
}
