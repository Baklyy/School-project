
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

typedef struct student {
  s8 name[50];
  s8 birthday[11];
  u16 ID;
  s8 address[100];
  s8 phone[12];
  struct student* next;
  s8 math,english,cs,physics;


}student;
student* head=NULL;

void addfirst(student ** ptr,student **head)
{
    (*ptr)->next=(*head);
    (*head)=(*ptr);

}
void NEW_STUDENT()
{
  student* ptr=(student*)malloc(sizeof(student));
  printf("\nEnter Student name : ");
 scanf(" %[^\n]",ptr->name);
  printf("\n Enter Student birthday (dd/mm/yyyy) : ");
  scanf("%s",ptr->birthday);
  printf("\n Enter Student ID : ");
  scanf("%d",&(ptr->ID));
  printf("\n Enter Student address");
  scanf(" %[^\n]",ptr->address);
  printf("\n Enter Student phone number : ");
  scanf("%s",ptr->phone);

   addfirst(&ptr,&head);
}
void STUDENT_LIST()
{
    student* current=head;
    if (head==NULL)
    {
        printf("There are no students to display !\n");
    }
    while (current!=NULL)
    {
        printf("\n Student name : %s\n",current->name);
        printf("Student ID : %d\n",current->ID);
        printf("Address : %s\n",current->address);
        printf("Date of birth : %s\n",current->birthday);
        printf("Phone Number : %s\n",current->phone);
        printf("======================================\n");
        current=current->next;
    }
}
void DELETE_STUDENT()
{
    u16 x;
    printf("Please enter Student ID : ");
    scanf("%d",&x);
    student* current=head;
    student* previous=head;
    if (current->ID==x)
    {
        head=current->next;
        free(current);
        return;
    }

    while (current!=NULL)
    {
        if (current->ID==x)
        {
            previous->next=current->next;
            free(current);
            printf("Student has been removed !\n");
            printf("======================================\n");
            return;
        }
        previous=current;
        current=current->next;
    }
    printf("Student ID Not found\nPlease try again\n");
}
 void STUDENT_EDIT()
 {
     u16 x,tempID;
     printf("\nPlease enter the Student ID : ");
     {
         scanf("%d",&x);
     }
     student* current=head;
     while (current!=NULL)
     {
         if (current->ID==x)
         {
             int choice;
             while (1)
             {

             printf("(1) Edit ID\n");
             printf("(2) Edit Name\n");
             printf("(3) Edit phone number\n");
             printf("(4) Edit date of birth\n");
             printf("(5) Edit student address\n");
             printf("(6) Exit editting \n");

             scanf("%d",&choice);
             switch(choice)
             {
             case 1:
                printf("\nPlease enter the new student ID : ");
                scanf("%d",&tempID);
                // searching for ID Avaialblity
                student* current2=head;
                while(current2!=NULL)
                {
                    if (tempID==current2->ID)
                    {
                        printf("This ID is not avaialble please try again\n");
                        printf("======================================\n");
                        break;

                    }
                    current2=current2->next;
                }
                current->ID=tempID;
                printf("ID Has been updated successfully \n");
                printf("======================================\n\n");
                break;
             case 2:
                printf("Enter new student name : ");
                   scanf(" %[^\n]",current->name);
                   printf("Student name has been updated Successfully\n");
                   printf("======================================\n\n");
                   break;
             case 3:
                printf("Enter the new phone number : ");
                scanf(" %[^\n]",current->phone);
                printf("Phone number has been updated Successfully\n");
                printf("======================================\n\n");
                break;
             case 4:
                printf("Enter the new date of birth : ");
                scanf(" %[^\n]",current->birthday);
                printf("Date of birth has been updated Successfully\n");
                printf("======================================\n\n");
                break;
              case 5:
                printf("Enter the student address : ");
                scanf(" %[^\n]",current->address);
                printf("Address has been updated Successfully\n");
                printf("======================================\n\n");
                break;
              case 6:
                return;
              default:
                printf("Invalid choice ! \nPlease try again \n");




             }

         }}
         current=current->next;
     }
     printf("Invalid Student ID !\n");
 }

