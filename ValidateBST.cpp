#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root , int d)
{
    //base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if(d > root -> data)
    {
        root -> right = insertIntoBST(root -> right , d); 
    }
    else
    {
        root -> left = insertIntoBST(root -> left , d);
    }
    return root;
    
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while (data != -1)
    {
        root = insertIntoBST(root , data);
        cin>>data;

    }
    
}


bool isBST(Node* root , int min , int max)
{
    //base case
    if(root == NULL)
        return true;
    if(root -> data > min && root -> data < max)
    {
        bool left = isBST(root -> left , min , root -> data);
        bool right = isBST(root -> left , root -> data , max);
        return left && right;
    }
    else
    {
        return false;
    }
    
}

bool validateBST(Node* root)
{
    return isBST(root , INT_MIN , INT_MAX);
}

int main()
{
    Node* root = NULL;
    int x;
    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    

    if (validateBST(root))
    {
        cout<<"True BST ";
    }
    else
        cout<<"not BST";
    
    return 0;

}