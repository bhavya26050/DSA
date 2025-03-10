#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

    node(int d) 
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;

    }
};

node* buildTree(node* root)
{
    cout<<"Enter the data for Node : ";
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter data for left child of "<<data<<" : "<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter data for right child of "<<data<<" : "<<endl;
    root -> right = buildTree(root -> right);
    return root;

}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp = q.front();
        
        q.pop();

        if(temp == NULL) //old level is complete
        {
            cout<<endl;
            if(!q.empty())//queue still has some elements
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data<<" ";
            if(temp -> left != NULL)
            {
                q.push(temp -> left);
            }
            if(temp -> right != NULL)
            {
                q.push(temp -> right);
            }
        }
    
    }
}

void Preorder(node* root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }
    cout<<root -> data<<" ";
    Preorder(root -> left);
    Preorder(root -> right);
}

int main()
{
    node* root = NULL;

    //Creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //Level Order Traversal
    cout<<"Printing the level order traversal of the tree : "<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal : ";
    Preorder(root);
}