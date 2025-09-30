// Using C struct to create stack data structure
// ??? How to use template in C++ to apply stucture for more data types 

#include <stdio.h>

// const int MAX = 50;
// Avoid using const in C program

#define MAX 50
struct Stack{
    int infor[MAX];
    int size;
};

// Khoi tao Stack 
void Init_Stack(struct Stack *S)
{
    S->size = 0;
}
void Push(struct Stack *S, int val)
{
    if (S->size == MAX)
        return ; 
    S->infor[S->size] = val; // Point to the last vacancy in the array 
    (S->size)++;
}
void Pop(struct Stack *S)
{
    if(S->size == 0) return; 
    (S->size)--; 
    // Just take care of the real capacity ( drawback of static array )
}
int Top(struct Stack *S)
{
    if (S->size == 0 ) return 0;
    int val = S->infor[S->size -1];
    (S->size)--;
    return val;
}
int Peek(struct Stack *S)
{
    if(S->size==0) return 0; 
    int val = S->infor[S->size-1];
    return val;
}
void display_Stack (struct Stack S)
{
    int n = (S.size);
    for(int i=0;i<n;i++)
    {
        printf("Phan tu thu %d la: %d\n", i+1 , S.infor[i]);
    }
}

void ToBinary(int val, struct Stack *S)
{
    while(val > 0)
    {
        Push(S, (val%2));
        val/=2;
    }
}
// Transfer from decimal to binary
int main()
{
    int val;
    int check = 1;
    struct Stack S;
    Init_Stack(&S);
    do{
        if(!check) {printf("Error! Please enter the positive number: ");}
        else{
            printf("Enter the value: ");
        }
        scanf("%d", &val);
        check = 0 ;
    }while(val < 0);
    ToBinary(val , &S);
    int n = S.size;
    printf("The binary value of %d is: \n", val);
    for(int i=0;i<n;i++)
    {
        printf("%d", Top(&S));
    }
}