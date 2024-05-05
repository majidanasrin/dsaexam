#include <iostream>
using namespace std;

const int MAX_CATALOG_SIZE = 100;
const int MAX_STACK_SIZE = 100;

class Library {
private:
    int catalog[MAX_CATALOG_SIZE];
    int top;
    int checkoutStack[MAX_STACK_SIZE];
    int stackTop;

public:
    Library() {
        top = -1;
        stackTop = -1;
    }

    void addBook(int isbn) {
        if (top < MAX_CATALOG_SIZE - 1) {
            catalog[++top] = isbn;
            cout << "Book with ISBN " << isbn << " added to catalog." << endl;
        } else {
            cout << "Catalog is full. Cannot add more books." << endl;
        }
    }

    void displayCatalog() {
        cout << "Library Catalog:" << endl;
        for (int i = 0; i <= top; ++i) {
            cout << catalog[i] << endl;
        }
    }

    bool searchByISBN(int isbn) {
        for (int i = 0; i <= top; ++i) {
            if (catalog[i] == isbn) {
                cout << "Book with ISBN " << isbn << " found in catalog." << endl;
                return true;
            }
        }
        cout << "Book with ISBN " << isbn << " not found in catalog." << endl;
        return false;
    }

    void checkoutBook(int isbn) {
        if (top >= 0) {
            checkoutStack[++stackTop] = catalog[top--];
            cout << "Book with ISBN " << isbn << " checked out." << endl;
        } else {
            cout << "Catalog is empty. Cannot check out books." << endl;
        }
    }

    void displayCheckedOutBooks() {
        cout << "Checked-out Books Stack:" << endl;
        for (int i = stackTop; i >= 0; --i) {
            cout << checkoutStack[i] << endl;
        }
    }

    void returnBook(int isbn) {
        if (stackTop >= 0 && checkoutStack[stackTop] == isbn) {
            catalog[++top] = checkoutStack[stackTop--];
            cout << "Book with ISBN " << isbn << " returned." << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found in checked-out books." << endl;
        }
    }
};

int main() {
    Library library;

    int choice, isbn;

    do {
        cout << "\nLibrary Management System Menu:" << endl;
        cout << "1. Add Book\n2. Display Catalog\n3. Search by ISBN\n4. Checkout Book\n5. Display Checked-out Books\n6. Return Book\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ISBN of the book to add: ";
                cin >> isbn;
                library.addBook(isbn);
                break;
            case 2:
                library.displayCatalog();
                break;
            case 3:
                cout << "Enter ISBN to search: ";
                cin >> isbn;
                library.searchByISBN(isbn);
                break;
            case 4:
                cout << "Enter ISBN of the book to checkout: ";
                cin >> isbn;
                library.checkoutBook(isbn);
                break;
            case 5:
                library.displayCheckedOutBooks();
                break;
            case 6:
                cout << "Enter ISBN of the book to return: ";
                cin >> isbn;
                library.returnBook(isbn);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}