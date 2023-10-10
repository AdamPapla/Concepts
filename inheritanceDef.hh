#include <iostream>
#include <string>

using namespace std;
// Base class
class player{
public:
    // Define constructor
    player(string name) : name {name} {cout << "Constructing player " << name << endl;}
    // Define virtual destructor, want to use runtime polymorphism
    virtual ~player(){cout << "Calling destructor for player " << name << endl;}
    string getName(){return name;}  // Getter for name - unavailable in derived classes
    virtual string preGame(){   // Declare as virtual- will be overridden in derived classes
        return name + " starts\n"; 
    }
private:
    string name;
};

// Definition for defender class
// Inherits from player class. Inheritance must be virtual to avoid conflicts with inheritance hierarchy
class defender : virtual public player{
public:
    defender(string name, int quality) : player(name), defending {quality}{cout << "Constructing defender " << name << endl;}
    string preGame() override{  // Override base class
        return getName() + " starts in defence\n";
    }
private:
    int defending;
};

// Definition for midfielder class
class midfielder : virtual public player{
public:
    midfielder(string name, int quality) : player(name), vision {quality}{cout << "Constructing midfielder " << name << endl;}
    string preGame() override;  // Declare preGame function. Defn outside class
private:
    int vision;
};
string midfielder::preGame(){   // Do not use override keyword outside class definition
    return getName() + " starts in midfield\n";
}

// Class to inherit from both midfielder and defender, creating a diamond.
// Testing virtual class inheritance, avoids having 2 copies of player: 1 from defender, 1 from midfielder
class invertedFB : public defender, public midfielder{
public: 
    invertedFB(string name, int defending, int vision, int versatility) : player (name), defender(name, defending), midfielder(name, vision), 
                                                                          versatility {versatility} {cout << "Constructing inverted full back " << name << endl;}
    string preGame() override{
        return getName() + " starts as an full-back, though we'll likely see him provide a midfield overload in possession\n";
    }
private:
    int versatility;
};

