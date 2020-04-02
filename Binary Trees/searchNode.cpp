/*
Program to search a node int the binary tree .


                        8
                      /   \
                     3     10
                   /  \      \
                  1    6      14
                     /   \    /
                    4     7  13

->input : 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

->Preorder : 8 3 1 6 4 7 10 14 13 

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

Node* searchNode(Node* root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        return root;
    }

    Node* ans = searchNode(root->left,key);
    if(ans != NULL)
    {
        return ans;
    }

    return searchNode(root->right,key);
}

int main()
{
    Node* root = NULL;
    
    root = createBinaryTree();

    cout<<"Pre order: "<<endl;

    preOrder(root);

    cout<<endl;

    Node* result = searchNode(root,0);

    if(result!= NULL)
    {
        cout<<"Node found : "<<result->data<<endl;
    }
    else
    {
        cout<<"Not found "<<endl;
    }
    
    return 0;

}