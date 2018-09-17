#ifndef TABLE_H
#define TABLE_H

struct Table_Entry
{
    unsigned int  current_state_id;
    unsigned char transition_letter;
    unsigned int  next_state_id;
};

Table_Entry const *    table_begin(void);
Table_Entry const *    table_end(void);

#endif // TABLE_H
#define reservedWord 1
#define reservedWordF 2 //F stands for Finished
#define specialSymbolF 3
#define greater 4
#define greaterFinished 5
#define greaterLessEqualF 6
#define less 7
#define lessF 8
#define nonEqualityF 9
#define colon 10
#define colonF 11
#define assignmentFinished 12
#define equalParenthesisAsteriskF 13
#define period 14
#define periodF 15
#define setRangeF 16
#define integerOrFloat 17
#define integerF 18
#define float 19
#define mantissa 20
#define floatF 21
#define followingDigitExpected 22
#define beginString 23
#define str 24
#define foundQuoteInString 25
#define doubleQuoteInString 26
#define stringFinished 27

#define endState 100
#define error 101