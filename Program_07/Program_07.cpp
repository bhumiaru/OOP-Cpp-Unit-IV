#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and cin
#include <limits>               // Used with numeric_limits
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names

int main() {                     // Main function starts

    ofstream outputFile("students.txt", ios::app); // Opens file in append mode

    if (!outputFile) {                       // Checks whether file opened
        cout << "Error: Could not open students.txt\n"; // Displays error
        return 1;                            // Stops program
    }

    int rollNumber;                          // Stores student's roll number
    string name;                             // Stores student's name
    double marks;                            // Stores student's marks

    cout << "Enter roll number: ";           // Asks for roll number
    cin >> rollNumber;                       // Takes roll number

    cout << "Enter name: ";                  // Asks for name

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Clears remaining characters from input buffer

    getline(cin, name);                      // Reads complete name including spaces

    cout << "Enter marks: ";                 // Asks for marks
    cin >> marks;                            // Takes marks

    outputFile << rollNumber << '|' << name << '|' << marks << '\n';
    // Writes student information into file using | as separator

    cout << "Student record saved successfully.\n"; // Displays success

    return 0;                                // Ends program
}
