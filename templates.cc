// Adam Graham
// Template concepts main file
#include <iostream>

#include "templates.hh"
using namespace std;

// Basic templated print function
template <typename T>
void templatedPrint(T in){
    cout << "Templated print of type " << typeid(T).name() << ": " << in << endl;
}
// Template specialisation for user defined templated class
template<typename T>
void templatedPrint(myVec<T> in){
    cout << "Template specialisation: Vector of " << typeid(T).name() << ":" << endl << in << endl;
}

//  Full template specialisation with specialisation of templated class
template<>
void templatedPrint(myVec<double> in){
    cout << "Full specialisation. Printing vector of doubles" << endl << in << endl;
}

template<typename T>
void templatedPrint(T* in){
    cout << "Partial specialisation of template for pointers of type " << typeid(T).name() << endl << in << endl;
}

int main(){
    try{
        // Test templated print function with some different types.
        cout << "Testing templated print function with different types\n\n" << endl;
        templatedPrint(2);
        templatedPrint(5.0);
        templatedPrint("Hello World");

        // Test with user defined myVec class
        cout << "\n\nTesting templated print function with custom class specialisation\n\n" << endl;
        myVec<int> i1(3); 
        i1[0] = 1; i1[1] = 2; i1[2] = 3; 
        templatedPrint(i1);
        myVec<char> c1(4);
        c1[0] = 'a'; c1[1] = 'b'; c1[2] = 'c'; c1[3] = 'd';
        templatedPrint(c1);

        // Test with partial template specialisation for pointers
        cout << "\n\nTesting templated print function with partial specialisation for pointers\n\n" << endl;
        double pTo = 10.0;
        double* p = &pTo;
        templatedPrint(p);

        // Test special member functions of templated class
        cout << "\n\nTesting templated class' special member functions and overloaded operators\n\n" << endl;
        cout << "Original vector = " << c1 << endl;
        myVec<char> c2 {c1};
        cout << "Copy constructor: c2 = " << c2 << endl;
        c2[2] = 'z';
        c1 = c2;
        cout << "c2[2]=z. Copy assignment operator copying c2 to c1. c1 = " << c1 << endl;
        myVec<char> c3 {move(c1)};
        cout << "Move constructor: c3=" << c3 << endl;
        myVec<char> c4 {5};
        c4 = move(c2);
        cout << "Move assignment operator: c4=" << c4 << endl;
    }

    catch(range_error &e){
        cout << "Invalid index: " << e.what() << endl;
    }

    
}