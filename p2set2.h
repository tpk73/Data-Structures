#include <cstddef>

template <typename T>
struct Set //Template for a set
{
    T* data;
    int size;
    int count;
};

template <typename T>
void initialize(Set<T>& t) //Initializes the set, setting everything to their default states
{
    t.size = 2;
    t.count = 0;
    t.data = new T[s.size];
}

template <typename T>
void destroy(Set<T>& t) //Detroys the set by converting all the values related to the set to their defaults
{
    t.size = 0;
    t.count = 0;
    delete[] t.data;
    t.data = NULL;
}

template <typename T>
bool isEmpty(Set<T> t) //Checks to see if the number of values in the set is 0
{
    return (t.count == 0);
}

template <typename T>
void insert(Set<T>& t, T value) //Inserts a value into the set
{
    if (t.count == t.size) //Checks to see if the dynamic array needs to be expanded 
    {
        T* tempArray = new T[t.size * 2]; //Creates new array to temporarily hold set values
        for (int i = 0; i < t.size; i++) //Inserts into tempArray
        {
            tempArray[i] = t.data[i];
        }
        t.size *= 2; //Doubles the size of the array
        delete[] t.data; //Clears the old array
        t.data = tempArray; //Copies previous values back into the expanded array
    }
    bool doesContain = false;
    for (int i = 0; i < t.count; i++) //Loops through array to check if the given value is already in the array
    {
        if (t.data[i] == value)
            doesContain = true;
    }
    if (!doesContain) //If the value is not in the array already, inserts the new value at the end and increases count of values
    {
        t.data[s.count] = value;
        t.count++;
    }
}

template <typename T>
bool contains(Set<T>& t, T value) //Checks to see if the set contains a given value
{
    bool doesContain = false;
    for (int i = 0; i < t.count; i++) //Loops through to see if value is in the array
    {
        if (t.data[i] == value)
        {
            doesContain = true;
        }
    }
    return doesContain;
}

template <typename T>
void remove(Set<T>& t, T value) //Removes a given value from the set
{
    bool doesContain = false;
    for (int i = 0; i < t.size; i++)
    {
        if (t.data[i] == value) //Loop through array to check if the value is actually in the set
        {
            t.data[i] = t.data[t.count - 1]; //If value is in the set, replaces it with the last value in the set, removing it
            if (t.data[i] == value)
            {
                t.data[i] = t.data[t.size - 1];
                doesContain = true;
            }
            doesContain = true;
        }
    }
    if (doesContain) //Decrements the count of values
    {
        t.count--;
    }
}

template <typename T>
int  getSize(Set<T> t) //Returns number of unique values in the set
{
    return t.count;
}

// New functions
Set<T> operator&&(Set<T> x, Set<T> y);  // intersection
Set<T> operator||(Set<T> x, Set<T> y);  // union
Set<T> operator-(Set<T> x, Set<T> y);   // difference