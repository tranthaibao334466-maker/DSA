#include <iostream>

using namespace std;

void Merge(int A[], int L, int R, int Mid)
{
    int temp[100];
    int count = 0; 
    int first1 = L, last1 = Mid, first2 = Mid+1, last2 = R;
    int index=0;
    for(; (first1 <= last1) && (first2 <= last2); index++ )
    {
        if(A[first1] < A[first2]) 
        {
            temp[index] = A[first1];
            first1++;
        }
        else{
            temp[index] = A[first2];
            first2++;
        }
    }
    // Forget to add index++
    for(;first1 <= last1; first1++,index++)
    {
        temp[index] = A[first1]; 
    }
    for(;first2 <= last2; first2++,index++)
    {
        temp[index] = A[first2];
    }
    for(int i=0; L<=R; L++,i++)
    {
        A[L] = temp[i];
    }
}
void Merge_Sort(int A[], int L , int R)
{
    if(L<R)
    {
        int Mid = (L+R)/2;
        Merge_Sort(A,L,Mid);
        Merge_Sort(A,Mid+1,R);
        Merge(A,L,R,Mid);
    }
}
int main()
{
    const int MAX_NUM = 100 ;
    const int MIN_NUM = 1 ; 
    int A[100];
    int n;
    bool check = true;
    do{
        if(!check) {cout << "ERROR!" << endl << "PLEASE ENTER THE AVAILABLE NUMBER: ";}
        else cout << "PLEASE ENTER THE NUMBER: "; 
        cin >> n;
        check = false;
    } while(n < MIN_NUM || n > MAX_NUM);
    for(int i=0;i<n;i++)
    {
        cout << "Enter the " << i+1 << " number: " ;
        cin >> A[i];
    }
    Merge_Sort(A,0,n-1);
    cout << endl << "Sorted Array is: " << endl;
    for(int i=0;i<n;i++)
    {
        cout << A[i] << ' '; 
    }

}