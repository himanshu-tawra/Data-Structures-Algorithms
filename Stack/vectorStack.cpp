#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack
{
    vector <T> v;
    public:
        void push(T d);
        void pop();
        T top();
        bool isEmpty();
        void displayStack();
};


template<class T>
void Stack<T> :: push(T d)
{
    v.push_back(d);
}

template<class T>
void Stack<T> :: pop()
{
    v.pop_back();
}

template<class T>
T Stack<T> :: top()
{
    return v[v.size() - 1];
}


template<class T>
bool Stack<T> :: isEmpty()
{
    return v.size() == 0;
}

template<class T>
void Stack<T> :: displayStack()
{
    T i = v.size()-1;
    while(i >= 0)
    {
        cout<<v[i]<<" ";
        i--;
    }
    cout<<endl;
}

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
            cout<<s.top()<<endl;
            break;

        case 4:
            s.displayStack();
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