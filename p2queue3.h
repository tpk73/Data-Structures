#include "p2stack.h"

template <typename T>
struct Queue {
    Stack<T> s1;
    Stack<T> s2;
};

template <typename T>
void initialize(Queue<T>& q) {

    initialize(q.s1);
    initialize(q.s2);
}

template <typename T>
void destroy(Queue<T>& q) {

    destroy(q.s1);
    destroy(q.s2);
}

template <typename T>
int  getSize(Queue<T> q) {

    int x = 0;
    x += getSize(q.s1);
    x += getSize(q.s2);
    return x;
}

template <typename T>
bool isEmpty(Queue<T> q) {

    return(isEmpty(q.s1) && isEmpty(q.s2));
}

template <typename T>
void push(Queue<T>& q, T value) {

    push(q.s1, value);
}
template <typename T>
T    pop(Queue<T>& q) {

    if (!isEmpty(q.s2))
        return pop(q.s2);

    while (!isEmpty(q.s1))
        push(q.s2, pop(q.s1));

    return pop(q.s2);
}