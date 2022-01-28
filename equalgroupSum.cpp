#include <iostream>
#include <sstream>
#include <cstddef>

//sum

using namespace std;

bool sumWO(int A[], int sum, int index, int size) {
	if (sum == 0)
		return true;
	else if (index >= size)
		return false;
	// making sure you don't use adjacent A[index] that are right next to eachother
	else
		return sumWO(A, sum - A[index], index + 2, size) || sumWO(A, sum, index + 1, size);
}

int main() {

	int val, currVal, sum;

	cout << "How many values? ";
	cin >> val;

	// make new array to push to equalSub
	int* nums = new int[val];

	cout << "Enter numbers: ";

	// allows user input
	for (int i = 0; i < val; i++) {
		cin >> nums[i];
	}

	cout << "Enter sum: ";
	cin >> sum;

	cout << endl;
	
	if (sumWO(nums, sum, 0, val))
		cout << "Yes, there is a subset that sums to " << sum << ".";
	else
		cout << "No, there is no subset that sums to " << sum << ".";

	// if you create a new int destroy it
	delete[] nums;
}