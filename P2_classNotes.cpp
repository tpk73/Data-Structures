8.24.20

//how to read from a file

	require the use of istream library
	#include <iostream>
	#include <fstream>
	#include <string>
	
	using namespace std;
		allows you to use cin and cout
	
	//create input stream using file
	ifstream fin;
	string filename;
	
	//open file
	fin.open(filename.c_str());
	
	//read in first word
	fin >> value;
	
	//read whole file
	while(fin >> value)
	
	//close file
	fin.close();
	
//how to get a whole line
	getline
	
8.26.20

//read file practice using cin and cout

	jay z
	toby keith
	freddy mercury
	
#include <iostream>
using namespace std;

int main () {

	string name;
	cout << "Enter a name: ";
	cin >> name; (Jay)
	cout << name;
	cin >> name; (Z)
	cout << name;
	cin >> name; (Toby)
	cout << name;
	
}

//read file practice using getline
	
	jay z
	toby keith
	freddy mercury
	
#include <iostream>
using namespace std;

int main () {

	string name;
	cout << "Enter a name: ";
	getline(cin,name);
	
	cout << name;
	
}

//warnings

be careful using getline using standard input

//more practice

#include <iostream>
using namespace std;

int main () {

	string name;
	cout << "Enter a name: ";
	cin >> name;
	cout << "Enter another name: ";
	getline(cin,name);
	
	//when using cin and getline,,, cin will only grab 'Jay' but the getline would take the '\n' after the word
	//add an extra getline to get rid of the '\n'
	getline(cin,name)
	
}

//how to write to a file

#include <ofstream>
#include <fstream
#

using namespace std;

int main () {
	
	fout 
	string filename;
	
	cout << "enter a filename: ";
	cin >> filename;
	
	fout.open("output.txt");
		
	if(fout.is_open() ) {
		for(int i = 0; i < 20; i+=2){
			fout << integers[i] << ", ";
			//fout << integers[i+1];
			fout << integers[i+2]; 			
		}
	}
}

//writing a file completely erases previouse data
//fstream dictates which input or output you are using ifstream = input ofstream = output

8.28.20

//string stream
#include <sstream>
	allows lower level parsing on a string
	works like cin (based on space)
	
	"As my guitar gently weaps"
	getline(cin,str)
	//or
	stringstream ss;
	ss << str;
	string word;
	ss >> word; -> (As)
	ss >> word; -> (my)
	ss >> word; -> (guitar)
	ss >> word; -> (gently)
	ss >> word; -> (weaps)

//practice

#include <sstream>
#include <iostream>

using namespace std;

int main () {	
	
}

//decoding morse code
	while loop
	get line
	sstream
	switch statements
	or arrays
	or if if else statements
	
//employee list
	filestream
	sstream
	ID[] Name[] c[] = "ID + Name"
	
8.31.20	
tutoring
carter
MWTH 3-6pm

//abstract data type (ADT)
	a way for framework to thinking about data in higher level
	most of the time used interchangabley with data structure
	data structure is an implementation of a particular ADT
	
	ADT deals with commmon approaches to ordering and movement of data
	behavior and not implementation
	
	Ex. list (stores data)
		see the content
		add/remove
		check to see if list is empty
	
	encaspulation
		hides details from the user
		
	Data Structures:
	
	#include "p2<ADT>"
	
	Queue
		First in, first out
			push
				add item to tail of the queue
			pop
				return the item from the head of queue
			isempty
				indicate if queue is currently empty
				
					head -> | empty | <-tail
		
		queue<type>
		
		void initialize(queue<type> Q);
		
		void destroy(queue<type> Q);
		
		void push(queue<type> Q, type V);
		
		type pop(queue<type> Q);
		
		bool isEmpty(queue<type> Q);
		
		destroy(Q);
		
	Stack
		Last in, first out
		ex. like stacking boxes
		
		push item on top of the stack
		
		pop returns form top of the stack
		
		isEmpty indicate if stack is currently empty
		
		where would this be useful
		deleting somethings in a string
		solving a maze (once you hit a dead end retreat and choose a new lane)
		
		stack<type>
		
		void initialize(stack<type> S);
		
		void destroy(stack<type> S);
		
		void push(stack<type> S, type V);
		
		type pop(stack<type> S);
		
		bool isEmpty(stack<type> S);
		
		destroy(S);
		
		ex. input "hello" output "olleh";
	
	Priority Queue
		push
			add item to priority queue
				add item w/ priority for that item
		pop
			return item from priority queue
				returns back the higher priority
		isEmpty
			Indicate if priority queue isEmpty
			
		|[empty]|
		
		the greater the number the higher the priority 
		if there are two values with the same priority which ever is towards the head will go our first
		
		ex. self driving car
			a collision error will rank higher that a light error
		
	Set
		insert
			add item to set if not already there
		
		remove
			remove item from set if present
		
		contains
			indicate if given item is present
			
		insert A, insert B, insert C contains B = [A,B,C] true
		insert A, insert A, insert C contains B = [A,C] false
		
		what operation can we do in a set?
			unionify two set
				A{1,2,3} B{3,4,5}
				A U B = {1,2,3,4,5}
			section two set
				A{1,2,3} B{3,4,5}
				A Section B = {3}
	
	Map
		assign (key,value)
			assosicate key with value in a map; if key is already present,
			discard former value and assosicate with new value
			
			ex. key "bill" value 95
			
		remove (key)
			remove key and value from map
		
		has_key (key)
			indicates T/F if key exists in map
			
		lookup (key)
			return value assosicated with key, Error if key doesn't exist
			
	Graph
	
	Heap
	
	Binary search tree
	
