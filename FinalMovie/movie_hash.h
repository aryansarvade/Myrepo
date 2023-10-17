#define movie_hash_size 60

struct movie_num
{
    char *name;  //Movie and the number associated with it
    int number;
};

//Creating a hash table of movie names
struct movie_num movie_Hash[movie_hash_size];

void fill_num();
int movie_Hash_function(char *name);
void insert_movie(char *name);
int retrieve_movie_num(char *name);