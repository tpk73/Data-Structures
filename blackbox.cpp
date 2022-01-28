#include <iostream>
#include <sstream>
#include "p2stack.h"
#include "p2queue.h"
#include "p2priorityqueue.h"

using namespace std;

int main () {

	string input[2];
	string order[100];
	int size = 0;
	

	//initialize ADT
	PriorityQueue<string, string> pq;
	initialize (pq);
	Stack<string> stack;
	initialize (stack);
	Queue<string> q;
	intialize (q(string) q);

	cout << "Command: ";

	for(int i = 0; i < 2; i++)
		cin >> input[i];

	while (input[0] != "END") {

		order[size] = input[1];

		if (input[0] == "PUSH") {
			push(pq, input[1], input[1]);
			push(stack, input[1]);
			push(q, input[1]);
		}

		else if (input[0] == "POP") {
			if (pq != isEmpty) {
				pop(pq);
			}
			else if (stack != isEmpty) {
				pop(stack);
			}
			else if (q != isEmpty) {
				pop(q);
			}
		}

		size++;

		cout << "Command: ";

		for (int i = 0; i < 2; i++) {
			cin >> input[i];
			if (input[0] == "END")
				break;
		}	
	}

	cout << "done!";


	destroy(pq);
	destory(stack);
	destroy(q);

}