#include <cstddef>

template <typename V, typename R>
struct Node {
    V value;
    R priority;
    Node<V, R>* next;
    Node<V, R>* prev;
};

template <typename V, typename R>
struct PriorityQueue {
    Node<V, R>* head;
};

//initialize will initialize the priority queue(create empty list)
template <typename V, typename R>
void initialize(PriorityQueue<V, R>& pq) {

    pq.head = NULL;
}

//destroy will destroy the priority queue(release all memory)
template <typename V, typename R>
void destroy(PriorityQueue<V, R>& pq) {

    if (pq.head == NULL) {
        return;
    }

    Node<V, R>* walker = pq.head;

    pq.head->prev->next = NULL; // looping the pointers to make the while loop work
   
    while (walker != NULL) {
        walker = pq.head->next;
        delete pq.head;
        pq.head = walker;
    }    
}

//isEmpty will return true if the priority queue is empty(holding no values)
template <typename V, typename R>
bool isEmpty(PriorityQueue<V, R>& pq) {

    return(pq.head == NULL);
}

//push will insert an element with value and priority rank into the priority queue
template <typename V, typename R>
void push(PriorityQueue<V, R>& pq, V val, R pri) {

    Node<V, R>* newNode = new Node<V, R>;

    newNode->value = val;
    newNode->priority = pri;

    // if there is not value
    if (pq.head == NULL) {
        pq.head = newNode;
        newNode->prev = pq.head; // pq.head or newNode
        newNode->next = pq.head; // pq.head or newNode
    }
    // set up for the smallets
    else if (pri <= pq.head->prev->priority) {
        newNode->next = pq.head;
        newNode->prev = pq.head->prev;
        pq.head->prev->next = newNode;
        pq.head->prev = newNode;
    }
    else {
        // setting new largerst
        if (pri > pq.head->priority) {
            newNode->next = pq.head;
            newNode->prev = pq.head->prev;
            pq.head->prev->next = newNode;
            pq.head->prev = newNode;
            pq.head = newNode;
            return;
        }
        // adding newNode to middle of the list
        newNode->next = pq.head->next;
        while (pri <= newNode->next->priority) {
            newNode->next = newNode->next->next;
        }
        newNode->prev = newNode->next->prev;
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
    }
}

//pop will return the next value removed from the priority queue(highest priority, longest in queue)
template <typename V, typename R>
V    pop(PriorityQueue<V, R>& pq) {

    V ret = pq.head->value;
    Node<V, R>* temp = pq.head;

    // only if pq.head is the only Node there
    if (pq.head == pq.head->next) {
        pq.head = NULL;
    }
    // if there are more Nodes then just head
    else {
        pq.head->prev->next = pq.head->next;
        pq.head->next->prev = pq.head->prev;
        pq.head = pq.head->next;
    }

    delete temp;
    return(ret);
}