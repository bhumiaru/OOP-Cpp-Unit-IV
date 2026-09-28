#include <cctype>               // Provides character checking functions
#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and getline
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names

bool isVowel(char ch) {         // Function checks whether character is a vowel

    ch = static_cast<char>(
        tolower(static_cast<unsigned char>(ch))
    );
    // Converts character to lowercase

    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
    // Returns true if character is a vowel
}

int main() {                    // Main function starts

    string fileName;            // Stores file name

    cout << "Enter file name: "; // Asks user for file name

    getline(cin, fileName);     // Reads complete file name

    ifstream inputFile(fileName); // Opens entered file

    if (!inputFile) {            // Checks whether file opened

        cout << "Error: Could not open " << fileName << '\n';
        // Displays error

        return 1;                // Stops program
    }

    size_t lines = 0;            // Stores number of lines
    size_t words = 0;            // Stores number of words
    size_t characters = 0;       // Stores number of characters
    size_t vowels = 0;            // Stores number of vowels
    size_t digits = 0;            // Stores number of digits
    size_t spaces = 0;            // Stores number of spaces

    bool insideWord = false;     // Tracks whether currently inside a word

    char ch;                     // Stores one character

    while (inputFile.get(ch)) { // Reads one character at a time

        ++characters;            // Increases character count

        if (ch == '\n') {        // Checks newline
            ++lines;             // Increases line count
        }

        if (isspace(static_cast<unsigned char>(ch))) {
            // Checks whether character is whitespace

            if (ch == ' ') {     // Checks for normal space
                ++spaces;        // Increases space count
            }

            insideWord = false; // Marks end of word
        }
        else if (!insideWord) { // Checks beginning of a new word

            ++words;             // Increases word count

            insideWord = true;  // Marks inside a word
        }

        if (isalpha(static_cast<unsigned char>(ch)) && isVowel(ch)) {
            // Checks whether character is alphabetic and a vowel

            ++vowels;            // Increases vowel count
        }

        if (isdigit(static_cast<unsigned char>(ch))) {
            // Checks whether character is a digit

            ++digits;            // Increases digit count
        }
    }

    if (characters > 0) {        // Checks whether file is not empty

        inputFile.clear();       // Clears EOF state

        inputFile.seekg(-1, ios::end);
        // Moves read pointer to last character

        char lastCharacter;      // Stores last character

        inputFile.get(lastCharacter); // Reads last character

        if (lastCharacter != '\n') { // Checks if last line has no newline
            ++lines;              // Counts final line
        }
    }

    cout << "\nFile Statistics\n";       // Displays heading
    cout << "Lines: " << lines << '\n'; // Displays lines
    cout << "Words: " << words << '\n'; // Displays words
    cout << "Characters: " << characters << '\n'; // Displays characters
    cout << "Vowels: " << vowels << '\n'; // Displays vowels
    cout << "Digits: " << digits << '\n'; // Displays digits
    cout << "Spaces: " << spaces << '\n'; // Displays spaces

    return 0;                    // Ends program
}
