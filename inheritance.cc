#include <iostream>
#include <string>

#include "inheritanceDef.hh"
using namespace std;

int main(void){
    midfielder adam ("adam", 10);
    defender isabel ("isabel", 10);
    player jack ("jack");
    invertedFB janet ("janet", 8, 8, 9);
    player* p1 = &adam;
    player* p2 = &isabel;
    player* p3 = &janet;
    cout << p1->preGame();
    cout << p2->preGame();
    cout << jack.preGame();
    cout << p3->preGame();
    return 0;
}