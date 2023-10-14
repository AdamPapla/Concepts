// Adam Graham
// Templated class definition for a vector type container. 
#ifndef TEMPLATES_HH_
#define TEMPLATES_HH_
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// Declare class and overloaded ostream operator in advance to 
// allow friend declaration in class
template <typename T> 
class myVec;

template<typename T>
ostream& operator<<(ostream& os, myVec<T> &in);

template <typename T>
class myVec{
public:
    // Constructor - allocates memory for n entries of type T
    myVec(int size) : n {size}, data {new T [size]} {
        fill(data, data+n, 0);
    }
    // Custom destructor to hanle dynamic memory allocation
    ~myVec(){
        delete[] data;
    }

    // Define copy constructor to ensure a deep copy is performed
    myVec(const myVec &other) : n {other.getSize()}, data{new T [n]}{
        copy(other.data, (other.data) + n, data);
    }
    // Copy assignment operator
    myVec& operator=(const myVec& other){
        delete[] data;
        n = other.getSize();
        data = new T [n];
        copy(other.data, (other.data) + n, data);
        return *this;
    }
    // Move constructor
    myVec(myVec&& other) : n {other.n}, data {other.data}{
        other.data = NULL;
        other.n = 0;
    }
    // Move assignment operator
    myVec& operator=(myVec&& other){
        n = other.n;
        delete[] data;
        data = other.data;
        other.data = NULL;
        other.n = 0;
        return *this;
    }
    // Declare ostream << operator as a friend to allow printing. Defined outside class body
    friend ostream& operator<< <>(ostream &os, myVec<T> &in);
    // Overload [] operator with a const version (for reading data) and a non-const version (for writing data)
    T& operator[](int i);
    T& operator[](int i) const;
    int getSize() const {return n;}
private:
    int n;
    T* data;
};

// Overload << operator for printing class objects
template <typename T>
ostream& operator<<(ostream &os, myVec<T> &in){
    os << "[ ";
    for (int i=0; i<in.getSize(); ++i){
        os << in[i] << ", ";
    }
    os << "]" << endl;
    return os;
}


// For data access - reading and writing


// Non const version - will be used for writing data
template <typename T>
T& myVec<T>::operator[](int i) {
    if (i<0){
        throw range_error("Attempting to access element with negative index!");
    }
    else if (i >= n){
        throw range_error("Attempting to access out of range element.");
    } 
    return data[i];
}

// const version - will be used for reading data (allows for use wth const e.g. for copy constructor)
template <typename T>
T& myVec<T>::operator[](int i) const {
    if (i<0){
        throw range_error("Attempting to access element with negative index!");
    }
    else if (i >= n){
        throw range_error("Attempting to access out of range element.");
    } 
    return data[i];
}

// Declare an addition operator - should use decltype for template type deduction
template<typename T, typename U>
myVec<decltype(T{}+U{})> operator+(const myVec<T>& v1, myVec<U>& v2){
    if (v1.getSize() != v2.getSize()){
        throw invalid_argument("Cannot add vectors of different sizes");
        return myVec<decltype(T{}+U{})> (0);
    }
    myVec<decltype(T{} + U{})> result (v1.getSize());
    for (int i=0; i<v1.getSize(); ++i){
        result[i] = v1[i] + v2[i];
    }
    return result;
}
#endif