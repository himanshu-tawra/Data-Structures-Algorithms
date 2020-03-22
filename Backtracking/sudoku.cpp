#include<iostream>
#include<cmath>
using namespace std;


bool isSafeToPut(int mat[][9] , int i ,int j ,int number,int n)
{
    // check for the row and column
    for(int k = 0; k < n; k++)
    {
        if(mat[i][k] == number || mat[k][j] == number)
        {
            return false;
        }
    }
    // check for the smaller box

    n = sqrt(n);
    int row_start = (i/n)*n;
    int col_start = (j/n)*n;

    for(int i = row_start; i < row_start+n; i++)
    {
        for(int j = col_start; j < col_start+n; j++)
        {
            if(mat[i][j] == number)
            {
                return false;
            }
        }
    }

    return true;
}


bool sudokuSolver(int mat[][9],int i ,int j,int n)
{

    // base case
    if(i == n)
    {
        //print the sudoku
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                cout<<mat[row][col]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    

    // recursive case

    if(j == n)
    {
        return sudokuSolver(mat,i+1,0,n);
    }

    if(mat[i][j] != 0)
    {
        return sudokuSolver(mat,i,j+1,n);
    }

    for(int number = 1; number <= n; number++)
    {
        if(isSafeToPut(mat,i,j,number,n))
        {
            mat[i][j] = number;
            bool kyaAageBatBani = sudokuSolver(mat,i,j+1,n);
            if(kyaAageBatBani)
            {
                return true;
            }
            mat[i][j] = 0;
        }
    }
    return false;
}



int main()
{
	int mat[9][9] =
	{
	{5,3,0,0,7,0,0,0,0},
	{6,0,0,1,9,5,0,0,0},
	{0,9,8,0,0,0,0,6,0},
	{8,0,0,0,6,0,0,0,3},
	{4,0,0,8,0,3,0,0,1},
	{7,0,0,0,2,0,0,0,6},
	{0,6,0,0,0,0,2,8,0},
	{0,0,0,4,1,9,0,0,5},
	{0,0,0,0,8,0,0,7,9}
	};

    sudokuSolver(mat,0,0,9);


    return 0;

}
