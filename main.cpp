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
};
class UniversityChatbot : public chatbot{
    public:
    void run(){
        while (true){
            cout<< "\nWelcome to the University Chatbot! \n";
            cout<< "1. Department information \n";
            cout<< "2. Campus facilities \n";
            cout<< "3. Faculty information \n";
            cout << "4. Admission Info\n";
            cout << "5. Class Timings\n";
            cout << "6. Rules & Regulations\n";
            cout << "7. Contact & Location\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            
            int choice;
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }
}
