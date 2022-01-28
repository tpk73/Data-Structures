const int SIZE = 5;

template <typename T>
struct Queue {
    T   data[SIZE];
    int head;
    int tail;
};

template <typename T>
void initialize(Queue<T>& t) {

    t.head = 0;
    t.tail = 0;

}

template <typename T>
void destroy(Queue<T>& t) {

    initialize(t);

}

template <typename T>
int  getSize(Queue<T>& t) {

    if (t.head > t.tail) {
        return((t.tail - t.head) + 5);
    }
    else {
        return (t.tail - t.head);
    }
   

}

template <typename T>
bool isEmpty(Queue<T>& t) {

    return(t.tail == t.head);

}

template <typename T>
void push(Queue<T>& t, T value) {

    t.data[t.tail++] = value;
    t.tail %= 5;

}

template <typename T>
T    pop(Queue<T>& t) {
    
    T value = t.data[t.head];
    t.head++;
    t.head %= 5;
    return value;

}
