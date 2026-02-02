#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool available;

public:
    Book(int i, string t, string a) : id(i), title(t), author(a), available(true) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void borrowBook() { available = false; }
    void returnBook() { available = true; }

    void display() const {
        cout << "ID: " << id << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (available ? "Available" : "Borrowed") << endl;
    }
};

class User {
private:
    int userId;
    string name;
    vector<int> borrowedBooks;

public:
    User(int id, string n) : userId(id), name(n) {}

    int getId() const { return userId; }
    string getName() const { return name; }

    void borrow(int bookId) { borrowedBooks.push_back(bookId); }

    void returnBook(int bookId) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
    }
};

class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully." << endl;
    }

    void removeBook(int id) {
        auto it = remove_if(books.begin(), books.end(),
            [id](Book& b) { return b.getId() == id; });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book removed successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    void addUser(const User& user) {
        users.push_back(user);
        cout << "User added successfully." << endl;
    }

    void searchByTitle(const string& title) const {
        bool found = false;
        for (const auto& b : books) {
            if (b.getTitle() == title) {
                b.display();
                found = true;
            }
        }
        if (!found) cout << "No book with that title found." << endl;
    }

    void borrowBook(int bookId) {
        for (auto& b : books) {
            if (b.getId() == bookId) {
                if (b.isAvailable()) {
                    b.borrowBook();
                    cout << "Book borrowed successfully." << endl;
                } else {
                    cout << "Book is already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void returnBook(int bookId) {
        for (auto& b : books) {
            if (b.getId() == bookId) {
                b.returnBook();
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void displayBooks() const {
        for (const auto& b : books) {
            b.display();
        }
    }
};

int main() {
    Library lib;

    lib.addBook(Book(1, "C++ Basics", "Bjarne"));
    lib.addBook(Book(2, "OOP Concepts", "James"));

    lib.addUser(User(1, "Alice"));

    int choice;
    do {
        cout << "\n1. Display Books\n2. Search Book by Title\n3. Borrow Book\n4. Return Book\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            lib.displayBooks();
        } else if (choice == 2) {
            string title;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            lib.searchByTitle(title);
        } else if (choice == 3) {
            int id;
            cout << "Enter book ID: ";
            cin >> id;
            lib.borrowBook(id);
        } else if (choice == 4) {
            int id;
            cout << "Enter book ID: ";
            cin >> id;
            lib.returnBook(id);
        }
    } while (choice != 5);

    return 0;
}
