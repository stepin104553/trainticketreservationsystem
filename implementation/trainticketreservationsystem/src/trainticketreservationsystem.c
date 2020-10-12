
#include<stdio.h>
#include"conio2.h"
#include "trainticketreservationsystem.h"
#include<string.h>
#include<ctype.h>
#include<windows.h>


int enterchoice()
{

    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1; i<=40; i++)
    printf("_ ");
    textcolor(10);
    printf("\nSelect an Option:");
    textcolor(12);
    printf("\n\n1.View Trains\n2.Book Ticket\n3.View Ticket\n4.Search Ticket No\n5.View All Bookings\n6.View Train Bookings\n7.Cancel Ticket\n8.Cancel Train\n9.Quit");
    textcolor(14);
    printf("\n\nEnter your choice:");
    textcolor(15) ;
    scanf("%d",&choice);
    return choice;
    getch();

}
int add_trains()
{
    FILE *fp;
    fp=fopen("c:\\My Project \\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[10]= {{"123","BPL","GWA",2100,1500},{"546","BPL","DEL",3500,2240},{"345","HBJ","AGR",1500,1135},{"896","HBJ","MUM",4500,3600},{
        "785","DEL","BPL",3000,2200},{"186","GWA","BPL",3200,2830},{"235","AGR","HBJ",3900,2480},{"762","MUM","HBJ",5600,4560},{"464","GWA","HBJ",2340,1120},{"231","DEL","MUM",1200,990}};
        fp=fopen("c:\\My Project\\alltrains.dat","wb");
        fwrite(alltrains,10*sizeof(Train),1,fp);
        printf("File Saved Successfully!\n");
        fclose(fp);
    }
    else
    {
        fclose(fp);
    }
}
int view_trains()
{
    clrscr();
    int i;
    textcolor(14);
    printf("\nTRAIN NO\tFROM\t\tTo\tFIRST AC FARE\t\tSECOND AC FARE \n");
    for(i=1; i<=40; i++)
    printf("_ ");
    printf("\n");
    FILE  *fp=fopen("c:\\My Project\\alltrains.dat","rb");
    Train tr;
    textcolor(15);
    while(fread(&tr,sizeof(tr),1,fp)==1)
    printf("%s\t\t%s\t\t%s\t%d\t\t\t%d\n",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    textcolor(14);
    for(i=1; i<=40; i++)
    printf("_ ");
    textcolor(13);
    printf("\n\n\nPress any key to go back to the main screen");
    fclose(fp);
    getch();
}

int check_train_no(char *trainno)
{

    FILE* fp=fopen("c:\\My Project\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

Passenger* get_passenger_datails()
{
    clrscr();
    gotoxy(55,1);
    textcolor(10);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(14);
    printf("Enter passenger name:");
    static Passenger psn;
    fflush(stdin);
    textcolor(15);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(12);
        gotoxy(1,22);
        printf("Reservation Cancelled!");
        return NULL;
    }
    int valid;
    textcolor(14);
    printf("Enter gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        textcolor(15);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reservation Cancelled!");
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            textcolor(12);
            gotoxy(1,22);
            printf("Error! Gender should be M or F (in uppercase)");
            valid=0;
            getch();
            gotoxy(19,2);
            printf("\t\t\t");
            gotoxy(19,2);
        }

    }
    while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    textcolor(14);
    printf("Enter train number:");
    do
    {
        textcolor(15);
        fflush(stdin);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reservation Cancelled!");
            return NULL;
        }
        valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("Error! Invalid Train No");
            getch();
            gotoxy(20,3);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(20,3);
        }

    }
    while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,4);
    textcolor(14);
    printf("Enter travelling class(First AC-F/Second AC-S):");
    do
    {
        valid=1;
        fflush(stdin);
        textcolor(15);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reservation Cancelled!");
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            textcolor(12);
            gotoxy(1,22);
            printf("Error! Travelling class should be F or S (in uppercase)");
            valid=0;
            getch();
            gotoxy(48,4);
            printf("\t\t\t");
            gotoxy(48,4);
        }

    }
    while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    textcolor(14);
    printf("Enter address:");
    fflush(stdin);
    textcolor(15);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(12);
        gotoxy(1,22);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,22);
        printf("Reservation Cancelled!");
        return NULL;
    }
    gotoxy(1,6);
    textcolor(14);
    printf("Enter age:");
    do
    {
        valid=1;
        fflush(stdin);
        textcolor(15);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reservation Cancelled!");
            return NULL;
        }
        if(psn.age<0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("Error! Age should be positive");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t\t");
            gotoxy(11,6);
        }
    }
    while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t\t\t");
    gotoxy(1,7);
    textcolor(14);
    printf("Enter Mobile number:");
    do
    {
        textcolor(15);
        fflush(stdin);
        scanf("%s",psn.mob_no);
        if(strcmp(psn.mob_no,"0")==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Reservation Cancelled!");
            return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Error! Invalid Mobile No");
            getch();
            gotoxy(21,7);
            printf("\t\t\t\t\t\t");
            gotoxy(21,7);
        }
    }
    while(valid==0);
    gotoxy(1,22);
    printf("\t\t\t\t\t");
    gotoxy(1,10);
    textcolor(11);
    printf("Please wait!Ticket booking is under process");
    for(int i=0;i<=3;i++)
    {
     printf(".");
     Sleep(1000);
    }
    clrscr();
    return &psn;
}

