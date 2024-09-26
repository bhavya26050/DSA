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

Node* SortLinkedlist(Node* head)
{
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;

    Node* temp = head;
    while (temp != NULL)
    {
        if(temp -> data == 0)
        {
            zerocount++;
        }
        else if (temp -> data == 1)
        {
            onecount++;
        }
        else if (temp -> data == 2)
        {
            twocount++;
        }
        temp = temp -> next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (zerocount != 0)
        {
            temp -> data = 0;
            zerocount--;
        }
        else if (onecount != 0)
        {
            temp -> data = 1;
            onecount--;
        }
        else if (twocount != 0)
        {
            temp -> data = 2;
            twocount--;
        }
        temp = temp -> next;
    }

    return head;
    
}

void PrintList(Node* node)
{
    while (node != NULL)
    {
        cout<<" "<<node -> data;
        node = node -> next;
    }
    
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    cout << "Given Linked list:";
    PrintList(head);

    head = SortLinkedlist(head);

    cout << "\nSorted Linked List:";
    PrintList(head);

}