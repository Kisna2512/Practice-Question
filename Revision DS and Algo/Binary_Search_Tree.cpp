#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{

public:
    Node *inputBST(Node *root, int data)
    {

        if (root == NULL)
        {
            return new Node(data);
        }

        if (data > root->data)
        {
            root->right = inputBST(root->right, data);
            cout << "\nIt will go in right of:-  " << root->data << endl;
        }
        else
        {
            root->left = inputBST(root->left, data);
            cout << "\n It will go in left of:- " << root->data << endl;
        }
        return root;
    }

    bool searchInBST(Node *root, int data)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }

        if (root->data > data)
        {
            return searchInBST(root->left, data);
        }

        return searchInBST(root->right, data);
    }

    Node *findMIN(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *DeletionBST(Node *root, int data)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data < data)
        {
            root->right = DeletionBST(root->right, data);
        }
        else if (root->data > data)
        {
            root->left = DeletionBST(root->left, data);
        }
        else
        {
            // No child
            if (root->left == NULL and root->right == NULL)
            {
                return NULL;
            }

            // one child right
            else if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // one child left

            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // If two child

            else
            {
                Node *temp = findMIN(root->right);
                root->data = temp->data;
                root->right = DeletionBST(root->right, temp->data);
            }
        }
        return root;
    }

    void printBST(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printBST(root->left);
        cout << root->data << endl;
        printBST(root->right);
    }
};

int main()
{
    BST bt;
    Node *node = NULL;
    int n;
    cout << "\nEnter How many Nodes you want to insert in Binary Search Tree:- " << endl;
    cin >> n;
    while (n--)
    {
        int data;
        cout << "Enter the value of data:- " << endl;
        cin >> data;
        node = bt.inputBST(node, data);
    }

    cout << "\nThe Binary search Tree in Incresing order(Inorder) :- " << endl;
    bt.printBST(node);

    int ele;
    cout << "\nEnter the elements you want to search in BST:- " << endl;
    cin >> ele;

    if (bt.searchInBST(node, ele))
    {
        cout << "\nYour Elements is present in Binary search Tree" << endl;
    }
    else
    {
        cout << "\n Your Element is not present In Binary Search Tree" << endl;
    }

    int x;
    cout << "\n Enter the element you want to delete in BST:-" << endl;
    cin >> x;

    node = bt.DeletionBST(node, x);

    cout << "\nAfter deleting node in BST is:- " << endl;
    bt.printBST(node);

    return 0;
}