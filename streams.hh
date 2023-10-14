// Adam Graham
// Header file with a basic person class
#ifndef STREAMS_HH_
#define STREAMS_HH_
#include <iostream>

using namespace std;
// Define a basic person class with an overloaded constructor and overloaded << operator for printing
class person{
    public:
        person(int age, string name, double wProb) : age {age}, name {name}, wProb {wProb}{}
        friend ostream& operator<<(ostream &os, const person &in){
            os << "___________________\n" << endl;
            os << "Name: " << in.name << endl;
            os << "Age: " << in.age << endl;
            os << "Win probability: " << in.wProb << endl;
            os << "___________________" << endl;
            return os;
        }
    private:
        int age;
        string name;
        double wProb;
};
#endif