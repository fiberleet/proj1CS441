#include "table.h"
//Constants to represent the states
const int fsReservedWord = 1;
const int fsReservedWordf = 2;
const int fsSpecialSymbolF = 3;
const int fsGreater = 4;
const int fsGreaterF = 5;
const int fsLess = 6;
const int fsGreaterLessEqualF = 7;
const int fsNonEqualityF = 8;
const int fsColon = 9;
const int fsColonF = 10;
const int fsAssignmentF = 11;
const int fsEqualRParenthesisAsteriskF = 12;
const int fsPeriod = 13;
const int fsPeriodF = 14;
const int fsSetRangeF = 15;
const int fsIntegerOrFloat = 16;
const int fsIntegerF = 17;
const int fsFlo = 18;
const int fsMantissa = 19;
const int fsFloF = 20;
const int fsFollowingDigitExpected = 21;
const int fsBeginString = 22;
const int fsString = 23;
const int fsFoundQuoteInString = 24;
const int fsDoubleQuoteInString = 25;
const int fsStringF = 26;
const int fsLParenthesis = 27;
const int fsInComment = 28;
const int fsCmStar = 29
const int fsCommentF = 30;
const int fsWhiteSpace = 31;
const int fsUnrecognizedChar = 32;
const int fsEndOfFileChar = 33;


const int fsbeginState = 0;
const int fsendState = 101;
const int fserrorState = 102;

//FSA character categories
const int ccAlpha = 0;
const int ccNumber = 1;
const int ccSpecialSymbol = 3;
const int ccGreater = 4;
const int ccEqual = 5;
const int ccLess = 6;
const int ccColon = 7;
const int ccLeftParenthesis = 8;
const int ccRightParenthesis = 9;
const int ccAsterisk = 10;
const int ccPeriod = 11;
const int ccSingleQuote = 12;
const int ccOther = 13;


static const tableEntry    fsaTable[] =
{
    //              Alpha              Number                SpecialSymbol      Greater     Equal                         Less       Colon, LeftParenthesis, Period, SingleQuote, Other 
   /*beginState*/ { fsReservedWord,    fsIntegerOrFloat  ,   fsSpecialSymbolF,  fsGreater, fsEqualRParenthesisAsteriskF,  fsLess,   fsColon, fsLParenthesis, },
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