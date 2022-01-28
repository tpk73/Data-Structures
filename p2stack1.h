#include<cstddef> // includes NULL definition

const int size = 2;

template <class T>
struct Stack {
    int size;	// size of array
    int top;	// index of value currently at top of Stack
    T* data;	// array of values
};

template <class T>
void initialize(Stack<T>& t) {

    t.size = 2;
    t.top = 0;
    t.data = new T[t.size]; // dynamic allocating
}

template <class T>
void destroy(Stack<T>& t) {

    t.size = 0;
    t.top = 0;
    delete[] t.data;
    t.data = NULL;
}

template <class T>
bool isEmpty(Stack<T>& t) {

    return(t.top == 0);
}

template <class T>
void push(Stack<T>& t, T value) {

    if (t.top == t.size) {
        T* temp = new T[t.size * 2];
        for (int i = 0; i < t.size; i++) {
            temp[i] = t.data[i];
        }
        t.size *= 2;
        delete[] t.data; // deallocating
        t.data = temp;
    }
    t.data[t.top++] = value;

}

template <class T>
T    pop(Stack<T>& t) {

    return t.data[--t.top];
}