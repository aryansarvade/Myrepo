#define acc_hash_size 50

struct account_details
{
    char *name;
    long int acc_num;
    int balance;
    struct account_details *next;
};

/*Creating a Hash Table(array) of account balances and account number of each person(from their name)*/
struct account_details* acc_Hash[acc_hash_size];

int Hash_function(char *name);
void fill_AcNo_bal();
void insert_in_accHash(char *name);
void retrieve_acc_details(char *name);
int retrieve_acc_num(char *name);
int retrieve_bal(char *name);