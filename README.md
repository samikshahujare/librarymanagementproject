# 📚 Library Management System

Welcome to the Library Management System, a comprehensive and user-friendly C-based application to efficiently manage a library. This system provides essential functionalities, including book management, user registration, and fine calculation, making it suitable for both academic and small-scale libraries.

---

## ✨ Features
- User Management:
  - Register new users with a unique ID and password.
  - Secure login system to access library services.
- Book Management:
  - Add, delete, and search for books in the library.
  - View all books along with their availability status.
- Borrow and Return Books:
  - Issue books to users with a limit of 3 books per user.
  - Return books with fine calculation for overdue items.
- Reports and Statistics:
  - View the total number of books, issued books, and available books.
  - Detailed fine system display.
- User-Friendly Interface:
  - Highlighted menus and color-coded messages for easy navigation.

---

## 🛠️ Technologies Used
- Programming Language: C
- Libraries:
  - <stdio.h>: Standard input and output operations.
  - <stdlib.h>: Memory management and utility functions.
  - <string.h>: String manipulation functions.
  - <time.h>: Time management for fine calculations.

---

## 🚀 How to Run the Program
1. Clone the Repository:
  
Bash

   git clone https://github.com/your-repository/library-management-system.git
   cd library-management-system
   
2. Compile the Program:
   Use any C compiler like GCC:
  
Bash

   gcc library_management.c -o library_management
   
3. Run the Program:
  
Bash

   ./libraryfinal.c
   
---

## 📖 Usage Instructions

### Initial Menu
1. Register User: Create a new user profile to access the system.
2. Login User: Log in using your User ID and password.
3. Exit: Exit the program.

---

### Main Menu (Post Login)
| Option           | Description                                                                                  |
|-----------------------|--------------------------------------------------------------------------------------------------|
| 1. Add Book       | Add new books to the library.                                                                   |
| 2. Delete Book    | Remove a book from the library.                                                                 |
| 3. Search Book    | Search for a book by its ID.                                                                    |
| 4. Reserve Book   | Reserve an available book.                                                                      |
| 5. Issue Book     | Issue a book to a user.                                                                         |
| 6. Return Book    | Return a book and calculate fines if overdue.                                                   |
| 7. List All Books | Display all books in the library with their availability status.                                 |
| 8. Fine System    | View the fine structure (10rs/day after 14 days).                                             |
| 9. Reports        | Display library statistics, including total books, issued books, and available books.           |
| 10. Logout        | Logout from the current user session.                                                           |
| 11. Exit          | Close the application.                                                                          |

---

## 📊 Fine System
- Borrow Limit: 3 books per user.
- Borrow Duration: 14 days without a fine.
- Fine: 10rs/day after 14 days. Maximum fine is 50rs.

---

## 📂 Sample Data
### Books
| ID | Title                       | Author               | Status       |
|--------|----------------------------------|--------------------------|------------------|
| 1      | Data Structures                 | Thareja                  | Available        |
| 2      | Discrete Mathematics            | Kenneth H. Rosen         | Available        |
| 3      | Computer Networks               | Andrew S. Tanenbaum      | Available        |
| 4      | Operating System Concepts       | Abraham Silberschatz     | Available        |
| 5      | Database System Concepts        | Abraham Silberschatz     | Available        |

---

## 🌟 Highlights
- Modular Code Structure: Functions like addBook, deleteBook, and issueBook make the system extensible.
- Color-Coded UI: Colorful messages and menus ensure a pleasant user experience.
  - Green: Success messages.
  - Red: Error messages.
  - Yellow: Warnings and menu options.
  - Blue: Input prompts.

---

## 👥 Contributing
1. Fork the repository.
2. Create a new branch:
  
Bash

   git checkout -b feature-name
   
3. Commit your changes:
  
Bash

   git commit -m "Add new feature"
   
4. Push your changes:
  
Bash

   git push origin feature-name
   
5. Submit a pull request.

---


 






