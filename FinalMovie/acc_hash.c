#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acc_hash.h"

/*Creating a Hash Function to input the name of the person and give their account balance from the Hash Table*/

int Hash_function(char *name)
{
    int hash_index = 0;
    for(int i = 0 ; i < strlen(name) ; i++)
    {
        hash_index += name[i];
        hash_index = hash_index % 20;
    }
    return hash_index;
}

void fill_AcNo_bal()
{
    for(int i = 0 ; i < acc_hash_size ; i++)
    {
        acc_Hash[i] = (struct account_details*)malloc(sizeof(struct account_details));
        acc_Hash[i]->name = " ";
        acc_Hash[i]->acc_num = (rand() % (9999999 - 999999 + 1)) + 999999;
        acc_Hash[i]->balance = (rand() % (6000 - 200 + 1)) + 200;
        acc_Hash[i]->next = NULL;
    }
    return;
}

void insert_in_accHash(char *name)
{
    int hash_index = Hash_function(name);
    if(!(hash_index <= acc_hash_size - 1))
    {
        printf("The account Hash function returns a hash_index which is not in the bounds of Hash table.\n");
        return;
    }
    if(strcmp(acc_Hash[hash_index]->name, " ") == 0) /* Indicates no username has been allocated account details on the
     * hash_index of the Hash Table*/
    {
        acc_Hash[hash_index]->name = name;
        return;
    }
    else if(strcmp(acc_Hash[hash_index]->name, name) == 0) //Same Username account details already exist
    {
        return;
    }
        
    struct account_details **ptr = &acc_Hash[hash_index];
    while(strcmp((*ptr)->name , name) != 0 && (*ptr)!=NULL) //Indicates that account details of another username already exist on the hash_index.
    {
        //Use of chaining method to resolve collisions.
        (*ptr) = (*ptr)->next;
    }
    if((*ptr) == NULL)
    {
        *ptr = (struct account_details*)malloc(sizeof(struct account_details));
        (*ptr)->name = name;
        (*ptr)->acc_num = (rand() % (9999999 - 999999 + 1)) + 999999;
        (*ptr)->balance = (rand() % (6000 - 200 + 1)) + 200;
        (*ptr)->next = NULL;
        return;
    }
    else if(strcmp((*ptr)->name , name) == 0)
    {
        return;
    }
}

void retrieve_acc_details(char *name)
{
    int hash_index = Hash_function(name);
    if(!(hash_index <= acc_hash_size - 1))
    {
        printf("The account Hash function returns a hash_index which is not in the bounds of Hash table.\n");
        return;
    }
    if(strcmp(acc_Hash[hash_index]->name, " ") == 0)  //No account details exist for the given username
    {
        printf("Sorry, account details for the given username do not exist\n");
        return;
    }
    else //Account details exist for the given username
    {
        /*Checking whether we are retrieving the account details for the given username or a username whose hash_index
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
            printf("Name - %s\nAccount Number - %ld\nBalance - %d\n", (ptr)->name, (ptr)->acc_num, (ptr)->balance);
            return;
        }
        else if(ptr == NULL)
        {
            printf("Sorry, the given Username's account details do not exist\n");
            return;
        }
    }
    
}

int retrieve_bal(char *name)
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
        /*Checking whether we are retrieving the account balance for the given username or a username whose hash_index
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
            return ptr->balance;
        }
        else if(ptr == NULL)
        {
            printf("Sorry, the given Username's account details do not exist\n");
            return -1;
        }
    }
}

int retrieve_acc_num(char *name)
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
        /*Checking whether we are retrieving the account number for the given username or a username whose hash_index
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
            return ptr->acc_num;
        }
        else if(ptr == NULL)
        {
            printf("Sorry, the given Username's account details do not exist\n");
            return -1;
        }
    }
}
