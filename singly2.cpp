#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* HEAD = NULL;
void insrtAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = HEAD;
    HEAD = newNode;
    cout << "Node with value " << value << " inserted at the beginning.\n";
}
