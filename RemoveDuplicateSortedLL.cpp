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

Node* RemoveDuplicateLL(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head;
    while (curr != NULL)
    {
        if( (curr -> next != NULL)  && curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
            
        }
        else
        {
            curr = curr -> next;
        }
        
    }
    return head;

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
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked list:";
    PrintList(head);

    head = RemoveDuplicateLL(head);

    cout << "\nRemove duplicate from  Linked List:";
    PrintList(head);

    return 0;
}