#include <cctype>               // Provides character functions like isspace()
#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names

int main() {                     // Main function starts

    ifstream inputFile("message.txt");        // Opens message.txt for reading

    if (!inputFile) {                         // Checks whether file opened
        cout << "Error: Could not open message.txt\n"; // Displays error
        return 1;                             // Stops program
    }

    size_t lineCount = 0;                     // Stores number of lines
    size_t wordCount = 0;                     // Stores number of words
    size_t characterCount = 0;                // Stores number of characters
    bool insideWord = false;                  // Keeps track of whether we are inside a word
    char ch;                                   // Stores one character at a time

    while (inputFile.get(ch)) {               // Reads one character from the file

        ++characterCount;                     // Increases character count by 1

        if (ch == '\n') {                     // Checks for new line character
            ++lineCount;                      // Increases line count
        }

        if (isspace(static_cast<unsigned char>(ch))) { // Checks whether character is whitespace
            insideWord = false;               // We are no longer inside a word
        }
        else if (!insideWord) {               // If character starts a new word
            ++wordCount;                      // Increases word count
            insideWord = true;                // Marks that we are inside a word
        }
    }

    if (characterCount > 0) {                 // Checks if file contains characters

        inputFile.clear();                    // Clears end-of-file state

        inputFile.seekg(-1, ios::end);        // Moves reading pointer to last character

        char lastCharacter;                   // Stores last character

        inputFile.get(lastCharacter);         // Reads last character

        if (lastCharacter != '\n') {          // Checks whether last character is not newline
            ++lineCount;                      // Counts the last incomplete line
        }
    }

    cout << "Lines: " << lineCount << '\n';          // Displays number of lines
    cout << "Words: " << wordCount << '\n';          // Displays number of words
    cout << "Characters: " << characterCount << '\n'; // Displays characters

    return 0;                                // Ends program
}
