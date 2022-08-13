#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist
{
public:
    Node *head;

    Linkedlist() { head = NULL; }

    void insertNode(int data)
    {
        Node *n = new Node(data);

        if (head == NULL)
        {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void printList()
    {

        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }

    void insertatFirst(int data)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }

    void insertatmiddle(int data, int idx)
    {
        Node *n = new Node(data);
        Node *temp = head;
        int i = 1;
        while (temp != NULL and i < idx)
        {
            temp = temp->next;
            i++;
        }
        n->next = temp->next;
        temp->next = n;
    }

    // Node* deleteAtstart(Node *head)
    // {
    //     // head = head->next;
    //    if(head==NULL)
    //    {
    //        return NULL;
    //    }
    //    Node* temp=head;
    //    head=head->next;

    //    delete temp;
    //    return head;
    // }

    void deleteAtindex(Node *head, int idx)
    {
        Node *temp = head;
        int i = 1;
        while (i < idx)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }

    void deleteAtend(Node *head, int lidx)
    {
        Node *temp = head;
        int i = 1;
        while (i < lidx)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }

    void reverseSL()
    {
        Node *temp = head;
        Node *n = NULL;
        Node *prev = NULL;

        while (temp != NULL)
        {

            n = temp->next;
            temp->next = prev;
            prev = temp;
            temp = n;
        }
        head = prev;
    }
};

int main()
{
    Linkedlist list;

    for (int i = 0; i < 5; i++)
    {
        int val;
        cout << "Enter the data which you want to insert:- " << endl;
        cin >> val;
        list.insertNode(val);
    }

    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    Node *head = NULL;
    cout << "Elements of the list are: ";
    // list.insertatFirst(67);
    cout << endl;
    // list.deleteAtstart(list.head);
    // list.deleteAtend(list.head, 4);
    list.reverseSL();
    list.printList();
    cout << endl;
    return 0;
}
