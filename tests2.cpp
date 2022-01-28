#include <iostream>
#include "p2stack2.h"
using namespace std;

int main()
{
	Stack<char> s;
	initialize(s);

	string command;
	char value;
	while (true)
	{
		cin >> command;

		if (command == "Quit")
			break;

		if (command == "Push")
		{
			cin >> value;
			push(s, value);
		}

		if (command == "Pop")
		{
			if (isEmpty(s))
				cout << "Stack empty\n";
			else
				cout << ">> " << pop(s) << endl;
		}
	}
	destroy(s);
}