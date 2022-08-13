#include <iostream>

using namespace std;

// Linked list code

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
    Node *head = NULL;

public:
    List()
    {
        head = NULL;
    }
    void insertAtfront(int val)
    {
        if (head == NULL)
        {
            Node *n = new Node(val);
            head = n;
            return;
        }

        Node *n = new Node(val);
        n->next = head;
        head = n;
    }

    void inserAtback(int val)
    {
        if (head == NULL)
        {
            Node *n = new Node(val);
            head = n;
            return;
        }
        Node *n = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
    }

    void insertAtindex(int idx, int val)
    {
        if (head == NULL)
        {
            Node *n = new Node(val);
            head = n;
            return;
        }

        Node *n = new Node(val);
        int i = 0;
        Node *temp = head;
        while (temp->next != NULL && i < idx - 1)
        {
            temp = temp->next;
            i++;
        }
        n->next = temp->next;
        temp->next = n;
    }

    void deleteAtFront()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtBack()
    {
        if (head == NULL)
        {
            cout << "Your List is empty: " << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void
    printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
};

int main()
{
    List l;
    List l1;

    l.insertAtfront(5);
    l.insertAtfront(6);
    l.insertAtfront(7);
    l.inserAtback(3);
    l.insertAtindex(2, 59);
    l.deleteAtFront();
    l.insertAtfront(34);
    l.deleteAtBack();
    l.printList();
    l1.insertAtfront(12);
    l1.insertAtfront(13);
    l1.insertAtfront(14);
    l1.insertAtfront(15);
    l1.printList();

    return 0;
}
