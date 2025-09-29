// Finding the right position of n Queen in a Chess Table (nxn)
// Don't have any Queen can eat other 

#include <iostream>

using namespace std;

int n; 
int count = 0 ;
pair <int,int> P[100];
int  A[4][4];
void Queen_Sort(int i , int j)
{
    if(count == n) 
    {
        for(int index = 0; index < n; index ++)
        {
            cout << "The " << i+1 << " position is: " << '(' << P[index].first << ',' << P[index].second << ')' << endl;
        }
    }
    else
    {
        for(int a=0;a<n;a++)
        {
            if(a==i)
            {
                for(int b=0;b<n;b++)
                {
                    A[a][b] = 0; 
                }
            }
            else{
                for(int b=0;b<n;b++)
                {
                    if (A[a][b]==0) continue;
                    if(b==j || abs(i-j) == abs(a-b)) A[a][b] = 0; 
                    else{
                        P[count].first = a;
                        P[count++].second = b;
                        Queen_Sort(a,b);
                    }
                }
            }
        }
    }
}
int main()
{
    cout << "Enter the n number: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j] = 1;
        }
        for(int j=0;j<n;j++)
        {
            Queen_Sort(i,j);
        }
    }
    if(count<n) cout << "Sorting is unavailable !" ; 
}