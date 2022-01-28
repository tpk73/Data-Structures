#include <iostream>
#include <fstream>
#include <cstddef>
#include "p2map.h"

using namespace std;

int main() {

	string fileName, father, son;

	// create maps
	Map<string,string> SonFat;
	Map<string, string> FatSon;

	// initialize them
	initialize(SonFat);
	initialize(FatSon);

	// create your fin and fout
	ifstream fin;
	ofstream fout;

	// user input for file they want to read
	cout << "Input file: ";
	cin >> fileName;

	// open desired file
	fin.open(fileName);

	// will read the data from file and put them into two maps
	while (fin >> father) {
		fin >> son;
		// will find names from start to finish
		assign(FatSon, father, son);
		// will find names finish to start
		assign(SonFat, son, father);
	}

	// close your fin
	fin.close();

	// find the top father
	while (has_key(SonFat, father)) {
		father = lookup(SonFat, father);
	}

	// open up your file with added fixed_
	fout.open("fixed_" + fileName);
	
	// start frome stored father position above and reset father to read through map
	while (has_key(FatSon, father)) {
		fout << father << " " << lookup(FatSon, father) << endl;
		father = lookup(FatSon, father);
	}

	// close your fout
	fout.close();

	// output
	cout << endl;
	cout << "Ordering complete.";

	destroy(SonFat);
	destroy(FatSon);
}