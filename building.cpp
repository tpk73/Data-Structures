#include <iostream>
#include "p2priorityqueue.h"
#include "p2set.h"
#include <sstream>
#include <cstddef>

using namespace std;

int main() {

	int pf[10], K, size = 0;

	cout << "Prime factors: ";

	// get the whole line of data using getline and stringstream
	string line;
	getline(cin, line);
	stringstream ss(line);

	// get size of the pf list 
	while (ss >> pf[size])
		size++;

	cout << "K: ";
	cin >> K;

	// need a PQ and Set
	PriorityQueue<int, int> Roblox;
	Set<int> Contain;

	// initialize PQ and Set
	initialize(Roblox);
	initialize(Contain);

	// Put 1 into PQ with a neg val so its at top
	// insert 1 into Set
	push(Roblox, 1, -1);
	insert(Contain, 1);

	// get currN from PQ
	for (int i = 0; i < K - 1; i++) {
		int currN = pop(Roblox);
		for (int j = 0; j < size; j++) {
			// checks to see if the currN * pf[] is already in Contain or not
			// if not insert it into PQ and Set
			if (!contains(Contain, currN * pf[j])) {
				insert(Contain, currN * pf[j]);
				push(Roblox, currN * pf[j], -(currN * pf[j]));
			}
		}
	}

	cout << '\n' << "Result: " << pop(Roblox);

	// destory PQ and Set
	destroy(Roblox);
	destroy(Contain);
}