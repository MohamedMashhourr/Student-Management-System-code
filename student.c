#include <stdio.h>
#include <stdlib.h>
#include "student.h"
extern student_t s;




void display(void)
{
    printf("\n      1- Add Student Details\n");
        printf("      2- Print all student details\n");
        printf("      3- Delete a student Using ID \n");
        printf("      4- Search on Student list\n");
        printf("      5- Sort The List By Students ID\n");
        printf("      6- The Total Number Of Students \n");
        printf("      7- Exit \n\n");
}




void string_scan(char*str,int maxSize)
{
    int i=0;
    fflush(stdin); //string قبل ال main لرقم في ال  scan ا عشان لو هعمل
    scanf("%c",&str[i]);
    for(;str[i]!='\n';)
    {
        i++;
        scanf("%c",&str[i]);
        if(i==maxSize-1)
        {
            break;

        }

    }
    str[i]=0;        // عشان اسكان لجد الانتر بظبط هشيل الانتر و احط مكنها صفرٍ
}

void string_print(char*str)
{

    int i;
    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}

void student_add(void)
{

    printf("      NAME: ");
    string_scan(&s.name,20);

    printf("      ID: ");
    scanf("%d",&s.id);

    printf("      AGE: ");
    scanf("%d",&s.age);

    printf("      PHONE NUMBER: ");
    string_scan(&s.phone,12);

}

void student_print(void)
{
    printf("\n==============================\n");
    printf("NAME: ");
    string_print(&s.name);
    printf(" ID : %d\n",s.id);
    printf(" AGE : %d\n",s.age);
    printf("PHONE NUMBER : ");
    string_print(&s.phone);
    printf("==============================\n");
}

node_t* student_AddFirst(student_t s)
{
    node_t* newnode=malloc(sizeof(node_t));
    newnode->s1=s;
    newnode->next=NULLPTR;
    return newnode;

}

void student_AddToLast(node_t*head,student_t s)
{
    node_t* newnode=student_AddFirst(s);
     node_t*current=head;

    if(head==NULLPTR)
    {
        return LIST_EMPTY;
    }

    while(current->next!=NULLPTR)
    {
        current=current->next;
    }
    current->next=newnode;


}

listStatus_t student_PrintAll(node_t*head)
{
    node_t*current=head;

    if(current==NULLPTR)
    {
        printf("\n    **THE LIST IS EMBTY**\n");
        return LIST_EMPTY;
    }
    while(current!=NULLPTR)
    {
    printf("\n==============================\n");
    printf(" NAME: ");
    string_print(&current->s1.name);
    printf(" ID : %d\n",current->s1.id);
    printf(" AGE : %d\n",current->s1.age);
    printf(" PHONE NUMBER : ");
    string_print(&current->s1.phone);
        //printf("%d  ",current->s1.age);
        current=current->next;
    }
    printf("\n==============================\n");
}

listStatus_t student_delete(node_t**phead,student_t s)
{
    node_t*current=*phead;
    node_t*temp;

    if(*phead==NULLPTR)
    {   printf("\n    **THE LIST IS EMBTY**\n");
        return LIST_EMPTY;
    }
    if(current->s1.id==s.id) //corner case to delete first element
    {
        temp=*phead;
        *phead=current->next;
        free(temp);
        return STUDENT_ID_FOUND;
    }
    while(current->next!=NULLPTR)
    {
        if(current->next->s1.id==s.id)
        {
            temp=current->next;
            current->next=current->next->next;
            free(temp);
            return STUDENT_ID_FOUND;
        }
        current=current->next;
    }
    return STUDENT_ID_NOT_FOUND;
}

listStatus_t student_SearchId(node_t*head,student_t s)
{
    node_t*current=head;

    while(current!=NULLPTR)
    {
        if(current->s1.id==s.id)
        {
            return STUDENT_ID_FOUND;
        }
        current=current->next;
    }
    return STUDENT_ID_NOT_FOUND;


}

listStatus_t student_PrintId(node_t*head,student_t s)
{
    node_t*current=head;

    while(current!=NULLPTR)
    {
        if(current->s1.id==s.id)
        {
             printf("\n==============================\n");
    printf(" NAME: ");
    string_print(&current->s1.name);
    printf(" ID : %d\n",current->s1.id);
    printf(" AGE : %d\n",current->s1.age);
    printf(" PHONE NUMBER : ");
    string_print(&current->s1.phone);
            printf("\n==============================\n");
            return STUDENT_ID_FOUND;
        }
        current=current->next;
    }
    return STUDENT_ID_NOT_FOUND;


}
listStatus_t student_EditId(node_t*head,student_t olds1,student_t news1)
{
    node_t*current=head;

    while(current!=NULLPTR)
    {
        if(current->next->s1.id==olds1.id)
        {
            current->s1.id=news1.id;

            return STUDENT_ID_FOUND;
        }
        current=current->next;
    }
    return STUDENT_ID_NOT_FOUND;


}


node_t* student_SortList(node_t* head)
{
   node_t *x, *y, *z, *w, *s;
    x = y = head;
    if(head==NULLPTR)
    {   printf("\n    **THE LIST IS EMBTY**\n");
        return LIST_EMPTY;
    }
    while (y->next) {
        z = w = y->next;
        while (w) {
            if (y->s1.id > w->s1.id) {
                if (y->next == w) {
                    if (y == head) {
                        y->next = w->next;
                        w->next = y;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        head = y;
                        w = w->next;
                    }
                    else {
                        y->next = w->next;
                        w->next = y;
                        x->next = w;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                    }
                }
                else {
                    if (y == head) {
                        s = y->next;
                        y->next = w->next;
                        w->next = s;
                        z->next = y;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                        head = y;
                    }
                    else {
                        s = y->next;
                        y->next = w->next;
                        w->next = s;
                        z->next = y;
                        x->next = w;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                    }
                }
            }
            else {
                z = w;
                w = w->next;
            }
        }
        x = y;
        y = y->next;
    }

    return head;
}


node_t* student_SortListAge(node_t* head)
{
   node_t *x, *y, *z, *w, *s;
    x = y = head;
    if(head==NULLPTR)
    {   printf("\n    **THE LIST IS EMBTY**\n");
        return LIST_EMPTY;
    }
    while (y->next) {
        z = w = y->next;
        while (w) {
            if (y->s1.age > w->s1.age) {
                if (y->next == w) {
                    if (y == head) {
                        y->next = w->next;
                        w->next = y;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        head = y;
                        w = w->next;
                    }
                    else {
                        y->next = w->next;
                        w->next = y;
                        x->next = w;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                    }
                }
                else {
                    if (y == head) {
                        s = y->next;
                        y->next = w->next;
                        w->next = s;
                        z->next = y;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                        head = y;
                    }
                    else {
                        s = y->next;
                        y->next = w->next;
                        w->next = s;
                        z->next = y;
                        x->next = w;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                    }
                }
            }
            else {
                z = w;
                w = w->next;
            }
        }
        x = y;
        y = y->next;
    }

    return head;
}


int student_count(node_t *p)
{
    int count = 0;
    while(p != 0){
       count++;
       p = p -> next;
    }
    return (count);
}
