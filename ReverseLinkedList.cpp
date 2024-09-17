#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this ->data = data;
        this ->next = NULL;
    }
};

Node* reverselist(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
    
}
void PrintList(Node* node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
    
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked list:";
    PrintList(head);

    head = reverselist(head);

    cout << "\nReversed Linked List:";
    PrintList(head);

    return 0;
}