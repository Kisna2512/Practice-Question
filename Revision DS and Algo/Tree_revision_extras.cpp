#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

// Node of a Tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // Constructor
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    // Tree input
    Node *inputTree()
    {
        int data;
        cout << "Enter the value of data and for NULL enter -1:- " << endl;
        cin >> data;
        Node *Proot;
        if (data == -1)
        {
            return NULL;
        }

        Proot = new Node(data);
        cout << "Enter the value for left node of :- " << Proot->data << endl;
        Proot->left = inputTree();
        cout << "Enter the value for right node:- " << Proot->data << endl;
        Proot->right = inputTree();
        return Proot;
    }
    // Recursive preorder
    void printTree(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
    // Recursive inorder
    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    // Recursive postorder
    void postOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    // Level order Traversal
    void LevelOrderTraversal(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }

    // Preorder iterative
    void PreOrderIterative(Node *root)
    {
        stack<Node *> st;
        Node *n = root;
        while (true)
        {
            if (n != NULL)
            {
                st.push(n);
                cout << n->data << " ";
                n = n->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }
                n = st.top();
                st.pop();
                n = n->right;
            }
        }
    }

    // Inorder iterative
    void InorderIterative(Node *root)
    {
        stack<Node *> st;
        Node *n = root;
        while (true)
        {
            if (n != NULL)
            {
                st.push(n);
                n = n->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }
                n = st.top();
                st.pop();
                cout << n->data << " ";
                n = n->right;
            }
        }
    }
    // PostOrder Iterative using two stacks:- TC:-O(N)+O(N)
    void PostOrderIterative(Node *root)
    {
        stack<Node *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();

            st2.push(root);

            if (root->left != NULL)
                st1.push(root->left);
            if (root->right != NULL)
                st1.push(root->right);
        }

        while (!st2.empty())
        {
            cout << st2.top()->data << " ";
            st2.pop();
        }
    }

    // Postorder Iterative One stack
    void PostorderIterOnestack(Node *node)
    {
        stack<Node *> s;

        unordered_map<Node *, int> vis;

        s.push(node);

        while (!s.empty())
        {

            vis[s.top()] = 1;

            if (s.top()->left != 0)
            {
                if (!vis[s.top()->left])
                {
                    s.push(s.top()->left);
                    continue;
                }
            }

            if (s.top()->right != 0)
            {
                if (!vis[s.top()->right])
                {
                    s.push(s.top()->right);
                    continue;
                }
            }

            cout << s.top()->data << " ";

            s.pop();
        }
    }



       












};

int main()
{
    BinaryTree t;
    Node *node = t.inputTree();
    cout << "\nThe tree is like this :- " << endl;
    t.printTree(node);
    cout << "\n The tree inorder is:- " << endl;
    t.inOrder(node);
    cout << "\nThe tree postorder is:- " << endl;
    t.postOrder(node);
    cout << "\nThe tree level order is:- " << endl;
    t.LevelOrderTraversal(node);
    cout << "\n The iterative preorder is :- " << endl;
    t.PreOrderIterative(node);
    cout << "\n The iterative inorder is :- " << endl;
    t.InorderIterative(node);
    cout << "\n The iterative postorder is :- " << endl;
    t.PostOrderIterative(node);
    cout << "\n The iterative postorder using one stack is :- " << endl;
    t.PostorderIterOnestack(node);
    

    return 0;
}