#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include <string.h>
#include <time.h>

int id2 = 1000;
int count = 0;

int changeprize(int prize)
{
	char pass[10],pak[10]="pass";
	printf("Enter the password to change price of ticket: ");
	scanf("%s",pass);
	if (strcmp(pass,pak)==0)
	{
		printf("Please enter new price: ");
		scanf("%d",&prize);
	}
	else 
		printf("The entered password is wrong! ");
	return prize;
}

void reservation(int *array, int price, int selection, char *movie_name)
{
    time_t t;
    time(&t);
    int i,j;
    printf("\n\t\tSCREEN FOR ~~ %s ~~\n(0 - available , 1 - booked)\n\n", movie_name);
    for (i = 1 ; i <= 100 ; i++)
    {
        if (array[i] == 0)
            printf("0 - %d \t",i);
        else if(array[i] == 1)
            printf("\e[1m1 - %d \e[m\t",i);
        if(i%10 == 0)
            printf("\n\n");
    }
        printf("\n\nEnter seat Number to be booked:(1-100) : ");
        scanf("%d",&j);
        while(j > 100 || j < 1)
        {
            printf("The requested seat number is unavailable in this theater\n");
            printf("Please re-enter seat number: ");
            scanf("%d",&j);
        }
        while(array[j] == 1)
        {
            printf("\nSorry, this ticket is already booked! Please choose another seat: ");
            scanf("%d",&j);
        }

        printf("\n\n======================= BOOKING DETAILS =========================");
        
        printf("\n\nPlease enter your name: ");
        char booking_name[25];
        scanf("%s", booking_name);
        long int booking_phone;
        printf("\nPlease enter your phone number: ");
        scanf("%ld",&booking_phone);
        
        insert_in_accHash(booking_name);
        
    printf("\nYour Account details are as follows:\n");
    retrieve_acc_details(booking_name);
    int pin = retrieve_pin(retrieve_acc_num(booking_name));
    printf("\nThe Account PIN is: %d\n", pin);
    
    printf("\n~~~~~~~~~~~~~~ TRANSACTION ~~~~~~~~~~~~~~");
    
    printf("\nThe price of the ticket is: %d", price);
    printf("\nThe amount deducted will be %d", price);
    
    if(retrieve_bal(booking_name) < price)
    {
        printf("\nInsufficient Balance in your account\nCannot initiate payment");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        return;
    }
    printf("\n\nEnter PIN to initiate payment: ");
    int enter_pin;
    scanf("%d",&enter_pin);
    if(enter_pin == pin)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\nPayment was successful\n~~~SEAT BOOKED~~~\n");
        int n = UpdateAccountBalance(booking_name, price);
        printf("\n\e[1mThe Balance remaining after transaction is: %d\e[m\n", n);
        
        printf("\n========== BOOKING DETAILS ==========\n");
        
        strcpy(person[count].name, booking_name);
        printf("\nBooking name is: %s\n",person[count].name);
        person[count].phone = booking_phone;
        printf("\nBooking Phone number is: %ld\n",person[count].phone);
        person[count].movie_no = selection;
        printf("\nBooking Theatre number is: %d\n",person[count].movie_no);        
        person[count].seat = j;
        printf("\nBooking seat number is: %d\n",person[count].seat);
        person[count].id = id2;
        printf("\nBooking ID number is: %d\n",person[count].id);
        printf("\nBooking Date & Time is: %s\n", ctime(&t));
        printf("\n=====================================\n");
        count++;
        id2++;
                
        if(array[j] == 0)
        {
            array[j] = 1;
        }

        printf("\n\t\tSCREEN FOR ~~ %s ~~\n(0 - available , 1 - booked)\n\n", movie_name);

        for (i = 1 ; i <= 100 ; i++)
        {
            if (array[i] == 0)
                printf("0 - %d \t",i);
            else if(array[i] == 1)
            printf("\e[1m1 - %d \e[m\t",i);
            if(i%10 == 0)
                printf("\n\n");
        }
        printf("\n~~~~~ THANK YOU & PLEASE VISIT NEXT TIME. HAVE A GOOD DAY!! ~~~~~\n");
        return;
    }
    else
    {
        system("clear");
        printf("\nSorry PIN entered was wrong, process terminated\n");
        printf("\n================================================\n");
        return;
    }
}

