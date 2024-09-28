#include <iostream>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertattail(Node*& head, Node*& tail, int d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* CloneLL(Node* head) {
    Node* clonehead = NULL;
    Node* clonetail = NULL;

    Node* temp = head;

    // Step 1: Create a clone list using the same data
    while (temp != NULL) {
        insertattail(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    // Step 2: Create a mapping between original and clone nodes
    map<Node*, Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = clonehead;
    while (originalNode != NULL && cloneNode != NULL) {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // Step 3: Adjust random pointers in the cloned list
    originalNode = head;
    cloneNode = clonehead;

    while (originalNode != NULL) {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return clonehead;
}

void PrintList(Node* node) {
    cout << "Normal LL: ";
    Node* temp = node;
    while (temp != NULL) {
        cout << " " << temp->data;
        temp = temp->next;
    }
    cout << endl;

    cout << "Random LL: ";
    temp = node;
    while (temp != NULL) {
        // Print the data for random pointer
        cout << " " << (temp->random ? to_string(temp->random->data) : "NULL");
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Assign random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next;

    cout << "Given Linked list:" << endl;
    PrintList(head);

    Node* clonedHead = CloneLL(head);

    cout << "\nClone Linked List:" << endl;
    PrintList(clonedHead);

    return 0;
}
