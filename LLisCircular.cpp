#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;

}

bool detectLoop(Node* head)
{
    if(head == NULL)
    {
        return false;
    }
    map<Node*, bool>visited;

    Node* temp = head;
    while (temp != NULL)
    {
        if(visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
    
}

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

int main()
{
    if(isCircularList(tail)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }

    return 0;
}