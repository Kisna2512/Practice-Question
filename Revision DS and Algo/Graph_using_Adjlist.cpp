#include <iostream>

using namespace std;

class Node
{
public:
   
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
} * head[10];

void insertAdj(Node *head,  int dest)
{
    // Node *temp = new Node(soure);
    // Node *temp1 = new Node(dest);
    // // Node *head = new Node[10];
    // if (head[0] == NULL)
    // {
    //     // temp = new Node(soure);
    //     head[0]->data = temp->data;
    //     head[0]->next = temp1;
    // }

    // Node *temp3 = Gl;
    // int i = 1;
    // while (i < 10)
    // {
    //     head[i]->data = temp->data;
    //     head[i]->next = temp1;
    // }

    if(head==NULL)
    {
        head->data=dest;
    }

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* dummy=new Node(dest);
    temp->next=dummy;


}

void printAdj()
{
  
    for (int i = 0; i < 5; i++)
    {
          Node* dummy=head[i];
        while (dummy != NULL)
        {
            cout << dummy->data << "->" << dummy->next->data << " " << endl;
        }
        // cout << head[i]->data << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cout << "Hello world" << endl;

  

    for (int i = 0; i < 5; i++)
    {
        int src, des;
        cout << "Enter the source and destination:- " << endl;
        cin >> des;

        insertAdj(head[i], des);
    }

    printAdj();

    return 0;
}
