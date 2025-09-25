// Chú thích về thuật toán 
// Giải thích tại sao Insert lại tối ưu hơn Select -> Ghi trong Samsung Note

#include <iostream> 
using namespace std;
void Insertion_Sort(int *A, int n ) // How to pass the Array to the Function and Changing it 
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
    int n; 
    int *A = new int[100];
    bool check = true; 
    do {
        if(!check) {cout << "Error!!!" << endl;}
        cout << "Please enter the size of array: ";
        cin >> n;
        check = false;
    }while (n <0 || n > 100); // Really take care of your logical operation 

    for(int i=0;i<n;i++)
    {
        cout << "Nhap phan tu thu " << i+1 << " : ";
        cin >> A[i] ; 
    }
    cout << A[0] << A[1] << A[2] ; 
    // About using Git -> you have to save your file for GIT understanding that the files's changed 
    // In main function, progarm understand that A implies an array => sizeof(A) oke
    // In function outside, program understand that A is a pointer => sizeof(A) is not oke 
    Insertion_Sort(A,n); 
    for(int i=0; i<n; i++)
    {
        cout << A[i] << ' ' ; 
    }    
    delete[] A; 
    // Xoa mot mang A duoc cap phat dong 
    // Using delete will remove everything in your array, so just using it in the end of program
}