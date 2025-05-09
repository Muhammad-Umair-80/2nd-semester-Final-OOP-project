#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
class chatbot{
    protected:
    void displayFromFile(const string& filename){
        ifstream file(filename);
        if (!infile){
            cerr << "Error opening file: " << filename << endl;
            return;
        }
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close();
    }
}
