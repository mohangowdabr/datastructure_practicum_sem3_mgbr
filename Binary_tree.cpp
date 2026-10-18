
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node *&root, int value)
{
    Node *newNode = createNode(value);

    if (root == NULL)
    {
        root = newNode;
        cout << "Node inserted successfully\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = newNode;
            cout << "Node inserted successfully\n";
            return;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = newNode;
            cout << "Node inserted successfully\n";
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void search(Node *root, int value)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == value)
        {
            cout << "Node found\n";
            return;
        }

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }

    cout << "Node not found\n";
}

void deleteDeepest(Node *root, Node *last)
{
    queue<Node*> q;
    q.push(root);

    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
        {
            if (temp->left == last)
            {
                delete temp->left;
                temp->left = NULL;
                return;
            }
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            if (temp->right == last)
            {
                delete temp->right;
                temp->right = NULL;
                return;
            }
            q.push(temp->right);
        }
    }
}

void deleteNode(Node *&root, int value)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == value)
        {
            delete root;
            root = NULL;
            cout << "Node deleted successfully\n";
        }
        else
        {
            cout << "Node not found\n";
        }
        return;
    }

    queue<Node*> q;
    q.push(root);

    Node *target = NULL;
    Node *last = NULL;

    while (q.size() > 0)
    {
        last = q.front();
        q.pop();

        if (last->data == value)
            target = last;

        if (last->left != NULL)
            q.push(last->left);

        if (last->right != NULL)
            q.push(last->right);
    }

    if (target == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    target->data = last->data;
    deleteDeepest(root, last);

    cout << "Node deleted successfully\n";
}

void display(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "Tree elements: ";

    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }

    cout << endl;
}

int main()
{
    Node *root = NULL;
    int choice, value;

    do
    {
        cout << "\n--- BINARY TREE OPERATIONS ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Display Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input\n";
            break;
        }

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                if (cin >> value)
                    insert(root, value);
                else
                {
                    cout << "Invalid input\n";
                    return 0;
                }
                break;

            case 2:
                cout << "Enter value to search: ";
                if (cin >> value)
                    search(root, value);
                else
                {
                    cout << "Invalid input\n";
                    return 0;
                }
                break;

            case 3:
                cout << "Enter value to delete: ";
                if (cin >> value)
                    deleteNode(root, value);
                else
                {
                    cout << "Invalid input\n";
                    return 0;
                }
                break;

            case 4:
                display(root);
                break;

            case 5:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
