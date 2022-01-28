#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next = NULL; // every next node will auto assign NULL value
};

void input(Node *&head)
{
    int value;
    Node *cur = head;
    while(cin >> value)
    {
        if(head == NULL) // if head is null create the linked list
        {
            head = new Node;
            cur = head;
        }
        else
        {
            cur -> next = new Node;
            cur = cur -> next;
        }
        cur -> val = value;
    }
}

void delDup(Node *&head)
{
    if(head == NULL)
        return;
    Node *p = head;
    if(p -> next == NULL) // if there is only 1 element
        return;

    while(p -> next != NULL) // while the next element is not NULL
    {
        if(p -> val == p -> next -> val) // check if the current value equal to the next value
        {
            Node *temp = p -> next; // temp equal to the next value
            p -> next = temp -> next; // assign the next of the next value to the current value, if it not exist p -> next will equal to NULL
            delete temp;
        }
        else // if delete the next value, no need to p to go to the next value
            p = p -> next;
    }
}

void display(Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        cout << p -> val << " ";
        p = p -> next;
    }
    cout << endl;
}


int main()
{
    freopen("input.txt","r",stdin);
    Node *head = NULL;
    input(head);
    cout << "The linked list elements: ";
    display(head);
    delDup(head);
    cout << "The linked list elements after delete duplicate: ";
    display(head);
    delete head;
}
