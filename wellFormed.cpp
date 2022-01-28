#include <iostream>
#include "p2stack.h"

using namespace std;

//keep pushing until you see a closing

int main() {
	
	//variables
	string express;
	Stack<char> list;
	bool wf = true;
	
	//User Input
	cout << "Enter expression: ";
	cin >> express;
	initialize(list);
	
	
	//find out if wf is true or false
	for ( int i = 0; wf && express[i] != 0; i++ ) {
		
		if ( express[i] == ']' ) {
			if ( isEmpty(list) )
				wf = false;
			else if ( pop(list) != '[' )
				wf = false;
		}else if ( express[i] == ')' ) {
			if ( isEmpty(list) )
				wf = false;
			else if ( pop(list) != '(' )
				wf = false;
		}else
			push( list, express[i] );		
	}
	
	if ( ! isEmpty(list) )
		wf = false;
	
	if (wf)
		cout << '\n' << "Expression " << express << " is well-formed.";
	
	else
		cout << '\n' << "Expression " << express << " is not well-formed.";
	
	//destroy stack
	destroy(list);
	
}