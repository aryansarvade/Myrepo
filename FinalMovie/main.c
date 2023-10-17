#include <stdio.h>
#include "system.h"
#include <stdlib.h>

int main()
{
    int **seat;
    int choice;
    int price=500;
    int selection,i; //selection is the movie selection integer
    seat=(int **)malloc(101 * sizeof(int *));

	for (i = 0 ;i < 101 ; i++)
        seat[i]=(int *)malloc(101 * sizeof(int));

    fill_AcNo_bal();
    fill_AcNo_pin_Hash();
    fill_num();
    
    put_movies();
    
	/* Row(movie) 0 - 0 1 2 3 4 5 .... 100 (101 times from 0-100)

	   Row 1 - 0 1 2 3 4 5 .... 100

	   Row 2 - 0 1 2 3 4 5 .... 100

	   total 303 seats */

/*0 indicates that the seat is not booked, while 1 indicates that the seat is booked.*/

	int x = 1; //Let's say 'x' is 1.

	while(x!=5)
	{
        choice=choice1();

		switch(choice)
		{

			case 1:

				price = changeprize(price);

				break;

			case 2:

				details();

				break;	

			case 3:

                printf("\t\t\tWhich movie you want to see? Enter it's name: ");
                char movie_name[40];
                scanf("%s", movie_name);
                printf("\n\t\t\t----------------------------------------------\n\n");
                selection = retrieve_movie_num(movie_name);
                while(selection == -1) //Movie not found
                {
                    printf("\nTHE REQUESTED MOVIE IS NOT AVAILABLE.\nPLEASE ENTER CORRECT NAME OF THE MOVIE: ");
                    scanf("%s", movie_name);
                    selection = retrieve_movie_num(movie_name);       
                }
                reservation(seat[selection-1], price, selection, movie_name);
                break;

			case 4:
                printf("\t\t\tEnter the name of the movie from which seat is to be cancelled: ");
                char movie_name2[40];
                scanf("%s", movie_name2);
                selection = retrieve_movie_num(movie_name2);
                while(selection == -1) //Movie not found
                {
                    printf("\nTHE REQUESTED MOVIE IS NOT AVAILABLE.\nPLEASE ENTER CORRECT NAME OF THE MOVIE: ");
                    scanf("%s", movie_name2);
                    selection = retrieve_movie_num(movie_name2);       
                }
                cancel(seat[selection-1]);	
                break;

			case 5:

				x=5;

				break;

			default: 

				printf("Please Enter a valid choice\n");

				break;	

		}

	}
    return 0;
}