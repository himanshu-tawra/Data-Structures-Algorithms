//input - 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1 
//output - 8 3 1 6 4 7 10 14 13

#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree()
{
    int d;
    cin>>d;

    if(d == -1)
    {
        return NULL;
    }

    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;

}

void print(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}



int main()
{   
    Node* root = buildTree();
    print(root);


    return 0;
}