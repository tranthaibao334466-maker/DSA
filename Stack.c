#include <stdio.h>

const int MAX = 50;
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
int main()
{
    struct Stack S;
    Init_Stack(&S);
    printf("%d\n", S.size);
    Push(&S, 3);
    Push(&S,4);
    Push(&S,5);
    Pop(&S);
    display_Stack(S);

}