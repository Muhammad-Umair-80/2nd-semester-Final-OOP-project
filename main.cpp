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
        greetUser();
        // New feature: Allow user to search for a keyword in all info files
        auto searchInFiles = [](const string& keyword) {
            vector<string> files = {
                "department.txt", "campus.txt", "faculty.txt",
                "admission.txt", "timings.txt", "rules.txt", "contact.txt"
            };
            bool found = false;
            for (const auto& file : files) {
                ifstream infile(file);
                if (!infile) continue;
                string line;
                int lineNum = 1;
                while (getline(infile, line)) {
                    if (line.find(keyword) != string::npos) {
                        cout << "[" << file << " - line " << lineNum << "]: " << line << endl;
                        found = true;
                    }
                    ++lineNum;
                }
            }
            if (!found) {
                cout << "No results found for \"" << keyword << "\" in any file.\n";
            }
        };

        cout << "8. Search Information\n";
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

            if (chice == 0){
                cout << "Exiting the chatbot. Goodbye!" << endl;
                break;
            }
            cout << endl;
            cout << endl;
            switch (choice) {
                case 1:
                    cout << "--- Department Information ---\n";
                    displayFromFile("department.txt");
                    break;
                case 2:
                    cout << "--- Campus Facilities ---\n";
                    displayFromFile("campus.txt");
                    break;
                case 3:
                    cout << "--- Faculty Information ---\n";
                    displayFromFile("faculty.txt");
                    break;
                case 4:
                    cout << "--- Admission Information ---\n";
                    displayFromFile("admission.txt");
                    break;
                case 5:
                    cout << "--- Class Timings ---\n";
                    displayFromFile("timings.txt");
                    break;
                case 6:
                    cout << "--- Rules & Regulations ---\n";
                    displayFromFile("rules.txt");
                    break;
                case 7:
                    cout << "--- Contact & Location ---\n";
                    displayFromFile("contact.txt");
                    break;
                default:
                    cout << "Invalid choice. Please select a number from 0 to 7.\n";
            }
            cout << "\nPress Enter to return to the main menu...";
            cin.get();
        }
    }
    // You can add more chatbot features here if needed.
    // For example, a function to greet the user or provide help.
    void greetUser() {
        cout << "Hello! I'm your University Chatbot. How can I assist you today?\n";
    }
};

int main() {
    UniversityChatbot bot;
    bot.run();
    return 0;
}

        