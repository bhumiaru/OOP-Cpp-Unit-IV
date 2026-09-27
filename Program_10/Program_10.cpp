#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout
#include <string>               // Used for string-related operations
using namespace std;             // Allows direct use of standard names

int main() {                     // Main function starts

    fstream file("navigation.txt", ios::in | ios::out | ios::trunc);
    // Opens file for both reading and writing
    // ios::in = input/read mode
    // ios::out = output/write mode
    // ios::trunc = clears old file contents

    if (!file) {                 // Checks whether file opened
        cout << "Error: Could not open navigation.txt\n";
        return 1;                // Stops program
    }

    file << "ABCDE";             // Writes ABCDE into file

    cout << "Output position after writing: " << file.tellp() << '\n';
    // tellp() gives current output/write position

    file.flush();                // Forces buffered data to be written

    file.seekg(0, ios::beg);     // Moves input/read pointer to beginning

    char firstCharacter;         // Stores first character

    file.get(firstCharacter);    // Reads one character

    cout << "First character: " << firstCharacter << '\n';
    // Displays first character

    cout << "Input position after reading one character: "
         << file.tellg() << '\n';
    // tellg() gives current input/read position

    file.seekg(2, ios::beg);     // Moves read pointer to position 2

    char thirdCharacter;         // Stores character at position 2

    file.get(thirdCharacter);    // Reads character at position 2

    cout << "Character at position 2: " << thirdCharacter << '\n';
    // Displays character

    file.seekp(5, ios::beg);     // Moves write pointer to position 5

    file << "F";                 // Writes F at position 5

    file.close();                // Closes file

    cout << "Navigation completed. Check navigation.txt\n";
    // Displays completion message

    return 0;                    // Ends program
}
