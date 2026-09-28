#include <fstream>              // Used for file handling
#include <iostream>             // Used for cout and cin
#include <limits>               // Used with numeric_limits
#include <sstream>              // Used for stringstream
#include <string>               // Used for string
using namespace std;             // Allows direct use of standard names


class Book {                     // Defines Book class

private:                         // Private members cannot be accessed directly outside class

    int bookId;                  // Stores book ID

    string title;                // Stores book title

    string author;               // Stores author name

    bool issued;                 // Stores book status


public:                          // Public members can be accessed outside class

    Book(int id, string bookTitle, string bookAuthor, bool issueStatus = false)
        : bookId(id), title(move(bookTitle)),
          author(move(bookAuthor)), issued(issueStatus) {}
    // Constructor initializes book data
    // id is assigned to bookId
    // bookTitle is moved to title
    // bookAuthor is moved to author
    // issueStatus is assigned to issued

    int getBookId() const {      // Function returns book ID

        return bookId;           // Returns ID
    }

    string toFileRecord() const { // Converts book data into file format

        return to_string(bookId) + "|" + title + "|" +
               author + "|" + (issued ? "1" : "0");
        // Creates one string containing all book information
    }

    void display() const {       // Function displays book details

        cout << "Book ID: " << bookId << '\n';
        // Displays book ID

        cout << "Title: " << title << '\n';
        // Displays title

        cout << "Author: " << author << '\n';
        // Displays author

        cout << "Status: " << (issued ? "Issued" : "Available") << '\n';
        // Displays Issued if issued is true
        // Otherwise displays Available
    }
};


void addBook() {                 // Function to add a book

    int id;                      // Stores book ID
    string title;                // Stores title
    string author;               // Stores author

    cout << "Enter book ID: ";   // Asks for book ID
    cin >> id;                   // Reads book ID

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Clears input buffer

    cout << "Enter title: ";     // Asks for title
    getline(cin, title);         // Reads complete title

    cout << "Enter author: ";    // Asks for author
    getline(cin, author);        // Reads complete author name

    Book book(id, title, author);
    // Creates Book object

    ofstream outputFile("library_books.txt", ios::app);
    // Opens library file in append mode

    if (!outputFile) {           // Checks whether file opened

        cout << "Error: Could not open library_books.txt\n";
        // Displays error

        return;                  // Returns to main
    }

    outputFile << book.toFileRecord() << '\n';
    // Converts book into file record and saves it

    cout << "Book added successfully.\n";
    // Displays success
}


void displayBooks() {             // Function to display all books

    ifstream inputFile("library_books.txt");
    // Opens library file for reading

    if (!inputFile) {             // Checks file

        cout << "No library record file found.\n";
        // Displays error

        return;                   // Returns
    }

    string line;                  // Stores one record line

    while (getline(inputFile, line)) {
        // Reads file line by line

        stringstream record(line);
        // Converts line into stream

        string idText;            // Stores book ID as text
        string title;             // Stores title
        string author;             // Stores author
        string issuedText;         // Stores issue status

        if (getline(record, idText, '|') &&
            getline(record, title, '|') &&
            getline(record, author, '|') &&
            getline(record, issuedText)) {
            // Separates four fields using | symbol

            Book book(stoi(idText), title, author, issuedText == "1");
            // Converts ID to integer and creates Book object

            book.display();
            // Displays book information

            cout << "-------------------------\n";
            // Displays separator
        }
    }
}


int main() {                      // Main function starts

    int choice;                   // Stores menu choice

    do {                          // Starts do-while loop

        cout << "\nLibrary Record System\n";
        // Displays menu heading

        cout << "1. Add Book\n";
        // Option 1

        cout << "2. Display Books\n";
        // Option 2

        cout << "0. Exit\n";
        // Option 0

        cout << "Enter choice: ";
        // Asks user for choice

        cin >> choice;            // Reads choice

        switch (choice) {          // Checks selected choice

            case 1:
                addBook();         // Calls addBook()
                break;             // Stops case

            case 2:
                displayBooks();    // Calls displayBooks()
                break;             // Stops case

            case 0:
                cout << "Exiting program.\n";
                // Displays exit message
                break;             // Stops case

            default:
                cout << "Invalid choice.\n";
                // Handles invalid choice
        }

    } while (choice != 0);         // Repeats until choice is 0

    return 0;                      // Ends program
}
