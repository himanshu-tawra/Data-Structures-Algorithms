#include<iostream>
#include "userDefinedStack.h"

using namespace std;

int main()
{
    Stack <int> s;
    
    int choice;
    while(1)
    {
        cout<<"<-------------Stack using vector------------->"<<
        endl<<"Enter your choice"<<endl<<"1.Push" <<endl<<"2.Pop"<<endl
        <<"3.Top"<<endl<<"4.Display stack"<<endl
        <<"5.Exit"<<endl;

        cin>>choice;
        int element;
        switch (choice)
        {
        case 1:
            cout<<"Enter the element"<<endl;
            cin>>element;
            s.push(element);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.top();
            break;

        case 4:
            s.display();
            break;

        case 5:
            exit(0);
            break;


        default:
            cout<<"Enter valid choice"<<endl;
            break;
        }
    }
    return 0;
}