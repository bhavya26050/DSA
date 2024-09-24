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

Node* RemoveDuplicateLLUnsorted(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* curr = head;
    while (curr != NULL)
    {
       Node* temp = curr -> next;
       Node* prev = curr;

       while (temp != NULL)
       {
            if(curr -> data == temp -> data)
            {
                prev -> next = temp -> next;
                delete(temp);
                temp = prev -> next;
            }
            else
            {
                prev = temp;
                temp = temp -> next;
            }
       }
       curr = curr -> next;
       
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
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(3);

    cout << "Given Linked list:";
    PrintList(head);

    head = RemoveDuplicateLLUnsorted(head);

    cout << "\nRemove duplicate from Unsorted Linked List:";
    PrintList(head);

    return 0;
}