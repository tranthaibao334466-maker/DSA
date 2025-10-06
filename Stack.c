// Using C struct to create stack data structure
// ??? How to use template in C++ to apply stucture for more data types 

#include <stdio.h>
#include <stdlib.h> // Using this library to use malloc function 
#include <string.h> 
#include <ctype.h>

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
int Peek(struct Stack S)
{
    if(S.size==0) return 0; 
    return S.infor[S.size-1];
}
void display_Stack (struct Stack S)
{
    int n = (S.size);
    for(int i=0;i<n;i++)
    {
        printf("The %d element is: %d\n", i+1 , S.infor[i]);
    }
}

// Question 1: Transfomr decimal to binary 
void ToBinary(int val, struct Stack *S)
{
    while(val > 0)
    {
        Push(S, (val%2));
        val/=2;
    }
}
// Question 2: Checking valid parentheses 
int Check_Parentheses(char s[], struct Stack S)
{
    int n = strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(') Push(&S,(int)s[i]);
        if(s[i] == ')' ) 
        {
            if((S.size)==0) return 0; // Added ')' when there isn't any '(' before 
            Pop(&S); 
        }
    }
    if((S.size) == 0) return 1;
    else return 0; 
}

//Question 3: Postfix Calculating 

// People: (5+3)*4 (infix) -> Machine: 5 3 + 4 * -> Using stack to calculate 

int Postfix_Cal(char s[], struct Stack S)
{
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i])) Push(&S,(int)s[i] - 48); 
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if(S.size >= 2) 
            {
                if(s[i] == '+') Push(&S,  Top(&S) + Top(&S) );
                if(s[i] == '-') Push(&S,  Top(&S) - Top(&S) );
                if(s[i] == '*') Push(&S,  Top(&S) * Top(&S) );
                if(s[i] == '/') Push(&S,  Top(&S) / Top(&S) );
            }
            else return -1;
        }
    }
    if(S.size == 1 ) return Peek(S); // The valid expression just leave one element in stack at the end 
    else return -1;  
}


// Question 4: Checking symmetry string 

int Check_Symstring(char s[], struct Stack S)
{
    int n = strlen(s);
    for(int i=0,j=n-1; i<j ; i++,j--)
    {
        Push(&S,s[i]);
        if(s[j] == s[i]) Pop(&S);

        else return 0;  
    }
    if(S.size == 0) return 1; 
}
int main()
{
    int val;
    char *s = (char*)malloc(sizeof(char)*100); 
    int check = 1;
    struct Stack S;
    Init_Stack(&S);
    // Testing for Question 1: 

    /* do{
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
    } */

    // Testing for question 2
    
    
    /*printf("Enter the string: "); 
    //getchar() Using when you enter the input with scanf before 
    fgets(s,100,stdin);
    if(Check_Parentheses(s,S)) printf("Valid Parentheses !");
    else printf("Invalid parentheses !"); 
    free(s) */

    // Testing for question 3

    /*printf("Enter the string: ");
    fgets(s,100,stdin);
    if(Postfix_Cal(s,S) == -1) printf("Invalid postfix expression !");
    else printf("The answer is: %d", Postfix_Cal(s,S));*/


    //Testing for question 4

    printf("Enter the string: ");
    fgets(s,100,stdin); // strlen would return the length of the string with '\0' at the end => Wrong 
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] == '\n') 
        {   s[i] = '\0'; 
            break; 
        } 
    }
    if(Check_Symstring(s,S)) printf("Is the symmetry string");
    else printf("Isn't the symmetry string"); 
}