int choice1(void)

{
	int choice;

	printf("                 \nSimple Movie Ticket Booking System\n");

	printf(" ==================================================================\n");

	printf("||             1- To edit price of ticket (only admin):           ||\n");

	printf("||             2- To view reserved tickets (only admin):          ||\n");

	printf("||             3- To puchase ticket:                              ||\n");

	printf("||             4- To cancel the seat:                             ||\n");

	printf("||             5- Exit system:                                    ||\n");

	printf("||================================================================||\n");

	printf("  Enter your choice: ");

	scanf("%d",&choice);

	return choice;

}

void cancel(int *array)
{
    int id_num,i;
    printf("Please enter Booking ID number on your ticket: ");
    scanf("%d",&id_num);

    for (i = 0 ; i < 500; i++)
    {
        if(id_num == person[i].id)
        {
            printf("\n%s your seat is %d cancelled\n\n",person[i].name,person[i].seat);
            array[person[i].seat] = 0;
            person[i].seat = 0;
            person[i].id = 0;
            person[i].phone = 0;
            person[i].movie_no = 0;
            count --;
            for(int j = 1 ; j <= 100 ; j++)
            {
                if (array[j] == 0)
                    printf("0 - %d \t",j);
                else if(array[j] == 1)
                    printf("\e[1m1 - %d \e[m\t",j);
                if(j%10 == 0)
                {
                    printf("\n\n");
                    
                }                
            }
            break;
        }
    }
    if (i == 500)
    {
        printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
    }
    return;
}


void details(void)
{
    int i;
    char pass[10],pak[10]="pass";
    printf("Enter the password to see details: ");
    scanf("%s",pass);
    if (strcmp(pass,pak)==0)
    {
        for (i=0;i<count;i++)
        {
            printf("\nseat no: %d is booked by booking id %d\n",person[i].seat,person[i].id);

        }
    }
    else
    {
        printf("Entered password is wrong \n");
    }
return;
}             


int UpdateAccountBalance(char *name, int price)
{
    int hash_index = Hash_function(name);
    if(!(hash_index <= acc_hash_size - 1))
    {
        printf("The account Hash function returns a hash_index which is not in the bounds of Hash table.\n");
        return -1;
    }
    if(strcmp(acc_Hash[hash_index]->name, " ") == 0)  //No account details exist for the given username
    {
        printf("Sorry, account details for the given username do not exist\n");
        return -1;
    }
    else //Account details exist for the given username
    {
        /*Checking whether we are updating the account balance for the given username or a username whose hash_index
         * collided with the hash_index of given username*/
        
        struct account_details *ptr = acc_Hash[hash_index];
        
        while(strcmp(ptr->name, name) != 0 && (ptr != NULL))
        {
            //given username matches the username in the evaluated hash_index
            ptr = ptr->next;
        }
        /*There are two possibilities to come out of the while loop:
         * 1. Username was found on the hash_index
         * 2. Username was not found and ptr hence became NULL*/
         
         //case 1:
         
        if(strcmp (ptr->name, name) == 0)
        {
            ptr->balance = ptr->balance - price;
            return ptr->balance;
        }
        else if(ptr == NULL)
        {
            printf("Sorry, the given Username's account details do not exist\n");
        }
    }
    return -1;
}

void put_movies()
{
    insert_movie("Avatar");
    insert_movie("Dark_Knight");
    insert_movie("American_Pyscho");
    insert_movie("Interstellar");
    insert_movie("Godfather");
    return;
}