#include <iostream>
#include <string> 
using namespace std;

// متغيرات لتخزين بيانات الكتاب
int bookids[100];
string bookTitles[100];
string bookAuthors[100];
bool isBorrowed[100];
int bookcount = 0;

// إضافة كتاب جديد
void addBook() {
    cout << "Enter the book id: ";
    cin >> bookids[bookcount];

    cout << "Enter the book title (no spaces): ";
    cin >> bookTitles[bookcount];

    cout << "Enter the book author (no spaces): ";
    cin >> bookAuthors[bookcount];

    isBorrowed[bookcount] = false;
    bookcount++;

    cout << "Book added successfully.\n";
}

//اعرض قائمة بجميع الكتب المتوفرة في المكتبة.
void displayBooks() {
    if (bookcount == 0) {
        cout << "No books are available in the library.\n";
        return;
    }

    cout << "\n=== Book List ===\n";

    for (int i = 0; i < bookcount; i++) {
        cout << "ID: " << bookids[i]
             << ", Title: " << bookTitles[i]
             << ", Author: " << bookAuthors[i];
        if (isBorrowed[i]) {
            cout << ", Status: Borrowed" << endl; 
        } 
        else {
            cout << ", Status: Available" << endl; 
        }
    }
    cout << "====\n"; 
}

//استعير كتاباً اذا كان متاحاً
void borrowBook() {
    cout << "Enter the book ID to borrow: ";

    int id;
    cin >> id;

    bool found = false;
    for (int i = 0; i < bookcount; i++) {
        if (bookids[i] == id) {
            found = true;

            if (isBorrowed[i]) {
                cout << "This book is already borrowed.\n";
                return;
            }

            isBorrowed[i] = true;
            cout << "You have successfully borrowed the book: " << bookTitles[i] << "\n";
            return;
        }
    }

    if (!found) {
        cout << "Book ID not found.\n";
    }
}

//قم بإعادة الكتاب المستعار ليصبح متاحاً مرة اخرى
void returnBook() {
    cout << "Enter the book ID to return: ";

    int id;
    cin >> id;

    bool found = false;
    for (int i = 0; i < bookcount; i++) {
        if (bookids[i] == id) {
            found = true;
            if (!isBorrowed[i]) {
                cout << "This book was not borrowed.\n";
                return;
            }

            isBorrowed[i] = false;
            cout << "Book returned successfully.\n";
            return;
        }
    }

    if (!found) {
        cout << "Book ID not found.\n";
    }
}

void menu() {
    while (true) {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add a new book\n";
        cout << "2. Display all books\n";
        cout << "3. Borrow a book\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            borrowBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            cout << "Goodbye!\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
