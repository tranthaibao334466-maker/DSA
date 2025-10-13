#include <bits/stdc++.h>

using namespace std;

#define MAX 5 
template<typename T> 
class Circular_Queue{
    private:
        int Front;
        int Rear;
        T *array;
    public:
        Circular_Queue(){
            Front = Rear = -1;
            array = new T[MAX]; 
        }
        ~Circular_Queue(){delete[] array;}
        bool Is_Full()
        {
            return (Rear+1)%MAX == Front; 
            // Rear = MAX-1 && Front = 0
            // Rear,Front < MAX-1 && Rear+1 = Front 
        }
        bool Is_Empty()
        {
            return Front == -1; 
        }
        int Get_Front() {return Front;} 
        int Get_Rear() {return Rear;} 
        void Enqueue(T val)
        {
            if(Is_Full()) throw "Queue is full"; 
            if(Is_Empty())
            {
                Front = 0;
                array[++Rear] = val;
            }
            else{
                if(Rear == MAX-1) { array[Rear=0] = val; }
                else {array[++Rear] = val;}
            }
        }
        void Dequeue()
        {
            if(Is_Empty()) throw "Queue is empty";
            if(Rear == 0 && Front == 0)
            {
                Rear = Front = -1;
            }
            else{
                if(Front == MAX-1) Front = 0;
                else Front++; 
            }
        }
        T Get()
        {
            if(Is_Empty()) throw "Queue is empty";
            if(Rear == 0 && Front == 0)
            {
                Rear = -1;
                return array[Front--]; 
            }
            else{
                if(Front == MAX-1)
                {
                    T temp = array[Front];
                    Front = 0; 
                    return temp; 
                }
                return array[Front++]; 
            }
        }
        void Display()
        {
            if(Is_Empty()) throw "Queue is empty"; 
            cout << endl << "The information of the circular Queue is: " << endl;
            cout << "-----------This is the top of the queue----------" << endl;
            if(Front <= Rear)
            {
                for(int i=Front;i<=Rear;i++)
                {
                    cout << array[i] << endl;
                }
            }
            else{
                for(int i=Front; i<=MAX-1; i++)
                {
                    cout << array[i] << endl;
                }
                for(int i=0; i<= Rear; i++)
                {
                    cout << array[i] << endl; 
                }
            }
        }
};

int main()
{
    int option;
    int val; 
    Circular_Queue<int> Q;
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
                try{
                    cout << "Enter the value you want to add: " ; 
                    cin >> val;
                    Q.Enqueue(val);
                    cout << "The value was added"; 
                    // Using throw - catch to avoid printing the above syntax when exception happen 
                }
                catch(const char* allert) {cout << allert;}
                break;
            case 2: 
                try{
                    Q.Dequeue();
                    cout << "The top element of the queue is deleted";
                }
                catch(const char* allert) {cout << allert;}
                break;
            case 3: 
                try{
                    cout << "The top of the queue is: ";
                    cout << Q.Get();
                }
                catch ( const char *allert) {cout << allert;}
                break;
            case 4:
                try{Q.Display();}
                catch (const char* allert) { cout << allert;}
                break;
            case 5:
                break;
        }
    }while(option != 5);
}