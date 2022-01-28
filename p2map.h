#include <cstddef>

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node<K, V>* next;
};

template <typename K, typename V>
struct Map {
    Node<K, V>** table;
    int size;
};

template <typename K, typename V>
void initialize(Map<K, V>& m, int val) {

    m.size = val;
    m.table = new Node<K,V>*[val];
    for (int i = 0; i < val; i++) {
        m.table[i] = NULL;
    }
}

template <typename K, typename V>
void destroy(Map<K, V>& m) {

    for(int i = 0; i < m.size; i++){
        Node<K,V>* walker = m.table[i];
        // deallocating using walker
        while (walker != NULL) {
            walker = walker->next;
            delete m.table[i];
            m.table[i] = walker;
        }
    }
    // delete m.table and set to values to NULL
    delete[] m.table;
    m.table = NULL;
    m.size = 0;
}

template <typename K, typename V>
bool has_key(Map<K, V>& m, K key) {

    int hashVal = key % m.size;
    Node<K, V>* walker = m.table[hashVal];
    // always stop walker one before
    while (walker != NULL && walker->key != key) {
        walker = walker->next;
    }
    return walker != NULL;
}

template <typename K, typename V>
void assign(Map<K, V>& m, K key, V value) {

    int hashVal = key % m.size;
    Node<K, V>* walker = m.table[hashVal];
    // setup for first key and value in the hashVal
    if (walker == NULL) {
        m.table[hashVal] = new Node<K, V>;
        m.table[hashVal]->key = key;
        m.table[hashVal]->value = value;
        m.table[hashVal]->next = NULL;
    }
    // setup to find end of stack in hashVal and add onto the end
    else if (!has_key(m,key)) {
        // always stop walker one before
        while (walker->next != NULL) {
            walker = walker->next;
        }
        walker->next = new Node<K, V>;
        walker = walker->next;
        walker->key = key;
        walker->value = value;
        walker->next = NULL;
    }
    // setup to update value when finding the same key
    else {
        // always stop walker one before
        while (walker != NULL && walker->key != key) {
            walker = walker->next;
        }
        walker->value = value;
    }

}
template <typename K, typename V>
void remove(Map<K, V>& m, K key) {

    // if key isn't there return
    if (!has_key(m, key)) {
        return;
    }
    else {
        int hashVal = key % m.size;
        Node<K, V>* walker = m.table[hashVal];
        if (key == m.table[hashVal]->key) {
            m.table[hashVal] = walker->next;
            delete walker;
        }
        else {
            // always stop walker one before
            while (walker->next->key != key) {
                walker = walker->next;
            }
            // create temp so walker can point around it then you can delete temp
            Node<K, V>* temp = walker->next;
            walker->next = temp->next;
            delete temp;
        }
    }
}

template <typename K, typename V>
V    lookup(Map<K, V>& m, K key) {

    int hashVal = key % m.size;
    Node<K, V>* walker = m.table[hashVal];

    // always stop walker one before
    while (walker != NULL && walker->key != key) {
        walker = walker->next;
    }
    // now that we are at the Node return the value
    return walker->value;
}