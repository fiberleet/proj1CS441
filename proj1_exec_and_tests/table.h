#ifndef TABLE_H
#define TABLE_H

struct tableEntry
{
    int  alphaID;
    int  numberID;
    int  specialSymbolID;
    int  greaterID;
    int  equalID;
    int  rParenthesisID;
    int  asteriskID;
    int  lessID;
    int  colonID;
    int  lParenthesisID;
    int  periodID;
    int  singleQuoteID;
    int  whiteSpaceID;
    int  unrecognizedCharID;
};

Table_Entry const *    table_begin(void);
Table_Entry const *    table_query(int state);
Table_Entry const *    table_end(void);

#endif // TABLE_H


//Constants to represent the states
const int fsReservedWord = 1;
const int fsReservedWordf = 2;
const int fsSpecialSymbolF = 3;
const int fsGreater = 4;
const int fsGreaterF = 5;
const int fsLess = 6;
const int fsLessF = 7;
const int fsGreaterLessEqualF = 8;
const int fsNonEqualityF = 9;
const int fsColon = 10;
const int fsColonF = 11;
const int fsAssignmentF = 12;
const int fsEqualRParenthesisAsteriskF = 13;
const int fsPeriod = 14;
const int fsPeriodF = 15;
const int fsSetRangeF = 16;
const int fsIntegerOrFloat = 17;
const int fsIntegerF = 18;
const int fsFlo = 19;
const int fsMantissa = 20;
const int fsFloF = 21;
const int fsFDE = 22; //Following Digit Expected
const int fsBeginString = 23;
const int fsString = 24;
const int fsFoundQuoteInString = 25;
const int fsDoubleQuoteInString = 26;
const int fsStringF = 27;
const int fsLParenthesis = 28;
const int fsLParenthesisF = 29;
const int fsInComment =30;
const int fsCmStar = 31;
const int fsCommentF = 32;


const int fsBeginState = 0;
const int fsEndState = 100;
const int fsErrorState = 101;


//FSA character categories
const int ccAlpha = 0;
const int ccNumber = 1;
const int ccSpecialSymbol = 3;
const int ccGreater = 4;
const int ccEqual = 5;
const int ccRParenthesis = 6;
const int ccAsterisk = 7;
const int ccLess = 8;
const int ccColon = 9;
const int ccLeftParenthesis = 10;
const int ccPeriod = 11;
const int ccSingleQuote = 12;
const int ccWhiteSpace = 13;
const int ccUnrecognizedChar = 14;
const int ccEndLine = 15;
const int ccEndOfFile = 16;