#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* LLReverseKorder(Node* head , int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    //step 1 : reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step 2 : Recursion will see
    if(next != NULL)
    {
        head -> next = LLReverseKorder(next , k);
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
    int k = 3;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Given Linked list:";
    PrintList(head);

    head = LLReverseKorder(head , k);

    cout << "\nReversed Linked List:";
    PrintList(head);

    return 0;
} 