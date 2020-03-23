#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

int lengthLL(node * head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
    
}

void InsertAtEnd(node * &head,node * &tail,int data)
{
    if(head == NULL)
    {
        head = tail = new node(data);
    }
    else
    {
        node *temp = new node(data);
        tail ->next = temp;
        tail = temp;
    }
    
}


void InsertAtFront(node * &head,node * &tail,int data)
{
    node *temp = new node(data);
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    
}

void InsertionAtPos(node * &head,node * &tail,int pos,int data)
{
    if(pos == 0)
    {
        InsertAtFront(head,tail,data);
    }
    else if(pos >= lengthLL(head))
    {
        InsertAtEnd(head,tail,data);
    }
    else
    {
        node *temp = head;
        int count = 1;
        while(count <= pos - 1)
        {
            temp = temp->next;
            count++;
        }
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;

    }
    
    
}

void displayLL(node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}


void deleteFromFront(node* &head , node* &tail)
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete(head);
        head = tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete(temp);

    }
    
}

void deleteFromEnd(node * &head ,node * &tail)
{
    if(head == NULL)
    {
        return;
    }

    else if(head->next == NULL)
    {
        delete(head);
        head = tail = NULL;
    }
    else
    {
        node *temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        temp->next = NULL;

    }
    


}

void deleteFromPosition(node * &head, node * &tail,int pos)
{
    if(pos == 0)
    {
        deleteFromFront(head,tail);
    }
    else if(pos >= (lengthLL(head) - 1))
    {
        deleteFromEnd(head,tail);
    }
    else
    {
        node *temp = head;
        int count = 1;
        while(count <= pos-1)
        {
            temp = temp->next;
            count++;
        }
        node *n = temp->next;
        temp->next = n->next;
        delete n;


    }
    
}

node *searchNode(node * head,int key)
{
    while (head)
    {
        if(head->data == key)
        {
            return head;
        }
        head = head->next;
    }
    return NULL; 
}


node *recursiveSearch(node * head,int key)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->data == key)
    {
        return head;
    }
    return recursiveSearch(head->next,key);
}


void reversal(node * &head,node * &tail)
{
    node *p = NULL;
    node *c = head;
    while(c)
    {
        node *n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    tail = head;
    head = p;
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    InsertAtFront(head,tail,5);
    InsertAtFront(head,tail,4);
    InsertAtFront(head,tail,3);
    InsertAtFront(head,tail,2);
    InsertAtFront(head,tail,1);

    displayLL(head);

    InsertAtEnd(head,tail,6);
    InsertAtEnd(head,tail,7);
    InsertAtEnd(head,tail,8);
    InsertAtEnd(head,tail,10);

    displayLL(head);

    InsertionAtPos(head,tail,0,0);
    InsertionAtPos(head,tail,9,9);

    displayLL(head);

    deleteFromFront(head,tail);

    displayLL(head);

    deleteFromEnd(head,tail);

    displayLL(head);

    deleteFromPosition(head,tail,4);

    displayLL(head);

    if(searchNode(head,9)== NULL)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Node found"<<endl;
    }

    if(recursiveSearch(head,7)== NULL)
    {
        cout<<"Not found"<<endl;
    }
    else
    {
        cout<<"Node found"<<endl;
    }

    reversal(head,tail);

    displayLL(head);

    return 0;
}