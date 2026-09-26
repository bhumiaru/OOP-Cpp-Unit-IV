#include <fstream>              // Used for file input and output
#include <iostream>             // Used for cout and other input/output operations
using namespace std;             // Allows us to use cout without writing std::cout

int main() {                     // Main function: program execution starts here

    ofstream outputFile("message.txt");   // Creates and opens message.txt for writing

    if (!outputFile) {                     // Checks whether the file was opened successfully
        cout << "Error: Could not create message.txt\n"; // Displays error message
        return 1;                          // Stops the program with an error code
    }

    outputFile << "Welcome to C++ File Handling\n";       // Writes first line into the file
    outputFile << "This is the first line written to a file.\n"; // Writes second line
    outputFile << "Files store data permanently.\n";      // Writes third line

    outputFile.close();                      // Closes the file

    cout << "Data written successfully to message.txt\n"; // Displays success message

    return 0;                                // Ends the program successfully
}
