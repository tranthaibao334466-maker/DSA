// Finding the right position of n Queen in a Chess Table (nxn)
// Don't have any Queen can eat other 

#include <iostream>

using namespace std;

int A[100];
// A[i] with i store the number of row and A[i] store the correspond collumn 
int n;

bool Check(int row,int col)
{
    // Iterate to ensure that the potential queen can't be eat by "all" the confirmed queen before
    for(int i=1;i<row;i++)
    // Remember to use quotation < ( i < row ) instead of <= 
    {
        if( col == A[i] || abs(col-A[i]) == abs(row-i) ) return false;
    }
    return true;
}
void Queen(int i)
{ 
    for(int j=1;j<=n;j++)
    {
        if(Check(i,j))
        {
            A[i] = j;
            if(i==n) 
            {
                for(int index =1 ; index <=n ; index++)
                {
                    cout << '(' << index << ',' << A[index] << ')' << " ";
                }
                // If there is a available solution the A[] array would be filled from the first index to the n one 
                cout << endl;
            }
            else Queen(i+1); 
        }
    }
}

int main()
{
    n=4;
    Queen(1);
}
