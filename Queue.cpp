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
            if(Rear == 0 && Front == 0) { 
                Front = -1;
                return array[Rear--]; 
            }
            else return array[Front++]; 
        }
        void Display()
        {
            cout << endl << "The information of the queue is: " << endl;
            cout << "----------This is the top of the queue----------" << endl;
            for(int i = Front; i<= Rear; i++)
            {
                cout << array[i] << endl;
            }
        }
};

int main()
{
    int option;
    int val;
    Queue<int> Q;
    do{
        cout << endl << "--------------------MENU--------------------" << endl;
        cout << "Enter 1 to enqueue" << endl;
        cout << "Enter 2 to dequeue" << endl;
        cout << "Enter 3 to get the top of the queue" << endl;
        cout << "Enter 4 to display the queue" << endl; 
        cout << "Enter 5 to cancel the menu" << endl;
        cout << "Your option is: "; cin >> option;
        switch(option)
        {
            case 1:
                cout << "Enter the value you want to add: " ; 
                cin >> val;
                try {
                    Q.EnQueue(val);
                    cout << "The value was added"; 
                }
                catch (const char *allert) {cout << allert;} 
                break;
            case 2: 
                try{
                    Q.DeQueue();
                    cout << "The top element of the queue is deleted";
                }
                catch (const char *allert) {cout << allert;}
                break;
            case 3: 
                try{
                    cout << "The top of the queue is: ";
                    cout << Q.Get();
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