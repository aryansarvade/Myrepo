#include "acc_hash.h"
#include "pin_hash.h"
#include "movie_hash.h"
#include <stdio.h>

struct booking_details
{
    char name[25]; //Name of the person who has booked the ticket
    long int phone;
    int movie_no;
    int seat;
    int id;
};

struct booking_details person[500];

int changeprize(int);
void reservation(int *array, int price,int selection, char *movie_name);
int choice1();
void cancel(int *);        
void ticket1(int array[],char name[10],int id2,int price);
void ticket2(int arrya[],char name[10],int id2,int price);
void ticket3(int array[],char name[10],int id2,int price);
int canc_movie_num();
void details();
int UpdateAccountBalance(char *name, int price); //returns updated account number of the Username.
void put_movies();