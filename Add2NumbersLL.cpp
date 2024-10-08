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

Node* reverseLL(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAttail(Node* &head , Node* &tail , int val )
{
    Node* temp = new Node(val);
    if(head == NULL)
    {
        //empty list case
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
    
}
//one solution
// Node* add(Node* first , Node* second)
// {
//     int carry = 0;
//     Node* anshead = NULL;
//     Node* anstail = NULL;

//     while (first != NULL && second != NULL)
//     {
//         int sum = carry + first -> data + second -> data;
//         int digit = sum % 10;
//         insertAttail(anshead , anstail , digit);
//         carry = sum/10;

//         first = first -> next;
//         second = second -> next;
//     }

//     while (first != NULL)
//     {
//         int sum = carry + first -> data ;
//         int digit = sum % 10;
//         insertAttail(anshead , anstail , digit);
//         carry = sum/10;

//         first = first -> next;
//     }
//     while (second != NULL)
//     {
//         int sum = carry + first -> data ;
//         int digit = sum % 10;
//         insertAttail(anshead , anstail , digit);
//         carry = sum/10;

//         second = second -> next;
//     }
//     while (carry != 0)
//     {
//         int sum = carry;
//         int digit = sum % 10;
//         insertAttail(anshead , anstail , digit);
//         carry = sum/10;
//     }
//     return anshead;
// }

//second solution
Node* add(Node* first , Node* second)
{
    int carry = 0;
    Node* anshead = NULL;
    Node* anstail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if(first != NULL)
        {
            val1 = first -> data; 
        }
        int val2 = 0;
        if(second != NULL)
        {
            val2 = second -> data; 
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertAttail(anshead , anstail , digit);
        carry = sum/10;


        if(first !=NULL)
        {
            first = first -> next;
        }
        if(second != NULL)
        {
            second = second -> next;
        }
    }
    return anshead;
}



Node* Addnumbers(Node* first , Node* second)
{
    // reverse input
    first = reverseLL(first);
    second = reverseLL(second);

    // add 2 LL
    Node* ans = add(first,second);

    ans = reverseLL(ans);

    return ans;
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

    head = Addnumbers(head , head1);

    cout << "\nSorted Linked List:";
    PrintList(head);

}