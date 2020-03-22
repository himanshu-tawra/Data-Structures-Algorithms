#include<iostream>
using namespace std;

bool RatInMaze(char maze[][5],int sol[][10],int i,int j,int n,int m)
{
    // base case
    if(i == n-1 && j == m-1)
    {
        sol[i][j] = 1;
        // print the path

        for(int k = 0; k < n; k++)
        {
            for(int l = 0; l < m; l++)
            {
                cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;

    }

    // Recursive case
    // assume that current cell we're standing on is a part of solution
    sol[i][j] = 1;
    //First check rigtwards
    if(j+1 < m && maze[i][j+1] != 'X')
    {
        bool kya_Right_Se_Rasta_Mila = RatInMaze(maze,sol,i,j+1,n,m);
        if(kya_Right_Se_Rasta_Mila == true)
        {
            return true;
        }
    }
    // check downwards
    if(i+1 < n && maze[i+1][j] != 'X')
    {
        bool kya_niche_se_rasta_mila = RatInMaze(maze,sol,i+1,j,n,m);
        if(kya_niche_se_rasta_mila == true)
        {
            return true;
        }
    }

    sol[i][j] = 0;

    return false;
}



int main()
{
    char maze[5][5] = {
        "0000",
        "00XX",
        "0000",
        "XX00"
    };

    int sol[10][10] = {0};

    RatInMaze(maze,sol,0,0,4,4);


    return 0;
}