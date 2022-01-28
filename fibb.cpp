#include <iostream>

using namespace std;

int fib(int n) {
	//fib 0 comes back at zero
	if (n == 0) {
		return 0;
	}
	//fib 1 || 2 always comes back as 1
	else if (n == 1 || n == 2) {
		return 1;
	}
	//fib > 2 needs to be calculated out
	else {
		return(fib(n - 1) + fib(n - 2));
	}
}
int main() {

	//initialize n
	int n;
	
	//prompt for user
	cout << "This program calculates numbers in the Fibonacci sequence." << endl;
	cout << "Which place in the sequence do you want to calculate? " << endl;

	//user input
	cin >> n;

	//formatting
	cout << endl;

	//formatting output
	cout << "Fibonacci(" << n << ") is " << fib(n) << endl;

	return 0;
}