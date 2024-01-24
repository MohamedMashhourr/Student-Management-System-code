
#define NULLPTR ((void*)0)
typedef struct{

    char name[20];
    int age;
    char phone[12];


}family_t;

typedef struct
{
    char name[20];
    int id;
    int age;
    char phone[12];
    char grade;
    family_t father;
    family_t mother;
    int numOfBro;
    family_t *brothers;

}student_t;


typedef enum{
    LIST_EMPTY,
    LIST_NOT_FOUND,
    LIST_DONE,
    STUDENT_ID_FOUND,
    STUDENT_ID_NOT_FOUND


}listStatus_t;


typedef struct node{

    student_t s1;
    struct node* next;

}node_t;


void display(void);

void student_add(void);
void student_print(void);

int array_scan(char*arr,int maxSize);
void array_print(const int*arr,int size);

void string_scan(char*str,int maxSize);
void string_print(char*str);

node_t* student_AddFirst(student_t s);
void student_AddToLast(node_t*head,student_t s);
listStatus_t student_PrintAll(node_t*head);
listStatus_t student_delete(node_t**phead,student_t s);
listStatus_t student_SearchId(node_t*head,student_t s);
listStatus_t student_EditId(node_t*head,student_t olds1,student_t news1);

listStatus_t student_SearchName(node_t*head,student_t s);


int student_count(node_t *p);


node_t* student_SortList(node_t* head);
node_t* student_SortListAge(node_t* head);


