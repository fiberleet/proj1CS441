#include "table.h"


static const tableEntry    fsaTable[] =
{
    //                               Alpha           Number            SpecialSymbol     Greater          Equal                          RParenthesis                  Asterisk                      Less             Colon            LeftParenthesis  Period           SingleQuote      WhiteSpace       UnrecognizedChar
    /*beginState*/                 { fsReservedWord, fsIntegerOrFloat, fsSpecialSymbolF, fsGreater,       fsEqualRParenthesisAsteriskF,  fsEqualRParenthesisAsteriskF, fsEqualRParenthesisAsteriskF, fsLess,          fsColon,         fsLParenthesis,  fsPeriod,        fsBeginString,   fsBeginState,    fsErrorState    },
    /*ReservedWord*/               { fsReservedWord, fsReservedWord,   fsReservedWordf,  fsReservedWordf, fsReservedWordf,               fsReservedWordf,              fsReservedWordf,              fsReservedWordf, fsReservedWordf, fsReservedWordf, fsReservedWordf, fsReservedWordf, fsReservedWordf, fsReservedWordf },
	/*ReservedWordf*/              { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*SpecialSymbolf*/             { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*Greater*/                    { fsGreaterF,     fsGreaterF,       fsGreaterF,       fsGreaterF,      fsGreaterLessEqualF,           fsGreaterF,                   fsGreaterF,                   fsGreaterF,      fsGreaterF,      fsGreaterF,      fsGreaterF,      fsGreaterF,      fsGreaterF,      fsGreaterF      },
	/*Greaterf*/                   { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*GreaterLessEqualf*/          { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*NonEqualityf*/               { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*Less*/                       { fsLessF,        fsLessF,          fsLessF,          fsNonEqualityF,  fsGreaterLessEqualF,           fsLessF,                      fsLessF,                      fsLessF,         fsLessF,         fsLessF,         fsLessF,         fsLessF,         fsLessF,         fsLessF         },
	/*LessF*/                      { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },	
	/*Colon*/                      { fsColonF,       fsColonF,         fsColonF,         fsColonF,        fsAssignmentF,                 fsColonF,                     fsColonF,                     fsColonF,        fsColonF,        fsColonF,        fsColonF,        fsColonF,        fsColongF,       fsColonF        },
	/*ColonF*/                     { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*AssignmentF*/                { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*EqualRParenthesisAsteriskF*/ { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*Period*/                     { fsPeriodF,      fsPeriodF,        fsPeriodF,        fsPeriodF,       fsPeriodF,                     fsPeriodF,                    fsPeriodF,                    fsPeriodF,       fsPeriodF,       fsPeriodF,       fsSetRangeF,     fsPeriodF,       fsPeriodF,       fsPeriodF       },
	/*Periodf*/                    { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*SetRangef*/                  { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*IntegerOrFloat*/             { fsIntegerF,     fsIntegerOrFloat, fsIntegerF,       fsIntegerF,      fsIntegerF,                    fsIntegerF,                   fsIntegerF,                   fsIntegerF,      fsIntegerF,      fsIntegerF,      fsFlo,           fsIntegerF,      fsIntegerF,      fsIntegerF      },
	/*IntegerF*/                   { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*Flo*/                        { fsFDE,          fsMantissa,       fsFDE,            fsFDE,           fsFDE,                         fsFDE,                        fsFDE,                        fsFDE,           fsFDE,           fsFDE,           fsFDE,           fsFDE,           fsFDE,           fsFDE           },
	/*FollowingDigitExpected*/     { fsErrorState,   fsErrorState,     fsErrorState,     fsErrorState,    fsErrorState,                  fsErrorState,                 fsErrorState,                 fsErrorState,    fsErrorState,    fsErrorState,    fsErrorState,    fsErrorState,    fsErrorState,    fsErrorState    },
	/*BeginString*/                { fsString,       fsString,         fsString,         fsString,        fsString,                      fsString,                     fsString,                     fsString,        fsString,        fsString,        fsString,        fsStringF,       fsString,        fsString        },
	/*String*/                     { fsString,       fsString,         fsString,         fsString,        fsString,                      fsString,                     fsString,                     fsString,        fsString,        fsString,        fsString,   fsFoundQuoteInString, fsString,        fsString        },
	/*FoundQuoteInString*/         { fsStringF,      fsStringF,        fsStringF,        fsStringF,       fsStringF,                     fsStringF,                    fsStringF,                    fsStringF,       fsStringF,       fsStringF,       fsStringF, fsDoubleQuoteInString, fsStringF,       fsStringF       },
	/*DoubleQuoteInString*/        { fsString,       fsString,         fsString,         fsString,        fsString,                      fsString,                     fsString,                     fsString,        fsString,        fsString,        fsString,   fsFoundQuoteInString, fsString,        fsString        },
	/*StringF*/                    { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
	/*LParenthesis*/               { fsLParenthesisF,fsLParenthesisF,  fsLParenthesisF,  fsLParenthesisF, fsLParenthesisF,               fsLParenthesisF,              fsInComment,                  fsLParenthesisF, fsLParenthesisF, fsLParenthesisF, fsLParenthesisF, fsLParenthesisF, fsLParenthesisF, fsLParenthesisF },
	/*LParenthesisf*/              { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
    /*InComment*/                  { fsInComment,    fsInComment,      fsInComment,      fsInComment,     fsInComment,                   fsInComment,                  fsCmStar,                     fsInComment,     fsInComment,     fsInComment,     fsInComment,     fsInComment,     fsInComment,     fsInComment     },
    /*CmStar*/                     { fsInComment,    fsInComment,      fsInComment       fsInComment,     fsInComment,                   fsCommentF,                   fsCmStar,                     fsInComment,     fsInComment,     fsInComment,     fsInComment,     fsInComment,     fsInComment,     fsInComment     },
    /*CommentF*/                   { fsEndState,     fsEndState,       fsEndState,       fsEndState,      fsEndState,                    fsEndState,                   fsEndState,                   fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState,      fsEndState      },
};

static const unsigned int  TABLE_SIZE =  
    sizeof(my_table) / sizeof(my_table[0]);


Table_Entry const *
table_begin(void)
{
    return &my_table[0];
}

Table_Entry const *
table_query(int state)
{
	if(state <= TABLE_SIZE){
		return &my_table[state];
	}
	else return -1;
}


Table_Entry const *
table_end(void)
{
    return &my_table[TABLE_SIZE];
}  