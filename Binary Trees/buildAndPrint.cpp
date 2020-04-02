/*
Program to build the given binary tree

                        8
                      /   \
                     3     10
                   /  \      \
                  1    6      14
                     /   \    /
                    4     7  13

input : 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

output :
Preorder : 8 3 1 6 4 7 10 14 13 
Inorder : 1 3 4 6 7 8 10 13 14 
Postorder : 1 4 7 6 3 13 14 10 8 
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


Node* createBinaryTree()
{
    int data;
    cin>>data;

    if(data == -1)
    {
        return NULL;
    }

    Node* root = new Node(data);
    root->left = createBinaryTree();
    root->right = createBinaryTree();

    return root;
}

void preOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

void inOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    Node* root = NULL;
    
    root = createBinaryTree();

    cout<<"Pre order: "<<endl;
    preOrder(root);
    cout<<endl;

    cout<<"In order: "<<endl;
    inOrder(root);
    cout<<endl;

    cout<<"Post order: "<<endl;
    postOrder(root);
    cout<<endl;

    return 0;



}