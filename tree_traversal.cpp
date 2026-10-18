
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root, *a, *b, *c, *d, *e, *f;
    int choice;

    root = NULL;

    cout << "TREE TRAVERSAL\n";
    cout << "1. Create Tree\n";
    cout << "2. Display Traversals\n";
    cout << "3. Empty Tree Test\n";
    cout << "4. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input!";
            break;
        }

        if (choice == 1)
        {
            int x, y, z, p, q, r, s;

            cout << "Enter root value: ";
            cin >> x;
            cout << "Enter left child of root: ";
            cin >> y;
            cout << "Enter right child of root: ";
            cin >> z;
            cout << "Enter left child of left node: ";
            cin >> p;
            cout << "Enter right child of left node: ";
            cin >> q;
            cout << "Enter left child of right node: ";
            cin >> r;
            cout << "Enter right child of right node: ";
            cin >> s;

            root = createNode(x);
            a = createNode(y);
            b = createNode(z);
            c = createNode(p);
            d = createNode(q);
            e = createNode(r);
            f = createNode(s);

            root->left = a;
            root->right = b;
            a->left = c;
            a->right = d;
            b->left = e;
            b->right = f;

            cout << "Tree created successfully.\n";
        }
        else if (choice == 2)
        {
            if (root == NULL)
            {
                cout << "Tree is empty.\n";
            }
            else
            {
                cout << "Inorder: ";
                inorder(root);

                cout << "\nPreorder: ";
                preorder(root);

                cout << "\nPostorder: ";
                postorder(root);

                cout << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Inorder: ";
            inorder(NULL);

            cout << "\nPreorder: ";
            preorder(NULL);

            cout << "\nPostorder: ";
            postorder(NULL);

            cout << "\nEmpty tree traversal completed.\n";
        }
        else if (choice == 4)
        {
            cout << "Exiting program.\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
