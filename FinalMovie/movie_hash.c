#include <stdio.h>
#include <string.h>
#include "movie_hash.h"

void fill_num()
{
    for(int i = 0 ; i < movie_hash_size ; i++)
    {
        movie_Hash[i].name = " ";
        movie_Hash[i].number = i+1;
    }
    return;
}

int movie_Hash_function(char *name)
{
    int hash_index = 0;
    for(int i = 0 ; i < strlen(name) ; i++)
    {
        hash_index += name[i];
    }
    hash_index = hash_index / 50;
    return hash_index;
}

void insert_movie(char *name) //Use of Linear Probing
{
    int i;
    int hash_index = movie_Hash_function(name);
    if(!(hash_index <= movie_hash_size - 1))
    {
        printf("\nThe movie Hash function returns a hash_index which is not in the bounds of Hash table.And hence cannot show this movie today\n");
        return;
    }
    for(i = hash_index  ; i < movie_hash_size ; i++)
    {
        if(strcmp(movie_Hash[i].name, " ") == 0) //indicates no movie exists for the movie number
        {
            movie_Hash[i].name = name;
            break;
        }
        else if(strcmp(movie_Hash[i].name, name) == 0) //Same movie name already exists on the hash index
        {
            break;
        }
        else //indicates another movie name and its number already exists on the hash index
        {
            continue;
        }
    }
    
    if(i == movie_hash_size)
    {
        for(i = 0 ; i < hash_index ; i++)
        {
            if(strcmp(movie_Hash[i].name, " ") == 0) //indicates no movie exists for the movie number
            {
                movie_Hash[i].name = name;
                break;
            }
            else if(strcmp(movie_Hash[i].name, name) == 0) //Same movie name already exists on the hash index
            {
                break;
            }
            else //indicates another movie name and its number already exists on the hash index
            {
                continue;
            }
        }
        if(i == hash_index)
        {
            printf("\nSORRY, WE ARE NOT SHOWING THE REQUESTED MOVIE TODAY...\n");
        }
    }
    return;
}

int retrieve_movie_num(char *name)
{
    int i;
    int hash_index = movie_Hash_function(name);
    if(!(hash_index <= movie_hash_size - 1))
    {
        printf("\nThis movie is not available today, sorry!!\n");
        return -12;
    }
    for(i = hash_index  ; i < movie_hash_size ; i++)
    {
        if(strcmp(movie_Hash[i].name, name) == 0)
        {
            break;
        }
        else //indicates another movie name and its number already exists on the hash index
        {
            continue;
        }
    }
    if(i == movie_hash_size)
    {
        for(i = 0 ; i < hash_index ; i++)
        {
            if(strcmp(movie_Hash[i].name, name) == 0)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        if(i == hash_index)
        {
//            printf("\nTHE REQUESTED MOVIE CANNOT BE SHOWN TODAY, SORRY!!\n");
            return -1;
        }
    }
    return movie_Hash[i].number;
}