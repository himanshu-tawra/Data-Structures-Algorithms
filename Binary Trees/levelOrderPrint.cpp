/*
Program to print the given tree level order.


                        8
                      /   \
                     3     10
                   /  \      \
                  1    6      14
                     /   \    /
                    4     7  13

->input : 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

->output : 8 
           3 10 
           1 6 14 
           4 7 13 

*/

#include<iostream>
#include<queue>

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


void levelOrder(Node* root)
{
    queue <Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* ans = q.front();
        q.pop();
        if(ans == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<ans->data<<" ";
            if(ans->left)
            {
                q.push(ans->left);
            }
            if(ans->right)
            {
                q.push(ans->right);
            }
        }
        
    }
}

int main()
{
    Node* root = NULL;
    
    root = createBinaryTree();

    levelOrder(root);

    return 0;
    
}