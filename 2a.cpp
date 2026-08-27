#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

string historyStack[MAX];
int top = -1;

// Check if stack is full
bool isFull() {
    return top == MAX - 1;
}

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Visit a new page - PUSH
void visitPage() {
    if (isFull()) {
        cout << "Stack Overflow! History is full." << endl;
        return;
    }

    string page;
    cout << "Enter page name: ";
    cin >> page;

    top++;
    historyStack[top] = page;

    cout << "Visited page: " << historyStack[top] << endl;
}

// Go back - POP
void goBack() {
    if (isEmpty()) {
        cout << "Stack Underflow! History is empty." << endl;
        return;
    }

    cout << "Going back from: " << historyStack[top] << endl;

    top--;

    if (!isEmpty()) {
        cout << "Current page: " << historyStack[top] << endl;
    }
    else {
        cout << "No previous page available." << endl;
    }
}

// Show current page - TOP/PEEK
void showCurrentPage() {
    if (isEmpty()) {
        cout << "History stack is empty." << endl;
        return;
    }

    cout << "Current page: " << historyStack[top] << endl;
}

// Display complete history - TRAVERSAL
void displayHistory() {
    if (isEmpty()) {
        cout << "History stack is empty." << endl;
        return;
    }

    cout << "Browser History:" << endl;

    for (int i = top; i >= 0; i--) {
        cout << historyStack[i] << endl;
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== BROWSER HISTORY =====" << endl;
        cout << "1. Visit New Page" << endl;
        cout << "2. Go Back" << endl;
        cout << "3. Show Current Page" << endl;
        cout << "4. Display Full History" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                visitPage();
                break;

            case 2:
                goBack();
                break;

            case 3:
                showCurrentPage();
                break;

            case 4:
                displayHistory();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}