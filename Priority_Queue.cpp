// Setting priority queue 

#include <bits/stdc++.h>

using namespace std;

#define MAX 100 

template<typename T>
class Priority_Queue{
    private:
        pair <int,T> *array;
        int Front;
        int Rear;
    public:
        Priority_Queue(){
            array = new pair<int,T>[MAX];
            Front = Rear = -1; 
        }
        ~Priority_Queue()
        {
            delete[] array;
        }
        bool Is_Empty() { return (Front == -1);}
        bool Is_Full() { return (Rear == MAX-1);}
        void Enqueue(pair<int,T> val)
        {
            if(Is_Full()) throw "Queue is full";
            if(Is_Empty())
            {
                Front = Rear = 0;
                array[Rear] = val; 
            }
            else{
                int index = Front; 
                for(; index <= Rear ; index++)
                {
                    if(val.first > array[index].first) 
                    {
                        for(int i=Rear;i>=index;i--)
                        {
                            array[i+1] = array[i];
                        }
                        Rear++;
                        array[index] = val;
                        break;
                    }
                }
                if(index == Rear+1) array[++Rear] = val; 
            }
        }
        void Dequeue()
        {
            if(Is_Empty()) throw "Queue is empty";
            if(Front == 0 && Rear == 0)
            {
                Front = Rear = -1;
            }
            else Front++; 
        }
        pair<int,T> Top()
        {
            if(Is_Empty()) throw "Queue is empty";
            if(Front == 0 && Rear == 0)
            {
                Front = -1;
                return array[Rear--]; 
            }
            else return array[Front++]; 
        }
        void Display()
        {
            cout << endl << "The information of the queue is: " << endl; 
            cout << endl << "==============This is the top of the queue===============" << endl;
            for(int i=Front;i<=Rear;i++)
            {
                cout << "The value of element is: " << array[i].second << endl;
                cout << "Its priority is: " << array[i].first << endl; 
            }
        }
        getF(){
            return Front;
        }
        getR(){
            return Rear; 
        }
};

int main()
{
    Priority_Queue<int> PQueue;
    int option;
    pair<int,int> val; 
    do{
        cout << endl << "======================MENU=======================" << endl;
        cout << "Enter 1 to enqueue" << endl;
        cout << "Enter 2 to dequeue" << endl;
        cout << "Enter 3 to get the top element of the queue" << endl;
        cout << "Enter 4 to display the queue" << endl;
        cout << "Enter 5 to cancel the menu" << endl;
        cout << "Your option is: "; cin>>option;
        switch(option){
            case 1:
                cout << "Enter the value: "; cin >> val.second;
                cout << "Enter the priority: "; cin >> val.first;
                try{
                    PQueue.Enqueue(val);
                }
                catch(const char* allert){cout << allert;}
                break;
            case 2:
                try{
                    PQueue.Dequeue();
                }
                catch(const char* allert){cout << allert;}
                break;
            case 3:
                try{
                    pair<int,int> res = PQueue.Top(); 
                    cout << "The top value is: " << res.second << endl;
                    cout << "Its priority is: " << res.first << endl;
                }
                catch(const char* allert){cout << allert;}
                break;
            case 4:
                PQueue.Display();
                break;
            case 5:
                break;
        }
    }while(option != 5);

}