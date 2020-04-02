/*
Program to calculate the height of the binary tree

                        8
                      /   \
                     3     10
                   /  \      \
                  1    6      14
                     /   \    /
                    4     7  13

input : 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

output : Height of the tree : 4
Preorder : 8 3 1 6 4 7 10 14 13 

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


int heightOfTree(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight,rightHeight) + 1;
}


int main()
{
    Node* root = NULL;
    
    root = createBinaryTree();

    cout<<"Height of the tree : "<<heightOfTree(root)<<endl;

    cout<<"Pre order: "<<endl;
    preOrder(root);
    
    

    return 0;



}