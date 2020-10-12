/**
* @mainpage train ticket reservation System  by Ruchitha Pagadala with PS:ID-104256 @subpage trainticketreservationsystem.h
* @file trainticketreservationsystem.h
*/
#ifndef TRAINTICKETRESERVATIONSYSTEM_H_INCLUDED
#define TRAINTICKETRESERVATIONSYSTEM_H_INCLUDED
/**
* details of the train
*/
struct Train
{
    char train_no[10];    /* for storing train_no */
    char from[10];        /* for storing from station code */
    char to[10];          /* for storing to station code */
    int fac_fare;         /* for storing fac_fare of First AC */
    int sac_fare;         /* for storing sac_fare  of Second AC */
};
/**
* details of the PASSENGER
*/
struct Passenger
{
    char p_name[20];     /* for storing name of a passenger */
    char gender;         /* for storing gender of passenger */
    char train_no[10];   /* for storing train number */
    char p_class;        /* for storing the F for first AC and S for second AC */
    char address[30];    /* for address of the passenger */
    int age;             /* for storing passenger age */
    int ticketno;        /* for storing ticketno */
    char mob_no[11];     /* for storing passengers mob_no */
};
typedef struct Train Train;
typedef struct Passenger Passenger;
/**
* For displaying available options to the user
* @return the enterchoice by him/her
*/

int enterchoice();
/**
* add_trains details to a file
*/
int add_trains();
/**
* displaying the details of all the view_trains from the file
*/
int view_trains();
/**
* accept a passenger and book the ticket
* @return ticket number
* @return -1
*/
int book_ticket(Passenger);
/**
* accept a passengers mobile number
* @return all ticket numbers
* @return NULL
int* get_ticket_no(char*);
/**
* accept a ticket number
* display the ticket details
*/
void view_ticket(int);
/**
* display all the booked tickets
*/
void view_all_bookings();
void view_bookings(char*);  /* display the ticket booked for that train */
/**
* cancel_ticket
* @return 1
* @return 0
*/
int cancel_ticket(int);
/**
* cancel_train
* @return 1
* @return 0
*/
int cancel_train(char*);

Passenger* get_passenger_datails();
int check_train_no(char*);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int book_ticket(Passenger);
int check_mob_no(char*);
int accept_ticket_no();
char* accept_mob_no();
void view_all_tickets(char*,int*);
char* accept_train_no();



#endif // TRAINTICKETRESERVATIONSYSTEM_H_INCLUDED
