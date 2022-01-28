#include<cstddef>

template <typename T>
struct SortedList {

	T* array; // points to an array of value
	int count; // amount of values in the array
};

template <typename T>
void initialize(SortedList<T>& list) {

	list.array = NULL;
	list.count = 0;
}

template <typename T>
void destroy(SortedList<T>& list) {

	if (list.array == NULL)
		return;

	delete[] list.array;
	list.count = 0;
}

template <typename T>
void insert(SortedList<T>& list, T value) {

	int position = 0;

	while (position < list.count && list.array[position] <= value) {

		if (list.array[position] == value)
			return;
		else
			position++;

	}

	if (list.array == NULL) {

		list.array = new T[1];
		list.array[0] = value;
		list.count++;
		return;
	}
	T* newList = new T[list.count + 1];

	for (int i = 0; i < position; i++) 
		newList[i] = list.array[i];
	
	newList[position] = value;

	for (int i = 0; i < list.count; i++)
		newList[i + 1] = list.array[i];

	delete[] list.array;
	list.array = newList;
	list.count++;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, SortedList<T> list) {

	if (list.array == NULL)
		return;

	out << list.array[0];

	for (int j = 1; j < list.count; j++) {
		out << ", " << list.array[j];
	}
	return out;
}

