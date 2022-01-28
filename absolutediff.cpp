#include <iostream>
#include <sstream>

using namespace std;

int main () {

	string list;
	int first = 0;
	int second = 0;
	int difference = 0;
	int numlist[50] = {0};
	int size = 0;
	bool absvalue = true;
	int missing = 0;
	
	//User Input
	cout << "Enter list: ";
	getline(cin, list);
	
	stringstream ss(list);
	
	ss >> first;
	
	//Get difference
	while (ss >> second){
		
		difference = second - first;
		
		//make difference positive
		if ( difference < 0 ) {
			difference *= -1;
		}
		
		numlist[difference]++;
		first = second;
		size++;		
		
	}
	
	//Find the missing value if absvalue reads false
	for (int i = 1; i < size+1 && absvalue; i++){
		
		if (numlist[i] == 0){
			absvalue = false;
			
			if ( missing == 0)
				missing = i;
		}
	}
	
	//output
	if (absvalue == true)
		cout << "Good sequence.";
	else 
		cout << "Bad sequence: missing " << missing << ".";
}