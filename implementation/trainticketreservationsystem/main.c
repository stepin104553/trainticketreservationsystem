#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"trainticketreservationsystem.h"
#include<string.h>
#include<windows.h>
int enterchoice();
int add_trains();
int view_trains();
int check_train_no(char *trainno);
Passenger* get_passenger_datails();
int check_mob_no(char *p_mob);
int get_booked_ticket_count(char*train_no,char c);
int last_ticket_no();
int book_ticket(Passenger p);
int accept_ticket_no();
void view_ticket(int ticket_no);
int cancel_ticket(int ticket_no);
char* accept_mob_no();
int* get_ticket_no(char *p_mob_no);
void view_all_tickets(char*pmob_no,int*pticket_no);
char* accept_train_no();
void view_bookings(char* train_no);
void view_all_bookings();
int cancel_train(char *train_no);
int test_main();

int main()

{
    Passenger *ptr;
    int ch;
    int ticket_no;
    int result;
    add_trains();
    char*pmob_no;
    int *pticket_no;
    char *ptrain_no;
    char username[20];
    char pwd[15];
    int i;
    new:
    gotoxy(26,1);
    textcolor(13);
    for(i=1;i<=30;i++)
    printf("-");
    gotoxy(28,2);
    textcolor(11);
    printf("RAILWAY RESERVATION SYSTEM");
    gotoxy(26,3);
    textcolor(13);
    for(i=1;i<=30;i++)
    printf("-");
    gotoxy(18,6);
    textcolor(14);
    printf(":::::LOGIN:::::");
    gotoxy(18,8);
    textcolor(12);
    printf("ENTER USERNAME: ");
    textcolor(15);
    scanf("%s",username);
    gotoxy(18,10);
    textcolor(12);
    printf("ENTER PASSWORD: ");
    textcolor(15);
    for(i=0;i<=7;i++)
    {
        pwd[i]=getch();
        printf("*");
    }
    pwd[i]='\0';
    getch();
    textcolor(10);
    printf("\n\n\n\n\tPassword Verfication Under process.Please wait!........");
    Sleep(2000);
    if((strcmp(username,"RUCHITHA@PAGADALA")==0)&&(strcmp(pwd,"12345678")==0))
    {

    }
    else
    {
        clrscr();
        textcolor(8);
        printf("\n\n incorrect! Username or Password. ");
        textcolor(13);
        printf("\n\nPress any key to re-login");
        getch();
        clrscr();
        goto new;
    }

    clrscr();
    while(1)
    {
      clrscr();
      ch=enterchoice();
      if(ch==9)
      {
         exit(0);
      }
      else
      {
         switch(ch)
         {
         case 1:
           view_trains();
           break;
         case 2:
            ptr=get_passenger_datails();
            if(ptr!=NULL)
            {
               ticket_no=book_ticket(* ptr);
               if(ticket_no==-1)
               {
                  textcolor(10);
                  printf("\n\nBooking Failed!");
               }
               else
               {
                  textcolor(10);
                  printf("\nCongratulations! Successfully Booked a Ticket.\n");
                  textcolor(12);
                  printf("\nYour ticket no  ");
                  textcolor(14);
                  printf("%d\n\n",ticket_no);
               }
             }
            textcolor(13);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
         case 3:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
                view_ticket(ticket_no);
            textcolor(13);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
         case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            textcolor(13);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
         case 5:
            clrscr();
            view_all_bookings();
            textcolor(13);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
         case 6:
             clrscr();
             ptrain_no=accept_train_no();
             if(ptrain_no!=NULL)
             {
                 view_bookings(ptrain_no);
             }
             textcolor(13);
             printf("\nPress any key to go back to the main screen");
             getch();
             clrscr();
             break;
         case 7:
             clrscr();
             ticket_no=accept_ticket_no();
             if(ticket_no!=0)
             {
                 result=cancel_ticket(ticket_no);
                 if(result==0)
                 {
                         textcolor(12);
                         printf("\nSorry! No tickets booked against ticket no ");
                         textcolor(11);
                         printf("%d\n\n",ticket_no);
                 }
                else if(result==1)
                 {
                        textcolor(10);
                        printf("\nTicket no ");
                        textcolor(12);
                        printf("%d",ticket_no);
                        textcolor(10);
                        printf(" successfully cancelled!\n\n");
                 }

             }
             textcolor(13);
             printf("\nPress any key to go back to the main screen");
             getch();
             clrscr();
             break;
         case 8:
             clrscr();
             ptrain_no=accept_train_no();
             if(ptrain_no!=NULL)
             {
                result=cancel_train(ptrain_no);
                if(result==0)
                {
                    textcolor(12);
                    printf("\nSorry! No Trains against Train no ");
                    textcolor(11);
                    printf("%s\n\n",ptrain_no);
                }
                else if(result==1)
                {
                    textcolor(10);
                    printf("\nTrain no ");
                    textcolor(12);
                    printf("%s",ptrain_no);
                    textcolor(10);
                    printf(" successfully cancelled!\n\n");
                }

             }
            textcolor(13);
            printf("\nPress any key to go back to the main screen");
            getch();
            clrscr();
            break;
         default:
            textcolor(8);
            printf("\nWrong Choice! Try Again.");
            getch();
            clrscr();
test_main();
    return 0;
         }
     }
 }
getch();
return 0;

}
