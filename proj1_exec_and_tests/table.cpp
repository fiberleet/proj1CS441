#include "table.h"

static const Table_Entry    my_table[] =
{
    //  Current   Transition     Next
    {    0,          'A',        1}, // From 0 goto 1 if letter is 'A'.
    {    0,          'B',        2}, // From 0 goto 2 if letter is 'B'.
    {    0,          'C',        3}, // From 0 goto 3 if letter is 'C'.
    {    1,          'A',        1}, // From 1 goto 1 if letter is 'A'.
    {    1,          'B',        3}, // From 1 goto 3 if letter is 'B'.
    {    1,          'C',        0}, // From 1 goto 0 if letter is 'C'.
};

static const unsigned int  TABLE_SIZE =  
    sizeof(my_table) / sizeof(my_table[0]);


Table_Entry const *
table_begin(void)
{
    return &my_table[0];
}


Table_Entry const *
table_end(void)
{
    return &my_table[TABLE_SIZE];
}  