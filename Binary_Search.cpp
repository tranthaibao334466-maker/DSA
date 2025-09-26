#include <iostream>

using namespace std;

int Binary_Search(int *A, int L, int R, int val)
{
    if(L<=R)
    {
        int Mid = (L+R)/2;
        if(val == A[Mid]) return Mid;
        else {
            if(val > A[Mid])
            {
                return Binary_Search(A,Mid+1,R,val);
            }
            else
            {
                return Binary_Search(A,L,Mid-1,val);
            }
        }
    }
    return __INT_MAX__; 
    // If your pos = 0, it'll be wrong
}

int main()
{
    int *A = new int[100];
    int n;
    int val;
    bool check = true;
    cout << "Please choose a number from 0 to 100: " ;
    do{
        if(!check) {cout << "ERROR!" << endl << "Please enter the available number: ";}
        cin >> n; 
        check = false;
    }while(n<0 || n>100);
    cout << endl << "Enter the array: " << endl;
    for(int i=0;i<n;i++)
    {
        cout << "Enter the " << i+1 << " num: ";
        cin >> A[i];
    } 
    cout << "Enter the enquiring number: ";
    cin >> val; 
    int pos = Binary_Search(A,0,n-1,val); 
    // Using pos to prevent call function two time ( which is time-wasting)
    if(pos == __INT_MAX__) {cout << "Can't find the value in the array" ;}
    else{
        cout << "The position of enquiring number is: " << pos+1 << endl;
    }

}