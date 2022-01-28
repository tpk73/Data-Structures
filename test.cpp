#include <iostream>

using namespace std;

int main() {

	int array[10] = { -2,6,3,9,5,7,0,2,1,8 };
	int* p = array;
	for (int i = 0; i < 3; i++) {
		p = p + i;
	}
	cout << *p << endl;
}