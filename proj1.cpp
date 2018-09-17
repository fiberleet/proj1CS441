#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "table.h"

int leximizer(sstream code, string lexeme, int lineNum, int colNum, int catNum, bool error, string errorMsg)
{
    unsigned int current_state = 0;
    char symbol;
    
    while (code.get (&symbol) )
    {     
        Table_Entry const *  p_entry = table_begin();
        Table_Entry const * const  p_table_end =  table_end();
        bool state_found = false;
        while ((!state_found) && (p_entry != p_table_end))
        {
            if (p_entry->current_state_id == current_state)
            {
                if (p_entry->transition_letter == transition_letter)
                {
                    cout << "State found, transitioning"
                         << " from state " << current_state
                         << ", to state " << p_entry->next_state_id
                         << "\n";
                    current_state = p_entry->next_state_id;
                    state_found = true;
                    break;
                }
             }
             ++p_entry;
         }
         if (!state_found)
         {
             cerr << "Transition letter not found, current state not changed.\n";
         }
    }
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
	string errorMsg = "";
	while(leximizer(code, lexeme, lineNum, colNum, catNum, error, errorMsg) != 0)
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