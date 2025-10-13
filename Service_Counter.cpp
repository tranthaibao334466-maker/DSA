#include <bits/stdc++.h>

using namespace std;

#define MAX 5 
#define START_ID 0 
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

class Client{
    private:
        static int count; 
        string Name;
        int ID; 
    public:
        Client(){
            count++;
            ID = count; 
        };
        friend istream & operator >> (istream &in, Client &C)
        {
            cout << endl << "Enter the client name: ";
            getline(in,C.Name);   
            return in;
        }
        friend ostream& operator << (ostream &out, const Client &C)
        {
            out << "The client name is: " << C.Name << endl;
            out << "The client ID is: " << C.ID << endl; 
            return out; 
        }
}; 
int Client::count = -MAX + START_ID; 
// Decrease by MAX, then +MAX -> = 0 

int main()
{
    int option;
    // Client C -> Declaring a variable in here means that the static variable count won't work properly 
    Circular_Queue<Client> Q;
    //This syntax ~ Declare a Client 'MAX' time ( MAX = 5 => count = 5 after move to the "case 1: ") 
    do{
        cout << endl << "--------------------MENU--------------------" << endl;
        cout << "Enter 1 to add a new client" << endl;
        cout << "Enter 2 to remove the client just served" << endl;
        cout << "Enter 3 to display the queue" << endl; 
        cout << "Enter 4 to cancel the menu" << endl;
        cout << "Your option is: "; cin >> option; cin.ignore();
        switch(option)
        {
            case 1:
                if(Q.Is_Full()) cout << "Queue is Full"; // Avoid using throw - catch in this case 
                else{
                    Client C; 
                    cout << "Enter the client information: " << endl; 
                    cin >> C;
                    Q.Enqueue(C);
                    cout << "The client was added"; 
                }
                break;
            case 2: 
                try{
                    Q.Dequeue();
                    cout << "The information of the client just served is deleted";
                }
                catch (const char *allert) {cout << allert;}
                break;
            case 3:
                try{Q.Display();}
                catch(const char *allert) {cout << allert;} 
                break;
            case 4:
                break;
        }
    }while(option != 4);

}