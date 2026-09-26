#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and cin
#include <string>               // Used for string data type
using namespace std;             // Allows use of standard library names directly

int main() {                     // Main function starts

    ifstream inputFile("message.txt");      // Opens message.txt for reading

    if (!inputFile) {                        // Checks whether the file opened successfully
        cout << "Error: Could not open message.txt\n"; // Displays error
        return 1;                            // Stops program with error
    }

    string line;                             // Creates a string variable to store each line

    cout << "File Content:\n";               // Displays heading

    while (getline(inputFile, line)) {       // Reads one complete line from the file
        cout << line << '\n';                // Displays the line on the screen
    }

    inputFile.close();                       // Closes the file

    return 0;                                // Ends program successfully
}
