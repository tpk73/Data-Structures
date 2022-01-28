#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "p2priorityqueue.h"

using namespace std;

int main () {
	
	//initial startup
	string Infile;
	string classes;
	int rank = 0;
	int student;
	stringstream ss;

	//setting up PQ for each class
	PriorityQueue<int, int> CS332;
	PriorityQueue<int, int> CS352;
	PriorityQueue<int, int> CS365;
	initialize(CS332);
	initialize(CS352);
	initialize(CS365);
	
	//user input
	cout << "Input file: ";
	cin >> Infile;
	
	ifstream fin;
	
	//Open and read file
	fin.open(Infile);
	
	for(int i = 0; fin >> classes; i++){
		
		fin >> student;
		fin >> rank;
		
		//pushing ID and Rank to seperate PQ
		if( classes == "CS332" )
			push(CS332, student, rank);
		else if( classes == "CS352" )
			push(CS352, student, rank);
		else 
			push(CS365, student, rank);	
	}
	fin.close();
	
	//Output files
	ofstream fout;
	
	//Output file for CS332
	fout.open("CS332");
	while(! isEmpty(CS332)){
		student = pop(CS332);
		fout << student << endl;
	}
	fout.close();
	
	//Output file for CS352
	fout.open("CS352");
	while(! isEmpty(CS352)){
		student = pop(CS352);
		fout << student << endl;
	}
	fout.close();
	
	//Output file for CS365
	fout.open("CS365");
	while(! isEmpty(CS365)){
		student = pop(CS365);
		fout << student << endl;
	}
	fout.close();
	
	//destroy PQ
	destroy(CS332);
	destroy(CS352);
	destroy(CS365);
}