int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
    {
        return 0;
    }
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
        {
            return 0;
        }
        p_mob++;
    }
   return 1;
}
int get_booked_ticket_count(char*train_no,char c)
{
    Passenger pr;
    int count=0;
    FILE*fp=fopen("c:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==c)
        {
            count++;
        }
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    Passenger pr;
    FILE*fp=fopen("c:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;

}

int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==30)
    {
        textcolor(12);
        printf("\nAll Seats full in train no. ");
        textcolor(14);
        printf("%s" ,p.train_no);
        textcolor(12);
        printf(" in ");
        textcolor(14);
        printf("%c",p.p_class);
        printf(" class");
        return -1;

    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;

    FILE *fp=fopen("c:\\My Project\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(12);
        printf("\nSorry!File can not be opened");
        return -1;

    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;

}
int accept_ticket_no()
{
    clrscr();
    gotoxy(55,1);
    textcolor(10);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(14);
    printf("Enter ticket no:");
    int valid;
    int ticket_no;
    do
    {
        textcolor(15);
        scanf("%d",&ticket_no);
        valid=1;
        if(ticket_no==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t");
            gotoxy(1,22);
            printf("Cancelling input...");
            return 0;
        }
        if(ticket_no<0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t");
            gotoxy(1,22);
            printf("Error!Ticket number should be positive");
            valid=0;
            getch();
            gotoxy(17,1);
            printf("\t\t\t");
            gotoxy(17,1);
        }
    }while(valid==0);
    return ticket_no;
    clrscr();
}

void view_ticket(int ticket_no)
{
    clrscr();
    FILE*fp=fopen("c:\\My Project\\allbookings.dat","rb");
    FILE *fp1=fopen("c:\\My Project\\alltrains.dat","rb");
    if(fp==NULL)
    {
        textcolor(12);
        printf("\nNo bookings done yet");
        return;
    }
    if(fp1==NULL)
    {
        textcolor(12);
        printf("\nNo trains done yet");
        return;
    }
    Passenger pr;
    Train tr;

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(ticket_no==pr.ticketno)
        {
            textcolor(14);
            printf("DETAILS OF TICKET NO:");
            textcolor(12);
            printf("%d\n",pr.ticketno);
            textcolor(10);
            printf("\nName:");
            textcolor(11);
            printf("%s",pr.p_name);
            textcolor(10);
            printf("\nGENDER:");
            textcolor(11);
            printf("%c",pr.gender);
            textcolor(10);
            printf("\nTRAIN NO:");
            textcolor(11);
            printf("%s",pr.train_no);
            textcolor(10);
            printf("\nCLASS:");
            textcolor(11);
            printf("%c",pr.p_class);
            textcolor(10);
            printf("\nADDRESS:");
            textcolor(11);
            printf("%s",pr.address);
            textcolor(10);
            printf("\nAGE:");
            textcolor(11);
            printf("%d",pr.age);
            textcolor(10);
            printf("\nMOBILE NO:");
            textcolor(11);
            printf("%s",pr.mob_no);
            textcolor(10);
            printf("\nTICKET NO:");
            textcolor(11);
            printf("%d",pr.ticketno);
            while(fread(&tr,sizeof(tr),1,fp1)==1)
            {
            if(strcmp(pr.train_no,tr.train_no)==0)
            {
                 textcolor(10);
                 printf("\nFROM:");
                 textcolor(11);
                 printf("%s",tr.from);
                 textcolor(10);
                 printf("\nTO:");
                 textcolor(11);
                 printf("%s",tr.to);
                 if(pr.p_class=='F')
                 {
                     textcolor(10);
                     printf("\nFARE:");
                     textcolor(11);
                     printf("%d",tr.fac_fare);
                 }
                 else
                 {
                     textcolor(10);
                     printf("\nFARE:");
                     textcolor(11);
                     printf("%d",tr.sac_fare);
                 }
             }
             }
             fclose(fp);
             fclose(fp1);
             printf("\n\n");
             return;
             }
    }
    textcolor(12);
    printf("\nNo details of ticket no ");
    textcolor(11);
    printf("%d",ticket_no);
    textcolor(12);
    printf(" found!");
    fclose(fp);
    printf("\n\n");
}
int cancel_ticket(int ticket_no)
{
    FILE*fp1=fopen("c:\\My Project\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(12);
        printf("\nNo bookings done yet");
        return -1;

     }
     FILE*fp2=fopen("c:\\My Project\\temp.dat","wb+");
     Passenger pr;
     int found=0;
     while(fread(&pr,sizeof(pr),1,fp1)==1)
     {
         if(pr.ticketno!=ticket_no)
         {
             fwrite(&pr,sizeof(pr),1,fp2);
         }
         else
         {
             found=1;
         }

     }
     fclose(fp1);
     fclose(fp2);
     if(found==0)
     {
         remove("c:\\My Project\\temp.dat");
     }
     else
     {
        remove("c:\\My Project\\allbookings.dat");
        rename("c:\\My Project\\temp.dat","c:\\My Project\\allbookings.dat");
     }
   return found;
}
char* accept_mob_no()
{
    static char mob_no[11];
    int valid;
    gotoxy(55,1);
    textcolor(10);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(14);
    printf("Enter Mobile number:");
    do
    {
        textcolor(15);
        fflush(stdin);
        scanf("%s",mob_no);
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Cancelling Input...!");
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Error! Invalid Mobile No");
            getch();
            gotoxy(21,1);
            printf("\t\t\t");
            gotoxy(21,1);
        }
    }while(valid==0);
    clrscr();
    return mob_no;
}
int* get_ticket_no(char *p_mob_no)
{
    int count=0;
    FILE *fp;
    fp=fopen("c:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
         ++count;
        }

    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int*p= (int *)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;

}
void view_all_tickets(char*pmob_no,int*pticket_no)
{
if(pticket_no==NULL)
{
    textcolor(12);
    printf("\nSorry!No Tickets booked against mobile no. ");
    textcolor(14);
    printf("%s",pmob_no);
    printf("\n\n");
    return;
}
textcolor(14);
printf("\nFollowing tickets are booked for mobile no. ");
textcolor(15);
printf("%s",pmob_no);
int i;
textcolor(10);
printf("\n\nTICKET NO:\n");
textcolor(12);
printf("---------");
textcolor(11);
for(i=0;*(pticket_no+i)!=-1;i++)
{
    printf("\n%d",*(pticket_no+i));
}
printf("\n\n");
free(pticket_no);
}

char* accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(55,1);
    textcolor(10);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(14);
    printf("Enter train number:");
    do
    {
        textcolor(15);
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,22);
            printf("Cancelling Input...!");
            return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            textcolor(12);
            gotoxy(1,22);
            printf("Error! Invalid Train No");
            getch();
            gotoxy(20,1);
            printf("\t\t\t\t");
            gotoxy(20,1);
        }

    }
    while(valid==0);
    clrscr();
    return train_no;
}
void view_bookings(char* train_no)
{

    int found=0,i;
    FILE*fp=fopen("c:\\My Project\\allbookings.dat","rb");
    Passenger pr;
    textcolor(12);
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\t\tMOBILE NO\n");
    textcolor(14);
    for(i=1;i<=80;i++)
        printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            textcolor(15);
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row++);
            printf("%c\t%d\t\t%s\n",pr.gender,pr.age,pr.mob_no);
            found=1;
        }
    }
    textcolor(14);
    for(i=1;i<=80;i++)
      printf("-");
    if(!found)
    {
        clrscr();
        textcolor(12);
        printf("\nNo details of train no ");
        textcolor(14);
        printf("%s",train_no);
        textcolor(12);
        printf(" found!");
    }
    printf("\n\n");
    fclose(fp);
}
void view_all_bookings()
{
    int i;
    FILE*fp=fopen("c:\\My Project\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(12);
        printf("\nNo bookings done yet!\n");
        return;
    }
    Passenger pr;
    textcolor(12);
    printf("TRAIN NO\tTICKET NO\tCLASS\tNAME\t\tAGE\tMOBILE NO\n");
    textcolor(14);
    for(i=1;i<=80;i++)
        printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
            textcolor(15);
            printf("%s\t\t%d\t\t%c\t%s",pr.train_no,pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(57,row++);
            printf("%d\t%s\n",pr.age,pr.mob_no);

    }
    textcolor(14);
    for(i=1;i<=80;i++)
    printf("-");
    printf("\n");
    fclose(fp);
}
int cancel_train(char *train_no)
{
    FILE*fp1=fopen("c:\\My Project\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(12);
        printf("\nNo Trains done yet");
        return -1;

    }
     FILE*fp2=fopen("c:\\My Project\\data.dat","wb+");
     Passenger pr;
     int found=0;
     while(fread(&pr,sizeof(pr),1,fp1)==1)
     {
         if(strcmp(pr.train_no,train_no)!=0)
         {
             fwrite(&pr,sizeof(pr),1,fp2);
         }
        else
         {
             found=1;
         }
     }
     fclose(fp1);
     fclose(fp2);
     if(found==0)
     {
         remove("c:\\My Project\\data.dat");
     }
     else
     {
        remove("c:\\My Project \\allbookings.dat");
        rename("c:\\My Project\\data.dat","c:\\My Project\\allbookings.dat");
     }
return found;
clrscr();
}

