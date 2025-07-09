#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Vector {
private:
    T* elements; // Pointer to the dynamically allocated array
    int capacity_; // Capacity of the vector
    int size; // Number of elements in the vector
    static const int INITIAL_CAPACITY = 2; // Initial capacity of the vector

    void resize(int newCapacity); // Resize the vector

public:
    // Constructors
    Vector(); // Default constructor
    Vector(const Vector& other); // Copy constructor
    ~Vector(); // Destructor

    // Operator Overloading
    Vector& operator=(const Vector& other); // Assignment operator
    bool operator==(const Vector& other) const; // Equality operator
    T& operator[](int index); // Access operator (non-const)
    const T& operator[](int index) const; // Access operator (const)
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec); // Display operator

    // Vector Functions
    void push_back(const T& value); // Add an element to the end of the vector
    void pop_back(); // Remove the last element from the vector
    int size_() const; // Return the number of elements in the vector
    bool empty() const; // Check if the vector is empty
    T at(int index) const; // Access an element at a specific index
    void insert(int index, const T& value); // Insert an element at a specific index
    void erase(int index); // Erase an element at a specific index
};

// Constructors
template<typename T>
Vector<T>::Vector() {
    capacity_ = INITIAL_CAPACITY;
    size = 0;
    elements = new T[capacity_];
}

template<typename T>
Vector<T>::Vector(const Vector& other) {
    capacity_ = other.capacity_;
    size = other.size;
    elements = new T[capacity_];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Vector<T>::~Vector() {
    delete[] elements;
    cout << "Destructor Called!!";
}

// Operator Overloading
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        capacity_ = other.capacity_;
        size = other.size;
        elements = new T[capacity_];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template<typename T>
bool Vector<T>::operator==(const Vector& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (elements[i] != other.elements[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
T& Vector<T>::operator[](int index) {
    return elements[index];
}

template<typename T>
const T& Vector<T>::operator[](int index) const {
    return elements[index];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << "[ ";
    for (int i = 0; i < vec.size; ++i) {
        os << vec.elements[i] << " ";
    }
    os << "]";
    return os;
}

// Vector Functions
template<typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity_) {
        resize(2 * capacity_);
    }
    elements[size++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        --size;
    }
    if (size * 2 < capacity_) {
        int newCapacity = capacity_ / 2;
        resize(newCapacity);
    }
}

template<typename T>
int Vector<T>::size_() const {
    return size;
}

template<typename T>
bool Vector<T>::empty() const {
    return (size == 0);
}

template<typename T>
T Vector<T>::at(int index) const {
    if (index < 0 || index >= size) {
        cout << "Out of Bounds Access!!" << endl;
        return T(); // Return default value for type T
    }
    return elements[index];
}

template<typename T>
void Vector<T>::insert(int index, const T& value) {
    if (index < 0 || index > size) {
        cout << "Out of Bounds Access!!" << endl;
        return;
    }
    if (size == capacity_) {
        resize(2 * capacity_);
    }
    for (int i = size; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    size++;
}

template<typename T>
void Vector<T>::erase(int index) {
    if (index < 0 || index >= size) {
        cout << "Out of Bounds Access!!" << endl;
        return;
    }
    for (int i = index; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
}

template<typename T>
void Vector<T>::resize(int newCapacity) {
    T* temp = new T[newCapacity];
    for (int i = 0; i < size; ++i) {
        temp[i] = elements[i];
    }
    delete[] elements;
    elements = temp;
    capacity_ = newCapacity;
}
