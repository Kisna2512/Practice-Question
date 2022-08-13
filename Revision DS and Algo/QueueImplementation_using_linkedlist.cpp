#include <iostream>

using namespace std;

// Queue implmentation using linked list
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

class Queue
{
    Node *head = NULL;

public:
    Queue()
    {
        head = NULL;
    }

    void push(int ele)
    {
        Node *n = new Node(ele);
        if (head == NULL)
        {
            n->next = head;
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

    void pop()
    {
        if (head != NULL)
        {
            head = head->next;
        }
        else
        {
            cout << "Queue is underflow" << endl;
        }
    }

    int front()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        return (head->data);
    }

    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int rear()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return (temp->data);
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    Queue q;
    q.push(6);
    q.push(4);
    q.push(5);
    q.push(7);
    q.push(8);

    q.pop();
    cout << "Front:- " << q.front() << endl;
    cout << "Rear:- " << q.rear() << endl;
    // q.display();
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}