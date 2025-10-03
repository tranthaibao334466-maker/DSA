// Danh sách liên kết mà ở đó con trỏ next của phần tử cuối danh sách trỏ vào nốt đầu tiên trong danh sách 

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
struct NODE
{
    int val;
    struct NODE *next;
    struct NODE *prv;
};
void Create_CircularList(struct Node **START, int n)
{
    int val;
    for(int i=0;i<n;i++)
    {
        printf("Nhap thong tin sinh vien thu %d : ", i+1);
        scanf("%d", &val);
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->val = val;
        if(*START == NULL)
        {
            *START = new_node;
            new_node->next = NULL;
        }
        else{
            struct Node *ptr = *START;
            while(ptr->next != NULL)
                ptr=ptr->next;
            ptr->next = new_node;
            if(i != (n-1)) new_node->next = NULL;
            else new_node->next = *START;
        }
    }
}
void Create_DoublyList(struct NODE **START, int n)
{
    int val;
    for(int i=0;i<n;i++)
    {
        printf("Nhap gia tri thu %d : ", i+1);
        scanf("%d", &val);
        struct NODE *new_node = (struct NODE*)malloc(sizeof(struct NODE));
        struct NODE *temp;
        new_node->next=NULL;
        new_node->val=val;
        if(*START == NULL)
        {
            *START = new_node;
            temp = new_node;
        }
        else{
            struct NODE *ptr = *START;
            while(ptr->next != NULL) ptr = ptr->next;
            ptr->next = new_node;
            (ptr->next)->prv = temp;
            temp = new_node;
        }
    }
}
// Display Doubly List

// Find an element in Doubly Linked List
struct NODE *Find_Element(struct NODE *START, int n, int val)
{
    struct NODE* ptr = START;
    while(ptr != NULL)
    {
        if(ptr->val == val) return ptr;
        ptr=ptr->next;
    }
    return NULL;
}

int main()
{ 
    struct NODE *START = NULL;
    Create_DoublyList(&START, 5);
    struct NODE *ptr = Find_Element(START, 5,34);
    while(ptr != NULL)
    {
        printf("\n%d ", ptr->val);
        ptr = ptr->prv; 
    }

}