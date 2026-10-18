
#include <iostream>
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

Node* insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        cout << "Duplicate value not allowed\n";
    }

    return root;
}

void search(Node *root, int value)
{
    if (root == NULL)
    {
        cout << "Node not found\n";
        return;
    }

    if (root->data == value)
    {
        cout << "Node found\n";
    }
    else if (value < root->data)
    {
        search(root->left, value);
    }
    else
    {
        search(root->right, value);
    }
}

Node* findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        cout << "Node not found\n";
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            cout << "Node deleted successfully\n";
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            cout << "Node deleted successfully\n";
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    int choice, value;

    do
    {
        cout << "\n--- BINARY SEARCH TREE ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input\n";
            break;
        }

        switch (choice)
        {
            case 1:
                cout << "Enter value to insert: ";
                if (cin >> value)
                {
                    root = insert(root, value);
                }
                else
                {
                    cout << "Invalid input\n";
                    return 0;
                }
                break;

            case 2:
                cout << "Enter value to search: ";
                if (cin >> value)
                {
                    search(root, value);
                }
                else
                {
                    cout << "Invalid input\n";
                    return 0;
                }
                break;

            case 3:
                cout << "Enter value to delete: ";
                if (cin >> value)
                {
                    if (root == NULL)
                    {
                        cout << "Tree is empty\n";
                    }
                    else
                    {
                        root = deleteNode(root, value);
                    }
                }
                else
                {
                    cout << "Invalid input\n";
                    return 0;
                }
                break;

            case 4:
                if (root == NULL)
                    cout << "Tree is empty\n";
                else
                {
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;
                }
                break;

            case 5:
                if (root == NULL)
                    cout << "Tree is empty\n";
                else
                {
                    cout << "Preorder: ";
                    preorder(root);
                    cout << endl;
                }
                break;

            case 6:
                if (root == NULL)
                    cout << "Tree is empty\n";
                else
                {
                    cout << "Postorder: ";
                    postorder(root);
                    cout << endl;
                }
                break;

            case 7:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}
