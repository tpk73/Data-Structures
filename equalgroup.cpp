#include <iostream>
#include <sstream>
#include <cstddef>

using namespace std;

bool equalSub(int A[], int sum3, int sum5, int index, int s) {

	// this statement will dictate true of false for the final output
	if (index == s)
		return sum3 == sum5;
	// when A[index] is % by 5
	else if (A[index] % 5 == 0)
		return equalSub(A, sum3, sum5 + A[index], index + 1, s);
	// when A[index] is % by 3
	else if (A[index] % 3 == 0)
		return equalSub(A, sum3 + A[index], sum5, index + 1, s);
	// allows two paths for A[index]
	else
		return equalSub(A, sum3 + A[index], sum5, index + 1, s) || equalSub(A, sum3, sum5 + A[index], index + 1, s);
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

	cout << endl;

	// when bool is true
	if(equalSub(nums,0,0,0,val))
		cout << "Yes, there are two equal subgroups.";
	// when bool is false
	else
		cout << "No, there are not two equal subgroups.";

	// if you create a new int destroy it
	delete[] nums;
}