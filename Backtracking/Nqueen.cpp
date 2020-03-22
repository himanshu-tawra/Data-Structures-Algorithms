#include<iostream>
using namespace std;


bool KyaPlaceKarSakteHai(int board[][10],int i,int j,int n)
{
    //check row and column
    for(int k = 0; k < n; k++)
    {
        if(board[i][k] || board[k][j])
        {
            return false;
        }
    }
    // check for the upper right diagnol
    int row = i;
    int col = j;

    while(i >= 0 && j < n)
    {
        if(board[i][j])
        {
            return false;
        }
        i--;
        j++;
    }

    //check for the upper left diagnol
    i = row;
    j = col;

    while(i >= 0 && j >= 0)
    {
        if(board[i][j])
        {
            return false;
        }
        i--;
        j--;
    }

    return true;
}



bool NQueen(int board[][10],int i, int n)
{
    // base case 
    if(i == n)
    {
        // prin the board

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 1)
                {
                    cout<<"Q ";
                }
                else
                {
                    cout<<"- ";
                }
                
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }



    // recursive case
    for(int j = 0; j < n; j++)
    {
        if(KyaPlaceKarSakteHai(board,i,j,n) == true)
        {
            board[i][j] = 1; //place the queen on the board
            bool KyaBakiBaatBani = NQueen(board,i+1,n);
            if(KyaBakiBaatBani == true)
            {
                return true;
            }

        }
        board[i][j] = 0;
    }

    return false;
}


int main()
{
    int board[10][10] = {0};
    int n;
    cin>>n;

    NQueen(board,0,n);


    return 0;
}