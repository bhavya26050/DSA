#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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

int solve(Node* root, int &i, int k) {
    // Base case
    if (root == NULL)
        return -1;

    // Traverse left subtree
    int left = solve(root->left, i, k);
    if (left != -1)
        return left;

    // Increment counter
    i++;
    if (i == k)
        return root->data;

    // Traverse right subtree
    return solve(root->right, i, k);
}

int Kthsmallest(Node* root, int k) {
    int i = 0;
    int ans = solve(root, i, k);
    if (ans == -1)
        cout << "Invalid value of k." << endl;
    return ans;
}

int main() {
    Node* root = NULL;
    cout << "Enter data to create BST (-1 to stop):" << endl;
    takeInput(root);

    int k;
    cout << "Enter the value of k:" << endl;
    cin >> k;

    int result = Kthsmallest(root, k);
    if (result != -1)
        cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
