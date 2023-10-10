#include <iostream>

#include "templates.hh"
using namespace std;

template <typename T>
void templatedPrint(const T& in){
    cout << "Templated print of type " << typeid(T).name() << ": " << in << endl;
}
// Full template specialisation
/*template<>
void templatedPrint(const player &in){
    cout << "Template specialisation: Player Profile." << endl << in << endl;
    return;
}
*/
int main(){
    templatedPrint(2);
    templatedPrint(5.0);
    templatedPrint("Hello World");
    myVec<int> three(3); 
    try{
    three[0] = 1;
    three[1] = 2;
    three[2] = 3;
    three[4] = 4;}
    catch(range_error &e){
        cout << "Invalid index: " << e.what() << endl;
    }

    cout << three << endl; 
}