#include <iostream>
#include "p2queue.h"
#include <fstream>

using namespace std;

int main() {

	Queue<string> names;
	Queue<string> specie;
	Queue<string> tempname;
	Queue<string> tempspecie;

	initialize(names);
	initialize(specie);
	initialize(tempname);
	initialize(tempspecie);

	
	ifstream fin;
	ofstream fout;

	string call, animal, name;

	fin.open("actions.txt");
	fout.open("adoptions.txt");
	
	while (fin >> call) {
		// read rescue
		if (call == "rescue") {
			// enter animal type and name
			fin >> animal >> name;
			//push names
			push(names, name);
			//push animal type
			push(specie, animal);

		}
		// read request
		else if (call == "request") {
			//find which animal is to be requested
			fin >> animal;
			//will get first animal out of queue
			if (animal == "either") {
				if (!isEmpty(names)) {
					//get name
					fout << pop(names) << endl;
					//get specie
					pop(specie);
				}
			}
			else {
				bool id = false;
				while (!isEmpty(specie)) {
					//create a temp string to hold popped names and species
					string tempN = pop(names);
					string tempS = pop(specie);

					if (tempS == animal && !id) {
						//finds animal that hasn't been popped from either
						fout << tempN << endl;
						id = true;
					}
					else {
						push(tempname, tempN);
						push(tempspecie, tempS);
					}
				}
				while (!isEmpty(tempname)) {
					push(names, pop(tempname));
					push(specie, pop(tempspecie));
				}
			}
		}
	}

	//destroy queue
	destroy(names);
	destroy(specie);
	destroy(tempname);
	destroy(tempspecie);

	//close out file
	fin.close();
	fout.close();
}