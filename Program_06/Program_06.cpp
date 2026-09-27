#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and cin
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names

int main() {                     // Main function starts

    ifstream inputFile("message.txt");        // Opens message.txt for reading

    if (!inputFile) {                         // Checks whether file opened
        cout << "Error: Could not open message.txt\n"; // Displays error
        return 1;                             // Stops program
    }

    string searchWord;                        // Stores word entered by user

    cout << "Enter word to search: ";         // Asks user for word
    cin >> searchWord;                        // Reads word from keyboard

    string word;                              // Stores each word from file
    int count = 0;                            // Stores number of occurrences

    while (inputFile >> word) {               // Reads words one by one

        if (word == searchWord) {             // Compares file word with searched word
            ++count;                          // Increases occurrence count
        }
    }

    cout << "The word '" << searchWord << "' occurred "
         << count << " time(s).\n";            // Displays result

    return 0;                                 // Ends program
}
