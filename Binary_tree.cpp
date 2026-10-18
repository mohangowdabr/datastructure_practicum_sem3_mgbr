
#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a node using level-order insertion
void insert(Node *&root, int value) {
    Node *newNode = new Node(value);

    if (root == NULL) {
        root = newNode;
        cout << "Node inserted successfully.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            q.push(temp->right);
        }
    }

    cout << "Node inserted successfully.\n";
}

// Search for an element
bool search(Node *root, int key) {
    if (root == NULL)
        return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->data == key)
            return true;

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }

    return false;
}

// Delete the deepest rightmost node
void deleteDeepestNode(Node *&root, Node *deepest) {
    if (root == deepest) {
        delete root;
        root = NULL;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->left == deepest) {
            delete temp->left;
            temp->left = NULL;
            return;
        }

        if (temp->right == deepest) {
            delete temp->right;
            temp->right = NULL;
            return;
        }

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

// Delete a specified element
bool deleteNode(Node *&root, int key) {
    if (root == NULL)
        return false;

    queue<Node*> q;
    q.push(root);

    Node *target = NULL;
    Node *deepest = NULL;

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp->data == key && target == NULL)
            target = temp;

        deepest = temp;

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }

    if (target == NULL)
        return false;

    if (target == deepest) {
        deleteDeepestNode(root, deepest);
    } else {
        target->data = deepest->data;
        deleteDeepestNode(root, deepest);
    }

    return true;
}

// Display the tree in level order
void display(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "Binary Tree (Level Order): ";

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }

    cout << "\n";
}

// Release all allocated memory
void freeTree(Node *root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node *root = NULL;
    int choice, value;

    do {
        cout << "\n===== BINARY TREE OPERATIONS =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Display Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                if (!(cin >> value)) {
                    cout << "Invalid input! Enter an integer.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                insert(root, value);
                break;

            case 2:
                cout << "Enter value to search: ";
                if (!(cin >> value)) {
                    cout << "Invalid input! Enter an integer.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (search(root, value))
                    cout << "Element found in the tree.\n";
                else
                    cout << "Element not found in the tree.\n";
                break;

            case 3:
                cout << "Enter value to delete: ";
                if (!(cin >> value)) {
                    cout << "Invalid input! Enter an integer.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (deleteNode(root, value))
                    cout << "Node deleted successfully.\n";
                else
                    cout << "Element not found. Deletion failed.\n";
                break;

            case 4:
                display(root);
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    freeTree(root);
    return 0;
}
