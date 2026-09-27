#include <cstring>              // Provides strncpy()
#include <fstream>              // Used for binary file handling
#include <iostream>             // Used for cout
using namespace std;             // Allows direct use of standard names

struct StudentRecord {           // Defines a structure for student information

    int rollNumber;              // Stores roll number

    char name[30];               // Stores student name as character array

    float marks;                 // Stores marks
};

int main() {                     // Main function starts

    StudentRecord student{};     // Creates student object and initializes it

    student.rollNumber = 101;    // Assigns roll number

    strncpy(student.name, "Amit Patil", sizeof(student.name) - 1);
    // Copies name into character array

    student.marks = 85.5F;       // Assigns marks

    {                            // Starts separate block

        ofstream outputFile("students.dat", ios::binary);
        // Opens binary file for writing

        if (!outputFile) {       // Checks whether file opened
            cout << "Error: Could not create students.dat\n";
            return 1;            // Stops program
        }

        outputFile.write(
            reinterpret_cast<const char*>(&student),
            sizeof(student)
        );
        // Converts structure address into character pointer
        // write() stores binary data into file
    }

    StudentRecord readStudent{}; // Creates structure for reading data

    {                            // Starts another block

        ifstream inputFile("students.dat", ios::binary);
        // Opens binary file for reading

        if (!inputFile) {        // Checks file
            cout << "Error: Could not open students.dat\n";
            return 1;            // Stops program
        }

        inputFile.read(
            reinterpret_cast<char*>(&readStudent),
            sizeof(readStudent)
        );
        // Reads binary data from file into structure

        if (!inputFile) {        // Checks whether reading was successful
            cout << "Error: Could not read record from students.dat\n";
            return 1;            // Stops program
        }
    }

    cout << "Roll Number: " << readStudent.rollNumber << '\n';
    // Displays roll number

    cout << "Name: " << readStudent.name << '\n';
    // Displays name

    cout << "Marks: " << readStudent.marks << '\n';
    // Displays marks

    return 0;                    // Ends program
}
