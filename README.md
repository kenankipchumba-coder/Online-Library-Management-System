# Online-Library-Management-System
Simple Online Library Management System using C++ and OOP

ONLINE LIBRARY MANAGEMENT SYSTEM
BSD 122 – Object Oriented Programming I

1. INTRODUCTION
This project implements a simple Online Library Management System using C++ 
and Object-Oriented Programming (OOP) principles. The system allows users to 
manage books, search for books, borrow and return books through a menu-driven interface.

2. SYSTEM DESIGN AND CLASSES

2.1 Book Class
The Book class represents a library book.
Attributes:
- id
- title
- author
- availability status

Methods:
- borrowBook()
- returnBook()
- display()

2.2 User Class
The User class represents a library user.
Attributes:
- user ID
- user name
- list of borrowed books

Methods:
- borrow()
- returnBook()

2.3 Library Class
The Library class manages books and users.
Responsibilities:
- Add and remove books
- Register users
- Search books by title
- Handle borrowing and returning of books

3. OBJECT-ORIENTED CONCEPTS USED
- Encapsulation: Class data members are private and accessed through public methods.
- Abstraction: Classes hide internal details and expose only required functionality.
- Modularity: Each class handles a specific responsibility.

4. HOW TO COMPILE AND RUN THE PROGRAM

Requirements:
- C++ compiler (g++)

Steps:
1. Open the project folder in the terminal.
2. Compile the program using:
   g++ library.cpp -o library
3. Run the program using:
   ./library
4. Follow the menu options displayed on the screen.

5. TESTING
The system was tested using both positive and negative test cases.
Test cases are documented in the file test_cases.txt.

6. CONCLUSION
This project demonstrates the application of Object-Oriented Programming concepts
to build a simple and functional library management system.
