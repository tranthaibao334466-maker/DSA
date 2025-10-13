#include <bits/stdc++.h>

using namespace std;

#define MAX 100
template<typename T>
class Queue{
    private:
        int Front;
        int Rear;
        T *array;
    public:
        Queue(){
            array = new T[MAX];
            Front = Rear = -1;
            // -1 instead of 0 to avoid Rear skipping the first index ( i = 0 )
        }
        ~Queue(){delete[] array;}
        bool Is_Empty() { return (Front == -1); }
        void EnQueue(T val)
        {
            if(Rear == MAX) throw "Queue is Full";
            if(Is_Empty())
            {
                Front = Rear = 0;
                array[Rear] = val; 
            }
            else array[++Rear] = val; 
        }
        void DeQueue()
        {
            if(Is_Empty()) throw "Queue is Empty";
            if(Rear == 0 && Front == 0) { Front = Rear = -1;}
            else Front++; 
        }
        T Get()
        {
            if(Is_Empty()) throw "Queue is Empty";
            return array[Front];
        }
        void Display()
        {
            cout << endl << "The information of the queue is: " << endl;
            cout << endl << "----------This is the top of the queue----------" << endl;
            for(int i = Front; i<= Rear; i++)
            {
                cout << array[i] << endl;
            }
        }
};


class File{
    private:
        int Pages;
        string Name;
    public:
        File(){};
        friend istream& operator >> (istream& in, File &F)
        {
            cout << "Enter the file name: ";
            getline(in,F.Name);
            cout << "Enter the file page number: ";
            in >> F.Pages; 
            in.ignore(); 
            return in; 
        }
        friend ostream& operator << (ostream& out, const File &F)
        {
            out << endl << "File name is: " << F.Name << endl;
            out << "File include " << F.Pages << " pages" << endl; 
            return out; 
        }
};

int main()
{
    int option;
    File F; 
    Queue<File> Q;
    do{
        cout << endl << "--------------------MENU--------------------" << endl;
        cout << "Enter 1 to add a file in queue" << endl;
        cout << "Enter 2 to dequeue the printed file" << endl;
        cout << "Enter 3 to print" << endl;
        cout << "Enter 4 to display the queue" << endl; 
        cout << "Enter 5 to cancel the menu" << endl;
        cout << "Your option is: "; cin >> option;cin.ignore(); 
        switch(option)
        {
            case 1:
                try {
                    cout << "Enter the file you want to add: " << endl ; 
                    cin >> F; // Using cin after operation overloading
                    Q.EnQueue(F);
                    cout << "The file was added"; 
                }
                catch (const char *allert) {cout << allert;} 
                break;
            case 2: 
                try{
                    Q.DeQueue();
                    cout << "The top file in the queue is deleted";
                }
                catch (const char *allert) {cout << allert;}
                break;
            case 3: 
                try{
                    cout << Q.Get();
                    cout << "File was printed"; 
                }
                catch ( const char *allert) {cout << allert;}
                break;
            case 4:
                Q.Display(); 
                break;
            case 5:
                break;
        }
    }while(option != 5);
}