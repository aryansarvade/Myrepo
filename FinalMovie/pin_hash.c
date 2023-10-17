#include <stdio.h>
#include <stdlib.h>
#include "pin_hash.h"

void fill_AcNo_pin_Hash()
{
    for(int i = 0 ; i < pin_hash_size ; i++)
    {
        pin_Hash[i] = (struct PIN*)malloc(sizeof(struct PIN));
        pin_Hash[i]->AccountNumber = 0; //Account Number = 0 indicates the pin isn't associated with any account number.
        pin_Hash[i]->pin = (rand() % (9999 - 1000 + 1)) + 1000;  //(4-Digit PIN)
        pin_Hash[i]->next = NULL;
    }
    return;
}

//Function to return sum of digits of a number
int sumOfDigits(int num)
{
    int sum = 0;
    if(num == 0)
    {
        return 0;
    }
    else
    {
        while(num != 0)
        {
            sum += (num % 10);
            num = num / 10;
        }
    }
    return sum;
}

int pin_Hash_func(long int AccountNumber)
{
    int hash_index = sumOfDigits(AccountNumber) - 15;
    return hash_index;
}

int retrieve_pin(long int AccountNumber)
{
//    int i;
    int hash_index = pin_Hash_func(AccountNumber);
    if(!(hash_index <= pin_hash_size - 1))
    {
        printf("The Pin Hash Function returns a hash_index over the bounds of the pin Hash table size.\n");
        return -1;
    }
    if(pin_Hash[hash_index]->AccountNumber == 0) //Account Number does not exist on the hash_index PIN of the Hash Table.
    {
        pin_Hash[hash_index]->AccountNumber = AccountNumber;
        return pin_Hash[hash_index]->pin;
    }
    else if(pin_Hash[hash_index]->AccountNumber == AccountNumber)//The given Account Number and it's PIN already exists on the hash_index
    {
        return pin_Hash[hash_index]->pin;
    }
    
    struct PIN *ptr = pin_Hash[hash_index];

    while(ptr->AccountNumber != AccountNumber && ptr!=NULL) //Some other Account Number and it's pin exists on the hash_index
    {
        ptr = ptr->next;
    }
    if(ptr != NULL) //The given Account Number does not exist
    {
        ptr = (struct PIN*)malloc(sizeof(struct PIN));
        ptr->AccountNumber = AccountNumber;
        ptr->pin = (rand() % (9999 - 1000 + 1)) + 1000;
        ptr->next = NULL;
        return ptr->pin;
    }
    else if(ptr->AccountNumber == AccountNumber)
    {
        return ptr->pin;
    }
}