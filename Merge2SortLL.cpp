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

Node* solve(Node* first , Node* second)
{
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1->data))
        {
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL)
            {
                curr1 -> next = curr2;
                return first;
            }   
        }
    }
    return first;
    
}

Node* Sort2Linkedlist(Node* first , Node* second)
{
    if(first == NULL)
    {
        return second;
    }
    if(second == NULL)
    {
        return first;
    }
    if (first -> data <= second -> data)
    {
        return solve(first , second);
    }
    else
    {
        return solve(second , first);
    }
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
    head->next = new Node(3);
    head->next->next = new Node(5);
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(5);
    cout << "Given Linked list:";
    PrintList(head);
    cout<<"  ";
    PrintList(head1);

    head = Sort2Linkedlist(head , head1);

    cout << "\nSorted Linked List:";
    PrintList(head);

}