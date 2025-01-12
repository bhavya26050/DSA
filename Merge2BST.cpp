#include<iostream>
#include<vector>
#include<queue>
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

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
        root->right = insertIntoBST(root->right, d);
    else
        root->left = insertIntoBST(root->left, d);

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorder(Node* root , vector<int> &in)
{
    if(root == NULL)
        return;
    inorder(root -> left , in);
    in.push_back(root -> data);
    inorder(root -> right , in);
}

vector<int> mergeArray(vector<int> &a , vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0 , j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }
    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
    
    return ans;
}

Node* inorderTobst(int s , int e , vector<int> &in)
{
    //base case
    if(s>e)
        return NULL;

    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root -> left = inorderTobst(s , mid - 1 , in);
    root -> right = inorderTobst(mid + 1 , e , in);
    return root;
}

Node* mergeBST(Node* root1 , Node* root2)
{
    //step 1:
    vector<int> bst1 , bst2;
    inorder(root1 , bst1);
    inorder(root2 , bst2);

    vector<int>mergearray = mergeArray(bst1 , bst2);

    int s = 0 , e = mergearray.size() - 1;
    return inorderTobst(s , e , mergearray);

}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        
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

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;
    cout << "Enter data to create BST1 (-1 to stop):" << endl;
    takeInput(root1);
    cout << "Enter data to create BST2 (-1 to stop):" << endl;
    takeInput(root2);
    Node* mergedRoot = mergeBST(root1, root2);
    cout<<"Merged Array is : "<<endl;
    //Level Order Traversal
    levelOrderTraversal(mergedRoot);



    return 0;

}