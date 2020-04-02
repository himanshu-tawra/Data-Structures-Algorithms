//input - 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
/* output
    Inorder 
    1 10 9 6 7 8 3 13 14 
    Post order
    1 9 7 6 10 13 14 3 8 
*/

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

void printInorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

void printPostOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}


int main()
{   
    Node* root = buildTree();
    
    cout<<"Inorder "<<endl;
    printInorder(root);

    cout<<endl;
    cout<<"Post order"<<endl;
    printPostOrder(root);


    return 0;
}