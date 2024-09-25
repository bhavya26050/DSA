#include<iostream>
#include<vector>
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

bool checkPalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while (s <= e)
    {
        if (arr[s] == arr[e])
        {
            return 1;
            s++;
            e--;
        }
        else
        {
            return 0;
        }
        
    }
    return 1;
    
}

bool isPalindrome(Node* head)
{
    vector<int>arr;
    Node* temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    return checkPalindrome(arr);
    
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
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    cout << "Given Linked list:";
    PrintList(head);
    if(isPalindrome(head))
    cout << "\nGiven Linked list is a palindrome.";
    else
    {
        cout<<"\nLinked list is not palindrome ";
    }
    
    return 0;
}