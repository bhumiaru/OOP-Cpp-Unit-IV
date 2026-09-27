#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and cin
#include <sstream>              // Used for stringstream
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names

int main() {                     // Main function starts

    ifstream inputFile("students.txt");      // Opens student file for reading

    if (!inputFile) {                        // Checks whether file opened
        cout << "Error: Could not open students.txt\n"; // Displays error
        return 1;                            // Stops program
    }

    int targetRollNumber;                    // Stores roll number to search

    cout << "Enter roll number to search: "; // Asks user for roll number
    cin >> targetRollNumber;                 // Reads roll number

    string line;                             // Stores one complete line
    bool found = false;                      // Stores whether record is found

    while (getline(inputFile, line)) {       // Reads file line by line

        stringstream record(line);           // Converts line into a stream

        string rollText;                     // Stores roll number as text
        string name;                         // Stores student name
        string marksText;                    // Stores marks as text

        if (getline(record, rollText, '|') && // Reads roll number
            getline(record, name, '|') &&     // Reads name
            getline(record, marksText)) {     // Reads marks

            int rollNumber = stoi(rollText);  // Converts text to integer
            double marks = stod(marksText);   // Converts text to double

            if (rollNumber == targetRollNumber) { // Checks matching roll number

                cout << "Record Found\n";    // Displays found message
                cout << "Roll Number: " << rollNumber << '\n'; // Displays roll number
                cout << "Name: " << name << '\n';              // Displays name
                cout << "Marks: " << marks << '\n';            // Displays marks

                found = true;                // Marks record as found
                break;                       // Stops searching
            }
        }
    }

    if (!found) {                            // Checks if record was not found
        cout << "Student record not found.\n"; // Displays not found message
    }

    return 0;                               // Ends program
}
