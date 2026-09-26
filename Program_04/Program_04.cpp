#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout
#include <string>               // Used for string data type
using namespace std;             // Allows direct use of standard names

int main() {                     // Main function starts

    ifstream sourceFile("message.txt");       // Opens source file for reading
    ofstream destinationFile("message_copy.txt"); // Creates destination file for writing

    if (!sourceFile) {                         // Checks source file
        cout << "Error: Could not open source file.\n"; // Displays error
        return 1;                              // Stops program
    }

    if (!destinationFile) {                    // Checks destination file
        cout << "Error: Could not create destination file.\n"; // Displays error
        return 1;                              // Stops program
    }

    string line;                               // Stores each line temporarily

    while (getline(sourceFile, line)) {        // Reads source file line by line
        destinationFile << line << '\n';       // Writes each line into destination file
    }

    cout << "File copied successfully to message_copy.txt\n"; // Displays success

    return 0;                                  // Ends program
}
