# include <iostream>
#include<bits/stdc++.h>

using namespace std;
// Remove unnecessary function 
struct Student{
    string NAME; 
    int MSV;
    float GPA;
};
struct node{
    struct Student Information;
    struct node *Next; 
};

struct node *Start = NULL; // Khai báo Start là biến toàn cục ta hoàn toàn có thể không cần truyền Start vào hàm nữa  

// Lưu ý về việc truyền con trỏ
// Khi truyền con trỏ trỏ vào một phần tử vào hàm, các tác động của hàm sẽ trực tiếp thay đổi giá trị của phần tử 
// Tuy nhiên khi truyền con trỏ ( chính bản thân con trỏ ) vào hàm thì giá trị của con trỏ trong hàm chỉ là một giá trị sao chép 
// tưởng tượng như là cũng có một con trỏ trỏ vào chính con trỏ đó và muốn thay đổi các giá trị của con trỏ ấy thì 
// phải truyền con trỏ trỏ vào nó chứ không phải truyền chính nó  

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
        cout << endl << "Nhap ten sinh vien thu " << i << " : "; 
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

void Insert_Begin( struct Student S)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    (new_node->Information).GPA = S.GPA;
    (new_node->Information).MSV = S.MSV;
    (new_node->Information).NAME = S.NAME;
    new_node->Next = Start;
    Start = new_node;
}
void Insert_End( struct Student S)
{
    struct node *new_node = new (struct node);
    struct node *ptr = Start;
    (new_node->Information).GPA = S.GPA;
    (new_node->Information).MSV = S.MSV;
    (new_node->Information).NAME = S.NAME;
    while(ptr->Next != NULL) ptr = ptr->Next;
    ptr->Next = new_node;
    new_node->Next = NULL;
}
void display_list(struct node *Start)
{
    struct node *ptr = Start;
    int n = 1;
    //while(ptr->Next != NULL)
    cout << endl << "Thong tin sinh vien: " << endl << endl; // Added new comment to make program output more readable 
    while(ptr != NULL)
    {
        cout << endl << "Ten sinh vien thu " << n << " la: " << (ptr->Information).NAME << endl;
        cout << "MSV sinh vien thu " << n << " la: " << (ptr->Information).MSV << endl;
        cout << "GPA sinh vien thu " << n << " la: " << (ptr->Information).GPA << endl;
        n++;
        ptr = ptr->Next;
    }
}
int main()
{
    int n,choice;
    string name;
    int msv;
    float gpa;
    struct Student S;
    cout << "Nhap so luong sinh vien:  "; 
    cin >> n;
    cin.ignore(); // Loi o day nen khong the nhap duoc 
    Start = Create_Lists(Start,n); 
    // O day ham Create tra ve Start nhung minh lai khong truyen cho Display nen no van la NULL
    display_list(Start);
    cout << endl << "Please enter the information of added student : " << endl;

    cout << "Nhap ten sinh vien: "; 
    getline(cin,name);
    cout << "Nhap ma sinh vien: " ; 
    cin >> msv;
    cout << "Nhap gpa sinh vien: " ; 
    cin >> gpa;
    cin.ignore();
    S.GPA = gpa;
    S.MSV = msv;
    S.NAME = name;
    do
    {
        cout << endl << "Enter 1 to insert the new student at the begin" << endl;
        cout << "Enter 2 to insert the new student at the end" << endl ; 
        cout << "Your choice is: ";
        cin >> choice; 
        cin.ignore();
        switch(choice){
            case 1: 
                Insert_Begin(S);
                break; // if the first statement is true, all command after will be executed 
            case 2: 
                Insert_End(S);
                break;
        }
    } while (n>=1 && n<=2);
    display_list(Start);
}
