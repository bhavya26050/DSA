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

bool SearchInBST(Node* root , int x)
{
    // //base case
    // if(root == NULL)
    // {
    //     return false;
    // }
    // if(root -> data == x)
    // {
    //     return true;
    // }
    // if(root -> data > x)
    // {
    //     return SearchInBST(root -> left , x);
    // }
    // else
    // {
    //     return SearchInBST(root -> right , x);
    // }

    Node* temp = root;
    while (temp != NULL)
    {
        if(temp -> data == x)
            return true;
        if(temp -> data > x)
            temp  = temp -> left;
        else
            temp = temp -> right;
    }
    return false;
}

Node* minVal(Node* root)
{
    Node* temp = root;

    while (temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node* temp = root;

    while (temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
}

Node* deleteFromBST(Node* root , int val)
{
    //base case
    if(root == NULL)
        return root;

    if(root -> data == val)
    {
        //0 child 
        if (root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left;
            delete root;
            return temp; 
        }
        //right child
        if(root -> left == NULL && root -> right != NULL)
        {
            Node* temp = root -> right;
            delete root;
            return temp; 
        }

        //2 child
        if(root -> left != NULL && root -> right != NULL)
        {
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right , mini);
            return root;
        }

    }
    else if(root -> data > val)
    {
        root -> left = deleteFromBST(root -> left , val);
        return root;
    }
    else
    {
        root -> right = deleteFromBST(root -> right , val);
        return root;
    }
    
}

int main()
{
    Node* root = NULL;
    int x;
    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    cout<<"Enter the node u want to search : ";
    cin>>x;

    if(SearchInBST(root , x))
        cout<<"Node found"<<endl;
    else
        cout<<"Node not found"<<endl;

    cout<<"Minimum value : "<<minVal(root) -> data<<endl;

    cout<<"Maximum value : "<<maxVal(root) -> data;

    return 0;

}