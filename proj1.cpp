#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "table.h"

int leximizer(sstream code, std::string &lexeme, char &nextChar, int &lineNum, int &colNum, int &catNum, bool &error, std::string &errorMsg)
{
    int currentState = 0;
    char symbol;
    int charCategory = charCategorizer(nextChar);
    do (charCategory = charCategorizer(nextChar))
    {   
    	if(charCategory != 16){  //If it's not the end of the file
	        Table_Entry const *  p_entry = table_query(currentState);

	        switch(p_entry->charCategory){
	        	case fsEndState : {	nextChar = symbol;
	        						catNum = charCategorizer(current_state);
	        						break;}
	        	case fsErrorState : {nextChar = symbol; 
	        						 error = true;
	        						 if(currentState == fsFDE) errorMsg = "Following Digit Expected";
	        						 break;}
	        	default : current_state = charCategory;
	        	}
	        	        
	      	if(current_state == fsBeginString || current_state == fsString || current_state ==fsFoundQuoteInString || current_state == fsDoubleQuoteInString || current_state == fsStringF )
	        {
	        	if( symbol == '\n' || symbol == EOF){
	        		error = true;
	        		errorMsg = "end of character literal expected";
	        		return -1;
	        	}
	        } 

	        if(current_state != fsInComment || current_state != fsCmStar || current_state != fsCommentF){ //Don't put comments in the lexeme
	        	lexeme += symbol;
	        	if(symbol == '\n'){
	        		lineNum++
	        		colNum = 0;
	        	}
	        	else{
	        		colNum++;
	        	}
	        }
	        else lexeme = "";


    	}
    }while(charCategory = charCategorizer(code.get(&symbol)) != 16);
}

int charCategorizer(char c)
{
	int cval = (int)c;
	if(c == EOF) return 16; 
	else if(isspace(c)) return 13;
	else if(isalpha(c)) return 0;
	else if(isdigit(c)) return 1;
	else if(c == '.') return 11;
	else if(c == '(') return 10;
	else if(c == ')') return 6;
	else if(c == '*') return 7;
	else if(c == ':') return 9;
	else if(c == '<') return 8;
	else if(c == '>') return 4;
	else if(c == '=') return 5;
	else if(c == '\'') return 12;
	else if(c == '+' || c == '-' || c == '/' || c == '[' || c == ']' || c == ',' || c == ';' || c == '^') return 3;
	else if(cval < 125 && cval >= 32 ) return 14;
	else if(cval >= 125 || cval < 32 ) return -1;
	else return -1;
}

int lexCategory(int i)
{

	if(i == fsReservedWordf) return 1;
	else if(i == fsSpecialSymbolF || i == fsGreaterF || i == fsLessF || 
		i == fsGreaterLessEqualF || i == fsNonEqualityF || i == fsColonF || 
	    i == fsAssignmentF || i == fsEqualRParenthesisAsteriskF || i == fsPeriodF || i == fsLParenthesisF) return 2;
	else if(i == fsIntegerF) return 3;
	else if(i == fsFloF) return 4;
	else if(i == fsStringF) return 5;
	else return -1;
}

int leximizer(sstream code, string lexeme, int lineNum, int colNum, int catNum, bool error, string errorMsg)
{

}

int main(int argc, char* argv[])
{
	
	if (argc = 1) 
	{
		std::cout << "Attempting to open " << argv[1] << std::endl;
	} 
	else
	{
		std::cout << "No file name entered. Exiting ...";
		return -1;
	}

	ifstream code(argv[1]);

	if (code.is_open() && code.good())
	{
		std::cout << "Code is open! Leximized code will be found in " << argv[1] << ".output.txt"; 
	}
	else
	{
		std::cout << "failed to open file..";
	}


	ofstream out;
	string outName = argv[1] + "output.txt";
	out.open(outName);
	string lexeme = "";
	int lineNum = 0;
	int colNum = 0;
	int catNum = 0;
	bool error = 0;
	char nextChar = '';
	string errorMsg = "";
	while(leximizer(code, lexeme, nextChar, lineNum, colNum, catNum, error, errorMsg) != 0)
	{
		out << setw(5) << lineNum << setw(5) << colNum << setw(5)
		<< catNum << ”\t” << lexeme << std::endl;
	}

	if(error){
		out << setw(5) << lineNum << setw(5) << colNum << setw(5)
		<< "	" << errorMsg << std::endl;
	}
	else{
		out << "END OF FILE";
	}

	return 0;
}