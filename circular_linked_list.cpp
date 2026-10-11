#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string name;
    Node* next;
};
Node* last = NULL;
Node* current = NULL;
void addMember(string name)
{
    Node* newNode = new Node;
    newNode->name = name;
    if (last == NULL)
    {
        last = newNode;
        newNode->next = newNode;
        current = newNode;
        cout << "Member added.\n";
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    cout << "Member added.\n";
}

// Remove member
void removeMember(string name)
{
    if (last == NULL)
    {
        cout << "Rotation is empty.\n";
        return;
    }

    Node* currentNode = last->next;
    Node* previous = last;

    do
    {
        if (currentNode->name == name)
        {
            if (currentNode == last && currentNode->next == last)
            {
                delete currentNode;
                last = NULL;
                current = NULL;

                cout << "Member removed.\n";
                return;
            }
            if (currentNode == last)
            {
                previous->next = currentNode->next;
                last = previous;
            }
            else
            {
                previous->next = currentNode->next;
            }
            if (current == currentNode)
                current = currentNode->next;

            delete currentNode;
            cout << "Member removed.\n";
            return;
        }
        previous = currentNode;
        currentNode = currentNode->next;
    } while (currentNode != last->next);
    cout << "Member not found.\n";
}
void searchMember(string name)
{
    if (last == NULL)
    {
        cout << "Rotation is empty.\n";
        return;
    }
    Node* temp = last->next;
    do
    {
        if (temp->name == name)
        {
            cout << "Member found: " << name << endl;
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
    cout << "Member not found.\n";
}
void displayRotation()
{
    if (last == NULL)
    {
        cout << "Driving Rotation is empty.\n";
        return;
    }
    Node* temp = last->next;
    cout << "\nCurrent Driving Rotation:\n";
    do
    {
        cout << temp->name;
        temp = temp->next;
        if (temp != last->next)
            cout << " -> ";
    } while (temp != last->next);
    cout << " -> back to " << last->next->name << endl;
}
void assignNextDriver()
{
    if (current == NULL)
    {
        cout << "No driver available. Rotation is empty.\n";
        return;
    }
    cout << "Current Driver: " << current->name << endl;
    current = current->next;
    cout << "Next Driver: " << current->name << endl;
}
int main()
{
    int choice;
    string name;

    do
    {
        cout << "\n===== CIRCULAR LINKED LIST =====\n";
        cout << "1. Add Member\n";
        cout << "2. Remove Member\n";
        cout << "3. Search Member\n";
        cout << "4. Display Driving Rotation\n";
        cout << "5. Assign Next Driver\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter member name: ";
            cin >> name;
            addMember(name);
            break;
        case 2:
            cout << "Enter member name to remove: ";
            cin >> name;
            removeMember(name);
            break;
        case 3:
            cout << "Enter member name to search: ";
            cin >> name;
            searchMember(name);
            break;
        case 4:
            displayRotation();
            break;
        case 5:
            assignNextDriver();
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}