9.14.20

	struct
		is an aggregate of data type;
		
		#include <iostream>
		
		using namespace std;
		
		//insert here
		struct Example{
			int num;
			float dec;
		};
		
		int main () {
			
			//call struct and give it a name
			Example test;
			
			//call name and data type
			test.num = 7
			test.dec = 3.14
			
			//or
			
			Example test[2];
			
			test[0].num = 7;
			test[1].num = 8;
			test[0].num = 3.14;
			test[1].num = 4.5;
			
		}

9.16.20
	check example1.cpp
	check example2.cpp

9.18.20
	template
		lets you use any data type

	template <typename T> // T will take in any data types int, string, char...
	void printArray(T array[], int size) // T will now call on any of the arrays
		cout << array[0];
		for (int i = 0; i < size; i++) {
			cout << ", " << array[i];
		}

9.21.20
9.23.20
	check example3
	//pointer is a variable that stores a memory location of another variable
	how do we creat a pointer?
10.5.20

11.2.20
	quick sort
		sorting aligorithm that uses recursion
		keep dividing the list into smaller size
		combie the smaller size list to produce the overall solution
		
	pivot 5 6 7 4 2 1 3 9 11 12 5 6 
	[lower than 5][equal to 5][greater than 5]
	[4,2,1,3][5,5][6,7,9,11,12,6]
	take first pivot
	[2,1,3][4][N/A]
	[1][2][3]
	// connect [1][2][3] to the [4]
	// dont touch middle pivot
	[N/A][6,6][7,9,11,12]
	[N/A][7][9,11,12]
	[N/A][9][11,12]
	[N/A][11][12]
	// connect [6,6][7][9][11][12]
	rearranged pivot 1 2 3 4 5 5 6 6 7 9 11 12

Node* quickSort(Node* head) {

	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* less = NULL;
	Node* equal = NULL;
	Node* greater = NULL;

	int pivot = head->data;

	Node* walker = head;
	while (walker != NULL) {
		Node* p = walker;
	}
}

11.9.20

Hash Table 
	used to implement map 
	map stores pairs of keys and values 

	implement map w/ an array of fixed size 

	ex. array[10] 
	[][][][][][][][][][]
	then use a hash function
	what is a hash function?
		hash function takes the key and returns the location in the array where the value associated with the queue is associated 
		hash funciton uses modulo arithmetic 
	ex: 14 'A', 15 'B', 3 'C', 2 'D', 10 'E', 44 'W', 46 'X'
	take the key along with the array size and input them
	// ex. using open addressing
	14 % 10 = 4 A[4]
	15 % 10 = 5 A[5]
	3 % 10 = 3 A[3]
	2 % 10 = 2 A[2]
	10 % 10 = 0 A[0]
	44 % 10 = 4 A[4+2] // open address will find an opening at A[6]
	46 % 10 = 6 A[6+1] // if using open addressing 44%10 has been pushed into A[6] already pushing 46%10 +1 to the empty A[7]

	[E][][D][C][A][B][W][X][][]

	// ex. using hash chaining
	14 'A', 15 'B', 3 'C', 2 'D', 10 'E', 44 'W', 46 'X', 54 'L', 5 'M'
	14 % 10 = 4 A[4]
	15 % 10 = 5 A[5]
	3 % 10 = 3 A[3]
	2 % 10 = 2 A[2]
	10 % 10 = 0 A[0]
	44 % 10 = 4 Link A[4]
	46 % 10 = 6 A[6]
	54 % 10 = 4 Link Link A[4]
	5 % 10 = 5 Link A[5]

	[E][][D][C][A][B][][][][]
	           [W][M]
               [L]
	when their is a collision on the hash function 
		1) open addressing 
			move directions to the right until you find an open space to insert the value 
		2) hash chaining 
			links the array and doesnt replace any values 

	this will determine the location in the array
	if the keys are non int we have to change them to an int 
	using ASCII code 
