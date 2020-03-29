#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
    }
};

class Linkedlist{
    Node *head;
    public:
        void display()
        {
           
            if(head == NULL)
            {
                return;
            }
            Node* temp = head;

            while (temp)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void insertionAtEnd(int element)
        {
            if(head == NULL)
            {
                head = new Node(element);
                return;
            }
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            } 
            Node* newNode = new Node(element);
            temp->next = newNode;                
            
        }



};




int main()
{
    Linkedlist myList1;
    Linkedlist myList2;

    myList1.insertionAtEnd(5);
    myList2.insertionAtEnd(7);

    //myList1.display();
    //myList2.display();



    return 0;
}