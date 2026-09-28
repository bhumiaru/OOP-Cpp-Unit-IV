#include <cstdio>               // Provides remove() and rename()
#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and cin
#include <limits>               // Used with numeric_limits
#include <sstream>              // Used for stringstream
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names


void addStudent() {              // Function to add a student

    ofstream outputFile("student_records.txt", ios::app);
    // Opens student file in append mode

    if (!outputFile) {           // Checks whether file opened

        cout << "Error: Could not open student_records.txt\n";
        // Displays error

        return;                  // Returns to main function
    }

    int rollNumber;              // Stores roll number
    string name;                 // Stores name
    double marks;                // Stores marks

    cout << "Enter roll number: "; // Asks roll number
    cin >> rollNumber;             // Reads roll number

    cout << "Enter name: ";         // Asks name

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Clears input buffer

    getline(cin, name);            // Reads complete name

    cout << "Enter marks: ";       // Asks marks
    cin >> marks;                  // Reads marks

    outputFile << rollNumber << '|' << name << '|' << marks << '\n';
    // Saves record in file

    cout << "Record added successfully.\n";
    // Displays success message
}


void displayStudents() {          // Function to display all students

    ifstream inputFile("student_records.txt");
    // Opens student file for reading

    if (!inputFile) {             // Checks whether file exists

        cout << "No student record file found.\n";
        // Displays error

        return;                   // Returns to main
    }

    string line;                  // Stores one line

    cout << "\nRoll No.\tName\t\tMarks\n";
    // Displays table heading

    cout << "----------------------------------------\n";
    // Displays separator

    while (getline(inputFile, line)) {
        // Reads records one by one

        stringstream record(line);
        // Converts line into a stream

        string rollText;          // Stores roll number
        string name;              // Stores name
        string marksText;          // Stores marks

        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText)) {
            // Separates record using | symbol

            cout << rollText << "\t\t"
                 << name << "\t\t"
                 << marksText << '\n';
            // Displays student data
        }
    }
}


void searchStudent() {            // Function to search student

    ifstream inputFile("student_records.txt");
    // Opens student file

    if (!inputFile) {             // Checks file

        cout << "No student record file found.\n";
        // Displays error

        return;                   // Returns
    }

    int targetRoll;               // Stores roll number to search

    cout << "Enter roll number to search: ";
    // Asks user

    cin >> targetRoll;            // Reads roll number

    string line;                  // Stores each line
    bool found = false;           // Tracks whether student is found

    while (getline(inputFile, line)) {
        // Reads records line by line

        stringstream record(line);
        // Creates stream from line

        string rollText;          // Stores roll number text
        string name;              // Stores name
        string marksText;          // Stores marks

        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText)) {
            // Separates data

            if (stoi(rollText) == targetRoll) {
                // Converts roll text to integer and compares

                cout << "Record Found\n";
                // Displays found message

                cout << "Roll Number: " << rollText << '\n';
                // Displays roll number

                cout << "Name: " << name << '\n';
                // Displays name

                cout << "Marks: " << marksText << '\n';
                // Displays marks

                found = true;     // Marks record as found

                break;            // Stops searching
            }
        }
    }

    if (!found) {                 // Checks if not found

        cout << "Student not found.\n";
        // Displays not found message
    }
}


void updateMarks() {              // Function to update marks

    ifstream inputFile("student_records.txt");
    // Opens original file for reading

    ofstream temporaryFile("student_records_temp.txt");
    // Creates temporary file

    if (!inputFile || !temporaryFile) {
        // Checks both files

        cout << "Error: Could not open record file(s).\n";
        // Displays error

        return;                   // Returns
    }

    int targetRoll;               // Stores roll number
    double newMarks;              // Stores new marks

    cout << "Enter roll number to update: ";
    cin >> targetRoll;            // Reads roll number

    cout << "Enter new marks: ";
    cin >> newMarks;              // Reads new marks

    string line;                  // Stores each line
    bool found = false;           // Tracks student

    while (getline(inputFile, line)) {
        // Reads file line by line

        stringstream record(line);
        // Converts line into stream

        string rollText;          // Stores roll number
        string name;              // Stores name
        string marksText;          // Stores marks

        if (getline(record, rollText, '|') &&
            getline(record, name, '|') &&
            getline(record, marksText)) {
            // Separates fields

            if (stoi(rollText) == targetRoll) {
                // Checks matching roll number

                temporaryFile << rollText << '|' << name
                              << '|' << newMarks << '\n';
                // Writes updated record

                found = true;     // Marks record found
            }
            else {

                temporaryFile << line << '\n';
                // Copies unchanged record
            }
        }
    }

    inputFile.close();             // Closes original file
    temporaryFile.close();         // Closes temporary file

    if (!found) {                  // Checks if student was not found

        remove("student_records_temp.txt");
        // Deletes temporary file

        cout << "Student not found. No changes made.\n";
        // Displays message

        return;                    // Returns
    }

    if (remove("student_records.txt") != 0 ||
        rename("student_records_temp.txt", "student_records.txt") != 0) {
        // Removes old file and renames temporary file

        cout << "Error: Could not replace the record file.\n";
        // Displays error

        return;                    // Returns
    }

    cout << "Marks updated successfully.\n";
    // Displays success
}


int main() {                       // Main function starts

    int choice;                    // Stores menu choice

    do {                           // Starts do-while loop

        cout << "\nStudent Record Manager\n";
        // Displays menu heading

        cout << "1. Add Student\n";
        // Option 1

        cout << "2. Display All Students\n";
        // Option 2

        cout << "3. Search Student\n";
        // Option 3

        cout << "4. Update Marks\n";
        // Option 4

        cout << "0. Exit\n";
        // Option 0

        cout << "Enter choice: ";
        // Asks user for choice

        cin >> choice;             // Reads choice

        switch (choice) {           // Checks selected option

            case 1:
                addStudent();       // Calls add student function
                break;              // Stops this case

            case 2:
                displayStudents();  // Calls display function
                break;              // Stops this case

            case 3:
                searchStudent();    // Calls search function
                break;              // Stops this case

            case 4:
                updateMarks();      // Calls update function
                break;              // Stops this case

            case 0:
                cout << "Exiting program.\n";
                // Displays exit message
                break;              // Stops this case

            default:
                cout << "Invalid choice. Try again.\n";
                // Handles invalid choice
        }

    } while (choice != 0);          // Repeats until user selects 0

    return 0;                       // Ends program
}
