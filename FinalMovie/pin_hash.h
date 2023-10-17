#define pin_hash_size 50

struct PIN
{
    long int AccountNumber;
    int pin; //(4-digit pin) which is unique to every account number
    struct PIN *next;
};

struct PIN* pin_Hash[pin_hash_size]; /*Hash Table storing PINs associated with every each account number*/

void fill_AcNo_pin_Hash();
int pin_Hash_func(long int AccountNumber);
int retrieve_pin(long int AccountNumber);