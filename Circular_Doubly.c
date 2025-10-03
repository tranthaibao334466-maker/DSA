// Danh sách liên kết mà ở đó con trỏ next của phần tử cuối danh sách trỏ vào nốt đầu tiên trong danh sách 

#include <stdio.h>

struct Node
{
    int val;
    struct Node *next;
};
void Create_List(struct Node **START, int n)
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

int main()
{ 

}