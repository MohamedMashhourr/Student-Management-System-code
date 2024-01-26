#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#define NULLPTR ((void*)0)
student_t s;




int main()
{

    node_t* head=NULLPTR;
    student_t test1;
    student_t test2;
    student_t test3;
    listStatus_t state;
    char str[20];

    int i=0,x,c=0,id,z,y,e,g;
    for(i=0;; i++)
    {
        display();

        scanf("%d",&x);
        fflush(stdin); // infinity loop

//*****************************first choice to add student***********************************************//
        if (x==1)
        {
            if(c==0)
            {
                student_add();
                head=student_AddFirst(s);
                c++;
            }
            else
            {

                student_add();
                student_AddToLast(head,s);

            }
        }
//*****************************second choice to print all student****************************************//
        else if(x==2)
        {
            student_PrintAll(head);
        }

//*****************************thired choice to delete student using id**********************************//
        else if(x==3)
        {
            printf("      Enter the ID of sutdent:  ");
            scanf("%d",&id);
            test1.id=id;//**************************************
            state=student_delete(&head,test1);//********************************
            if(state==STUDENT_ID_NOT_FOUND)
            {
                printf("      This ID NOT FOUND\n\n");
            }
        }
//*****************************fourth choice to search for a student*************************************//
        else if (x==4)
        {
            while(1)
            {


                printf("\n      1- Find Using ID Number\n");
                printf("      2- Find Using Name\n");
                printf("      3- Back\n");
                scanf("%d",&z);


            //*******************************//


                if(z==1)                                          //*********searching using id***********//
                {

                    printf("      Enter the ID of sutdent:   ");
                    scanf("%d",&id);
                    test2.id=id;//********************
                    state= student_SearchId(head,test2); //compare the input id with STUDENTS id//************

                    if(state==STUDENT_ID_FOUND) // if the id found what do u need ?

                    {
                        while(1)
                        {


                            printf("\n      1- Print The Details Of The Student\n");
                            printf("      2- EDIT The ID Number\n");
                            printf("      3- EDIT The Phone Number\n");


                            scanf("%d",&y);
                            if(y==1) // Print the details of the student for previous ID
                            {
                                student_PrintId(head,test2);
                                break;
                            }
                            if(y==2) //edit the id for previous id
                            {
                                printf(" Enter The New ID Number:  ");
                                scanf("%d",&id);
                                student_EditId(head,id,test2);
                                break;

                            }
                            if(y==3) //edit the phone number for previous id
                            {
                                printf(" Enter The New Phone Number:  ");
                                string_scan(test2.phone,12);
                                student_EditPhone(head,id,test2);
                                break;
                            }
                        }
                        break;

                    }
                    else
                    {
                        printf("      This ID NOT FOUND\n\n");
                    }

                }


            //*******************************//


                else if(z==2)                                            //*********search using name***********//
                {
                    printf("      Enter the NAME of sutdent:   ");
                    string_scan(&test3.name,20);

                    state= student_SearchName(head,test3); //compare the input Name with STUDENTS Name

                    if(state==STUDENT_NAME_FOUND) // if the name found what do u need ?

                    {
                        while(1)
                        {


                            printf("\n      1- Print The Details Of The Student\n");
                            printf("      2- EDIT The ID Number\n");
                            printf("      3- EDIT The Phone Number\n");



                            scanf("%d",&g);
                            if(g==1) // Print the details of the student for previous Name************
                            {
                                student_PrintName(head,test3);
                                break;
                            }
                            if(g==2) //edit the id for previous Name***************
                            {
                                printf(" Enter The New ID Number:  ");
                                scanf("%d",&id);

                                student_EditIdByName(head,id,test3);
                                break;
                            }
                            if(g==3) //edit the phone number for previous Name************
                            {
                                printf(" Enter The New Phone Number:  ");
                                string_scan(test3.phone,12);
                                student_EditPhoneByName(head,test3);

                                break;
                            }


                        }
                    }
                    else
                    {
                        printf("      This Name NOT FOUND\n\n");
                    }

                    break;
                }


        //********************************//

                else if (z==3)                                                //*********BACK***********//
                {
                    break;
                }

                else                                                        //*******WORNG INPUT*******//
                {
                    printf("\n  WORNG INPUT PLEASE TRY AGAIN\n");
                }


            }
        }
//*******************fifth choice to sort the student list according to ID numbers *******************//
        else if (x==5)
        {
            while(1)
            {
                printf("\n      1- Sorting Using ID \n");
                printf("      2- Sorting Using Age\n");
                printf("      3- Back\n");
                scanf("%d",&e);
                if(e==1) //**********Sorting Using ID**********//
                {
                    head = student_SortList(head);
                    break;
                }
                else if (e==2) //*********Sorting Using Age**********//
                {
                    head = student_SortListAge(head);
                    break;
                }
                else if (e==3) //*********BACK***********//
                {
                    break;
                }
                else //********FOR WRONG INPUT************//
                {
                    printf("\n  WORNG INPUT PLEASE TRY AGAIN\n");
                }

            }
        }
//*****************************final choice to count the total number of student*********************//
        else if (x==6)
        {
            int countSt =student_count(head);
            printf("\nThe Total Number Of Students is = %d\n\n",countSt);
        }
//******************************************** EXIT ************************************************//
        else if (x==7)
        {
            return 0;
        }
//********************************************WORNG DATA*******************************************//
        else
        {
            printf("\n  WORNG INPUT PLEASE TRY AGAIN\n");

        }


    }



    return 0;
}
