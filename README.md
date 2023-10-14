# Concepts
Small programs built to test and practice various C++ concepts.  
## Inheritance
Testing inheritance with a small program concerning player positions.  
Tests virtual and overridden functions and diamond shaped inheritance (testing virtual inheritance).  
## Templates
Creates a templated vector class and a templated print function. Templated vector class has
- User defined special member functions
- Overloads the `<<` operator for printing to `ostream`
- Creates two overloads of the [] operator- one const for reading and one non const for writing data to the vector
- Overloads the + operator as a non-member function. Uses decltype to determine type of resultant vector.
Templated print function has
- Specialisation for the user-defined template class.
- Specialisation for a specialisation of the user-defined template class i.e. `void templatedPrint(myVec<double> &in)`
- Partial specialisation for templates
