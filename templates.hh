#include <iostream>
#include <string>

using namespace std;
template <typename T> 
class myVec;

template<typename T>
ostream& operator<<(ostream& os, myVec<T> &in);

template <typename T>
class myVec{
public:
    myVec(int size) : n {size}, data {new T [size]} {
        cout << "Allocated for vector of type " << typeid(T).name() << " and size " << n << endl;
    }
    ~myVec(){
        cout << "Destroying vector of type " << typeid(T).name() << " and size " << n << endl;
        delete[] data;
    }
    friend ostream& operator<< <>(ostream &os, myVec<T> &in);
    T& operator[](int i);
    int getSize(){return n;}
private:
    int n;
    T* data;
};
template <typename T>
ostream& operator<<(ostream &os, myVec<T> &in){
    os << "[ ";
    for (int i=0; i<in.getSize(); ++i){
        os << in[i] << ", ";
    }
    os << "]" << endl;
    return os;
}

template <typename T>
T& myVec<T>::operator[](int i){
    if (i<0){
        throw range_error("Attempting to access element with negative index!");
    }
    else if (i >= n){
        throw range_error("Attempting to access out of range element.");
    } 
    return data[i];
}