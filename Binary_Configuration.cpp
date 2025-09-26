// List all the binary with n number

#include <iostream>

using namespace std;

int n;
int X[100]; 
 
void Try(int i)
{
    for(int j=0;j<=1;j++)
    {
        X[i] = j;
        if(i==(n-1))
        {
            for(int i=0;i<n;i++)
            {
                cout << X[i] << ' ';
            }
            cout << endl;
        }
        else Try(i+1);
    }
}
int main()
{
    cout << "Enter n number: ";
    cin >> n;
    Try(0);
}