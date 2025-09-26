#include <iostream>

using namespace std;

void move(int n, string a , string b , string c)
{
    if(n==1)
    {
        cout << endl << "Move " << n << " disk from " << a << " to " << c << endl; 
    }
    else
    {
        move(n-1,a,c,b);
        move (1,a,b,c);
        move(n-1,b,a,c);
    }
}
int main()
{
    int n;
    bool check = true; 
    do{
        if(!check) {cout << "ERROR!" << endl << "PLEASE ENTER THE AVAILABLE NUMBER: ";}
        else{
            cout << "PLEASE ENTER THE NUMBER FROM 1 TO 32: "; 
        }
        cin >> n;
        check = false;
    }while(n<1 || n>32);
    move(n,"Tower 1", "Tower 2", "Tower 3");

}