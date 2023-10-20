#include <iostream>
#include <vector>
#include <string>
#include<iomanip>
using namespace std;
class Book {
public:
    Book(const string& title, const string& author, const string& isbn, int year)
        : title(title), author(author), isbn(isbn), year(year) {}

    const string& getISBN() const {
        return isbn;
    }

    const string& getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }
    const string& getTitle() const {
        return title;
    }

    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Year of Publication: " << year << endl;
    }

private:
    string title;
    string author;
    string isbn;
    int year;
};
void printIntro() {
    cout << setw(80) << "************************************************" << endl;
    cout << setw(78) << "  Welcome to the Winchester Library Adventure!" << endl;
    cout << setw(80) << "************************************************" << endl;

    cout << setw(100) << "Prepare to embark on a literary journey,filled with knowledge, imagination, and wonder." << endl;

    cout << setw(80) << "Are you ready to dive into the world of words?" << endl;

    cout << setw(77) << "Press 1 to continue to the library menu." << endl;
}
class Library {
public:

    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added to the library." << endl;
    }

    bool removeBookByISBN(const string& isbn) {
        for (auto bookiterator = books.begin(); bookiterator != books.end(); ++bookiterator) {
            if (bookiterator->getISBN() == isbn) {
                books.erase(bookiterator);
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                cout << "Book with ISBN " << isbn << " removed from the library." << endl;
                cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                return true;
            }
        }
        cout << "Book with ISBN " << isbn << " not found in the library." << endl;
        return false;
    }
    void findBooksPublishedAfter(int year) {
        bool found = false;
        cout << "Books published after " << year << ":" << endl;
        for (const Book& book : books) {
            if (book.getYear() > year) {
                book.displayInfo();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found published after " << year << "." << endl;
        }
    }
    void findBooksByAuthor(const string& author) {
        bool found = false;
        cout << "Books by " << author << ":" << endl;
        for (const Book& book : books) {
            if (book.getAuthor() == author) {
                book.displayInfo();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found by " << author << "." << endl;
        }
    }
    void displayCatalog() {
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(70) << "          Your Library Catalog          " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

        if (books.empty()) {
            cout << "Your library is currently empty." << endl;
        }
        else {
            cout << setw(30) << "Title" << setw(30) << "Author" << setw(15) << "ISBN" << setw(15) << "Year" << endl;
            cout << "-----------------------------------------------------------------------------------------------" << endl;

            for (const Book& book : books) {
                cout << setw(30) << book.getTitle() << setw(30) << book.getAuthor() << setw(15) << book.getISBN() << setw(15) << book.getYear() << endl;
            }
        }

        cout << "----------------------------------------------------------------------------------------------" << endl;
    }
    void closeLibrary() {
        cout << setw(80) << "***************************************************" << endl;
        cout << setw(78) << "    Thank you for your library adventure!" << endl;
        cout << setw(80) << "***************************************************" << endl;

        cout << setw(110) << "As you exit the world of books and stories,remember that your library is a gateway to endless" << endl;
        cout << setw(80) << "adventures, knowledge, and imagination." << endl;
        cout << setw(80) << "***************************************************" << endl;
        cout << setw(64) << "Let's hope I did good :)" << endl;
        cout << setw(80) << "***************************************************" << endl;
    }
private:
    vector<Book> books;
};
void displayMenu() {
    cout << "-----------------------------------------" << endl;
    cout << "               Library Menu              " << endl;
    cout << "-----------------------------------------" << std::endl;
    cout << "1. Add a book to your collection" << std::endl;
    cout << "2. Remove a book from your collection" << std::endl;
    cout << "3. Search for books by a specific author" << std::endl;
    cout << "4. Search for books published after a specific year" << std::endl;
    cout << "5. Display your library catalog" << std::endl;
    cout << "6. Quit the library adventure" << std::endl;
    cout << "-----------------------------------------" << std::endl;
    cout << "Enter the number of your choice: ";
}
int main() {
    printIntro();
    //this part of code i found it on google ;)
    int choice;
    cin >> choice;
    if (choice == 1) {
#ifdef _WIN32
        system("cls"); // For Windows
#else
        system("clear"); // For other systems
#endif
    }
    Library library;
    Book book1("The Catcher in the Rye", "J.D. Salinger", "ISBN1", 1951);
    Book book2("To Kill a Mockingbird", "Harper Lee", "ISBN2", 1960);
    Book book3("1984", "George Orwell", "ISBN3", 1949);
    Book book4("The Great Gatsby", "F. Scott Fitzgerald", "ISBN4", 1925);
    Book book5("Pride and Prejudice", "Jane Austen", "ISBN5", 1813);

    // Add the sample books to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);

    while (true) {
        displayMenu();
        cout << "Choose an option:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Remove a book" << endl;
        cout << "3. Search books by author" << endl;
        cout << "4. Search books published after a year" << endl;
        cout << "5. Display catalog" << endl;
        cout << "6. Quit" << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            string title, author, isbn;
            int year;
            cin.ignore(); // Clear the newline character from the input buffer.
            cout << "Enter the title: ";
            //cin >> title;
            getline(cin, title);
            cout << "Enter the author: ";
            //cin >> author;
            getline(cin, author);
            cout << "Enter the ISBN: ";
            getline(cin, isbn);
            // cin >> isbn;
            cout << "Enter the year of publication: ";
            cin >> year;
            Book newBook(title, author, isbn, year);
            library.addBook(newBook);
        }
        else if (choice == 2) {
            string isbn;
            cout << "Enter the ISBN of the book you want to remove: ";
            cin >> isbn;
            library.removeBookByISBN(isbn);
        }
        else if (choice == 3) {
            cin.ignore();
            string author;
            cout << "Enter the author's name to search for: ";
            // cin >> author;
            getline(cin, author);
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            library.findBooksByAuthor(author);
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
        else if (choice == 4) {
            int year;
            cout << "Enter the year to search for books published after: ";
            cin >> year;
            library.findBooksPublishedAfter(year);
        }
        else if (choice == 5)
        {
            //displayCatalog(library);
            library.displayCatalog();
        }
        else if (choice == 6) {
            library.closeLibrary();
            break; // Quit the program.
        }
        else {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}
