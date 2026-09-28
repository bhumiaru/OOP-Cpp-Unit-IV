#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names

int main() {                     // Main function starts

    ifstream inputFile("missing_file.txt");
    // Attempts to open missing_file.txt

    if (!inputFile.is_open()) {  // Checks whether file failed to open

        cout << "Error: File could not be opened.\n";
        // Displays error message

        cout << "Check whether missing_file.txt exists in the current folder.\n";
        // Gives user information about the problem

        return 1;                // Stops program
    }

    string line;                 // Stores each line

    while (getline(inputFile, line)) {
        // Reads file line by line

        cout << line << '\n';    // Displays each line
    }

    if (inputFile.eof()) {       // Checks whether end of file was reached

        cout << "End of file reached normally.\n";
        // Displays normal EOF message

    }
    else if (inputFile.bad()) {  // Checks for serious input/output error

        cout << "A serious file I/O error occurred.\n";
        // Displays serious error

    }
    else if (inputFile.fail()) { // Checks for logical read failure

        cout << "A logical file read error occurred.\n";
        // Displays logical error
    }

    return 0;                    // Ends program
}
