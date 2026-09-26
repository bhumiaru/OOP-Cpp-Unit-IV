#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout
using namespace std;             // Allows use of cout without std::

int main() {                     // Main function starts

    ofstream outputFile("message.txt", ios::app); // Opens file in append mode

    if (!outputFile) {                     // Checks whether file opened successfully
        cout << "Error: Could not open message.txt for appending\n"; // Displays error
        return 1;                          // Stops program
    }

    outputFile << "This line was added using append mode.\n"; // Adds data at end of file

    outputFile.close();                    // Closes the file

    cout << "New line appended successfully.\n"; // Displays success message

    return 0;                              // Ends program
}
