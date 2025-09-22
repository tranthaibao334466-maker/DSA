#include <iostream> 
using namespace std;
void Insertion_Sort(int A[], int n ) // How to pass the Array to the Function and Changing it 
{
    for(int i=1; i<n ; i++)
    {
        int  j = i-1;
        int key = A[i];
        while(A[j] > key && j >= 0)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
int main()
{
    int A[9]  = {2,3,5,7,2,4,6,9,10};
    int n = sizeof(A)/sizeof(int);
    // In main function, progarm understand that A implies an array => sizeof(A) oke
    // In function outside, program understand that A is a pointer => sizeof(A) is not oke 
    Insertion_Sort(A,n); 
    for(int i=0; i<(sizeof(A)/(sizeof(int))); i++)
    {
        printf("%d ", A[i]);
    }    

}