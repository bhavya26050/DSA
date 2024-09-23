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

Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast)
        {
            cout<<"present at"<<slow -> data<<endl;
            return slow;
        }
    }
    return NULL ;
    
}

Node* getStartingNode(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while (slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
    
}

void RemoveLoop(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    Node* startofLoop = getStartingNode(head);
    Node* temp = startofLoop;

    while (temp -> next != startofLoop)
    {
        temp = temp -> next;
    }

    temp -> next = NULL;
    
    
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
    head->next->next->next->next->next = head->next;
     cout << "Given Linked list: ";
    // PrintList(head);
    if(floydDetectLoop(head) != NULL){
        cout<<"Cycle is present "<<endl;
    }
    else
    {
        cout<<"Cycle is not present "<<endl;
    }
    Node* loop = getStartingNode(head);

    cout<<"Starting Node Of LL is "<<loop -> data<<endl;


    RemoveLoop(head);
    PrintList(head);

}