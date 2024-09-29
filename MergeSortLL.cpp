#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* findmid(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* merge(Node* left, Node* right)
{
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != NULL && right != NULL)
    {
        if(left -> data < right -> data)
        {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while (left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    while (right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;

    return ans;
    
}

Node* mergeSort(Node* head)
{
    //base case
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }

    //break LL into 2 halfs.
    Node* mid = findmid(head);

    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    //recursive calls to sort both half
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both half
    Node* result = merge(left , right);


    return result;

    
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
    Node* head = new Node(9);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(0);
    cout << "Given Linked list:";
    PrintList(head);

    head = mergeSort(head);
    cout<<"\nSorted Linked List:";
    PrintList(head);
}