#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int main (){
	
	//arrays
	int size = 0;
	string firstName[1000];
	string lastName[1000];
	string id[1000];
	
	
	ifstream fin;
	
	//user input for name of input and output
	string Infile, Outfile;
	
	//user input
	cout << "Input file: ";
	cin >> Infile;
	
	//open file
	fin.open(Infile);
	
	if( fin.is_open() ) {
		
		//reads file data
		while( fin >> firstName[size] ){
			fin >> lastName[size];
			fin >> id[size];
			size++;
		}
			
	//user input for outfile
	cout << "Output file: ";
	cin >> Outfile;
	
	//Output File
	ofstream fout;
	string sortedEmployee = Outfile;
	fout.open(Outfile);
	
	//add id + fname + lname
	string employee[1000];
	
	for(int i = 0; i < size; i++){
		employee[i] = id[i] +" "+firstName[i]+" "+lastName[i];
	}
	
	//sort from ascending order
	sort(employee, employee + size);
	
	for(int i = 0; i < size; i++)
		fout << employee[i] << endl;
	
	//close out the file
	fout.close();
	
	}
	else{
		cout << "File failed to open." ;
	}
}