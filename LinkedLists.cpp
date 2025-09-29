# include <iostream>
#include<bits/stdc++.h>

using namespace std;
// Remove unnecessary function 
struct Student{
    int MSV;
    float GPA;
    string NAME; 
};
struct node{
    struct Student Information;
    struct node *Next; 
};

struct node *Start = NULL;
struct node *Create_Lists(struct node *Start, int n )
{
    string name;
    float gpa;
    int msv;
    //struct node *new_node = (struct node *)malloc(sizeof(struct node)); -> Cap phat dung malloc ( C )
    ////struct node *new_node = new struct node; 
    // new data_type -> Cap phat trong C++ mot vung nho dong chua duoc 1 bien kieu data_type
    // new data_type(100) -> Cap phat vung nho cho 100 bien kieu data_type
    // new data_type(100) -> Cap phat va gan phan tu = 100 vao vung nho ay 
    // struct node *new_node = new struct node ({name},{msv},{gpa}); ??? Maybe can't run 
    struct node *ptr;
    for(int i=1;i<=n;i++)
    {
        struct node *new_node = new struct node; 
        cout << "Nhap ten sinh vien thu " << i << " : "; 
        getline(cin,name);
        cout << "Nhap ma sinh vien thu " << i << " : "; 
        cin >> msv;
        cout << "Nhap gpa sinh vien thu " << i << " : "; 
        cin >> gpa;
        cin.ignore();
        (new_node->Information).NAME = name;
        (new_node->Information).MSV = msv; 
        (new_node->Information).GPA = gpa;

        if (Start == NULL)
        {
            Start = new_node;
            new_node->Next = NULL;
        }
        else{
            ptr = Start;
            while(ptr->Next != NULL)
            {
                ptr=ptr->Next;
            }
            ptr->Next = new_node;
            new_node->Next = NULL;
        }
    }
    return Start;
}

void display_list(struct node *Start)
{
    struct node *ptr = Start;
    int n = 1;
    //while(ptr->Next != NULL)
    cout << endl << "Thong tin sinh vien: " << endl; // Added new comment to make program output more readable 
    while(ptr != NULL)
    {
        cout << "Ten sinh vien thu " << n << " la: " << (ptr->Information).NAME << endl;
        cout << "GPA sinh vien thu " << n << " la: " << (ptr->Information).GPA << endl;
        cout << "MSV sinh vien thu " << n << " la: " << (ptr->Information).MSV << endl;
        n++;
        ptr = ptr->Next;
    }
}
int main()
{
    int n;
    cout << "Please enter the number of students: "; 
    cin >> n;
    cin.ignore(); // Loi o day nen khong the nhap duoc 
    Start = Create_Lists(Start,n); // O day ham Create tra ve Start nhung minh lai khong truyen cho Display nen no van la NULL
    display_list(Start);
}
