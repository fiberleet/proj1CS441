#ifndef TABLE_H
#define TABLE_H

struct Table_Entry
{
    unsigned int  current_state_id;
    unsigned int transition_id;
    unsigned int  next_state_id;
};

Table_Entry const *    table_begin(void);
Table_Entry const *    table_end(void);

#endif // TABLE_H