#pragma once
#include "Vector.h"

template<typename T>
class Set {
private:
    Vector<T> data; // Using Vector class for storage
public:
    // Constructors
    Set(); // Default constructor
    Set(const Set& other); // Copy constructor
    ~Set(); // Destructor

    // Operator Overloading
    Set operator+(const Set& other) const; // Union of two sets
    Set operator-(const Set& other) const; // Difference of two sets
    Set operator*(const Set& other) const; // Intersection of two sets
    Set operator^(const Set& other) const; // Symmetric difference of two sets
    Set& operator=(const Set& other); // Assignment operator
    bool operator==(const Set& other) const; // Equality operator
    Set& operator+=(const Set& other); // Insertion and sorting operator
    friend std::ostream& operator<<(std::ostream& os, const Set& set); // Display operator

    // Set Functions
    void insert(const T& element); // Insert an element into the set (sorted and unique)
    void erase(const T& element); // Remove an element from the set
    bool find(const T& element) const; // Find if an element exists in the set
    int size() const; // Return the number of elements in the set
    bool empty() const; // Check if the set is empty
    void display() const; // Display the elements of the set
};

// Default constructor
template<typename T>
Set<T>::Set() {
    // Vector's default constructor will be called
}

// Copy constructor
template<typename T>
Set<T>::Set(const Set& other) : data(other.data) {}

// Destructor
template<typename T>
Set<T>::~Set() {
    // Vector's destructor will be called
}

// Union of two sets
template<typename T>
Set<T> Set<T>::operator+(const Set& other) const {
    Set<T> result(*this); // Create a copy of the current set
    for (int i = 0; i < other.data.size_(); i++) { // Iterate through elements of the other set
        if (!result.find(other.data.at(i))) { // If an element is not already in the result set, insert it
            result.insert(other.data.at(i));
        }
    }
    return result;
}

// Difference of two sets
template<typename T>
Set<T> Set<T>::operator-(const Set& other) const {
    Set<T> result(*this); // Create a copy of the current set
    for (int i = 0; i < other.data.size_(); i++) { // Iterate through elements of the other set
        result.erase(other.data.at(i)); // Remove elements of other set from the result set
    }
    return result;
}

// Intersection of two sets
template<typename T>
Set<T> Set<T>::operator*(const Set& other) const {
    Set<T> result; // Create an empty set for the result
    for (int i = 0; i < data.size_(); i++) { // Iterate through elements of the current set
        if (other.find(data.at(i))) { // If an element is also in the other set, insert it into the result set
            result.insert(data.at(i));
        }
    }
    return result;
}

// Symmetric difference of two sets
template<typename T>
Set<T> Set<T>::operator^(const Set& other) const {
    Set<T> result; // Create an empty set for the result
    for (int i = 0; i < data.size_(); i++) { // Iterate through elements of the current set
        if (!other.find(data.at(i))) { // If an element is not in the other set, insert it into the result set
            result.insert(data.at(i));
        }
    }
    for (int i = 0; i < other.data.size_(); i++) { // Iterate through elements of the other set
        if (!find(other.data.at(i))) { // If an element is not in the current set, insert it into the result set
            result.insert(other.data.at(i));
        }
    }
    return result;
}

// Assignment operator
template<typename T>
Set<T>& Set<T>::operator=(const Set& other) {
    if (this != &other) { // Check for self-assignment
        data = other.data; // Use Vector's assignment operator
    }
    return *this;
}

// Equality operator
template<typename T>
bool Set<T>::operator==(const Set& other) const {
    return data == other.data; // Use Vector's equality operator
}

// Insertion and sorting operator
template<typename T>
Set<T>& Set<T>::operator+=(const Set& other) {
    for (int i = 0; i < other.data.size_(); i++) { // Iterate through elements of the other set
        insert(other.data.at(i)); // Insert elements into the current set
    }
    return *this;
}

// Insert an element into the set (sorted and unique)
template<typename T>
void Set<T>::insert(const T& element) {
    if (!find(element)) { // If the element is not already in the set
        typename Vector<T>::Iterator it = data.begin(); // Iterator for traversing the set
        while (it != data.end() && *it < element) { // Find the correct position to insert while maintaining sorted order
            ++it;
        }
        data.insert(it, element); // Insert the element at the correct position
    }
}

// Remove an element from the set
template<typename T>
void Set<T>::erase(const T& element) {
    typename Vector<T>::Iterator it = data.begin(); // Iterator for traversing the set
    while (it != data.end() && *it != element) { // Find the element in the set
        ++it;
    }
    if (it != data.end()) { // If the element is found, erase it
        data.erase(it);
    }
}

// Find if an element exists in the set
template<typename T>
bool Set<T>::find(const T& element) const {
    return data.find(element) != data.end(); // Check if the element is in the set
}

// Return the number of elements in the set
template<typename T>
int Set<T>::size() const {
    return data.size_();
}

// Check if the set is empty
template<typename T>
bool Set<T>::empty() const {
    return data.empty();
}

// Display the elements of the set
template<typename T>
void Set<T>::display() const {
    cout << "{ ";
    for (int i = 0; i < data.size_(); ++i) {
        std::cout << data.at(i) << " ";
    }
    cout << "}";
    cout << endl;
}

// Display operator
template<typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
    os << "{ ";
    for (int i = 0; i < set.data.size_(); ++i) {
        os << set.data.at(i) << " ";
    }
    os << "}";
    return os;
}

