#include <cstring>              // Provides strncpy()
#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and cin
using namespace std;             // Allows direct use of standard names

struct StudentRecord {           // Defines student record structure

    int rollNumber;              // Stores roll number

    char name[30];               // Stores name

    float marks;                 // Stores marks
};

void addRecord(ofstream& file, int rollNumber, const char* name, float marks) {
    // Function used to add one student record

    StudentRecord student{};     // Creates and initializes student structure

    student.rollNumber = rollNumber; // Assigns roll number

    strncpy(student.name, name, sizeof(student.name) - 1);
    // Copies name into structure

    student.marks = marks;       // Assigns marks

    file.write(
        reinterpret_cast<const char*>(&student),
        sizeof(student)
    );
    // Writes complete structure into binary file
}

int main() {                     // Main function starts

    {                            // Starts block for writing

        ofstream outputFile("records.dat", ios::binary | ios::trunc);
        // Opens binary file and clears previous data

        if (!outputFile) {       // Checks file
            cout << "Error: Could not create records.dat\n";
            return 1;            // Stops program
        }

        addRecord(outputFile, 101, "Amit", 85.5F);
        // Adds first record

        addRecord(outputFile, 102, "Neha", 91.0F);
        // Adds second record

        addRecord(outputFile, 103, "Ravi", 78.0F);
        // Adds third record
    }

    ifstream inputFile("records.dat", ios::binary);
    // Opens binary file for reading

    if (!inputFile) {            // Checks file
        cout << "Error: Could not open records.dat\n";
        return 1;                // Stops program
    }

    int recordNumber;             // Stores record number entered by user

    cout << "Enter record number to read (1 to 3): ";
    // Asks user for record number

    cin >> recordNumber;         // Reads record number

    if (recordNumber < 1 || recordNumber > 3) {
        // Checks whether record number is invalid

        cout << "Invalid record number.\n";
        return 1;                // Stops program
    }

    const streamoff offset =
        static_cast<streamoff>(recordNumber - 1) *
        static_cast<streamoff>(sizeof(StudentRecord));
    // Calculates byte position of selected record

    inputFile.seekg(offset, ios::beg);
    // Moves read pointer to calculated position

    StudentRecord selectedStudent{};
    // Creates structure to store selected record

    inputFile.read(
        reinterpret_cast<char*>(&selectedStudent),
        sizeof(selectedStudent)
    );
    // Reads selected record

    if (!inputFile) {             // Checks reading
        cout << "Error: Could not read selected record.\n";
        return 1;                 // Stops program
    }

    cout << "Roll Number: " << selectedStudent.rollNumber << '\n';
    // Displays roll number

    cout << "Name: " << selectedStudent.name << '\n';
    // Displays name

    cout << "Marks: " << selectedStudent.marks << '\n';
    // Displays marks

    return 0;                    // Ends program
}
