// Adam Graham
// Testing file streams and parsing
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include "streams.hh"
using namespace std;
int main(void){
    try{
    // Append strings and random numbers to file
    // Generate random numbers
    random_device dev;
    mt19937 rng(dev());
    uniform_real_distribution<double> rDist(0.0,1.0);
    // Setting win probability for 3 people
    double pA = rDist(rng);
    double pB = rDist(rng);
    double pC = rDist(rng);
    ofstream outfile;
    outfile.open("store.txt");  // Opening file
    // Appending strings to file
    outfile <<  "I think the probability of Adam who is aged 23 going the full way and winning: " << pA << endl <<
                "Probability of Brian aged 25 winning: " << pB << 
                "Also perhaps the probability of Charlie who is aged 34 beating out the competitors and winning: " << pC << endl;
    outfile.close();    // Close file
    
    ifstream infile;    // Open file 
    infile.open("store.txt");
    // Check that file opened correctly
    if (!infile.is_open()){
        throw ios_base::failure("Failed to open file");
    }
    vector<person> people;  // Vector to store people in file
    while(!infile.eof()){
        string junk;
        int age;
        string name;
        double wProb;
        // File format: Name of person will be after "of"
        int iter = 0;
        while (iter < 10){
            junk.clear();
            infile >> junk;
            if (junk == "of"){
                break;
            }
            // If "of" is not encountered after 10 words of start of line, throw error
            ++iter;
            if (iter == 10){
                throw invalid_argument("File input has incorrect format - no name found");
            }
        }
        infile >> name;     // Read in name
        // Repeat process for age, should be after "aged"
        iter = 0;
        while (iter < 10){
            junk.clear();
            infile >> junk;
            if (junk == "aged")
                break;
            ++iter;
            if (iter == 10){
                throw invalid_argument("File input has incorrect format - no age found");
            }
        }
        infile >> age; 

        // Repeat process for win probability
        iter = 0;

        while (iter < 10){
            junk.clear();
            infile >> junk;
            if (junk == "winning:")
                break;
            ++iter;
            if (iter == 10){
                throw invalid_argument("File input has incorrect format - no win probability found");
            }
        }
        infile >> wProb;
        infile >> junk;
        // Append a new person object to the people vector.
        people.push_back(person(age, name, wProb));
    }
    // Print people
    for (person p : people){
        cout << p << endl;
    }
    }
    // Catch any exceptions thrown throughout
    catch (invalid_argument &e){
        cout << "Invalid argument encountered: " << e.what() << endl;
    }
    catch (ios_base::failure &e){
        cout << "IO error: " << e.what() << endl;
    }
    catch (exception &e){
        cout <<"Unknown exception encountered: " << e.what() << endl;
    }
    return 0;
}