#include <cstddef>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
struct Stack {
    Node<T>* top;
};

template <typename T>
void initialize(Stack<T>& t) {

    t.top = NULL;
}

template <typename T>
void destroy(Stack<T>& t) {


    delete[] t.top;
    t.top = NULL;
}

template <typename T>
bool isEmpty(Stack<T>& t) {

    return(t.top == NULL);
}

template <typename T>
void push(Stack<T>& t, T x) {

    Node<T>* newNode = new Node<T>;
    newNode->value = x;
    newNode->next = NULL;

    if (t.top == NULL) {
        t.top = newNode;
        t.top->next = t.top;
        //t.top->top = t.top;
        return;
    }

 //   newNode->next = t.top;
 //   newNode->top = t.top->top;

//    t.top->top->next = newNode;
//    t.top->top = newNode;

}

template <typename T>
T    pop(Stack<T>& t) {

    popValue = t.top;
    t.top->top->top = t.top;
    t.top->top->next = t.next;

    return Node<T> popValue;
}
