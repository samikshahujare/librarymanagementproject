#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100
#define MAX_USERS 100
#define MAX_FINE 50
#define MAX_BORROW_LIMIT 3
#define MAX_DAYS_WITHOUT_FINE 14
#define FINE_PER_DAY 10

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

typedef struct {
    int id;
    char title[50];
    char author[50];
    int isIssued;
    time_t issueDate;
} Book;

typedef struct {
    int id;
    char name[50];
    char password[20];
    int borrowedBookIds[MAX_BORROW_LIMIT];
    int borrowedBookCount;
} User;

Book books[MAX_BOOKS];
User users[MAX_USERS];
int bookCount = 0;
int userCount = 0;
int loggedInUser = -1; // Indicates no user is logged in

// Function prototypes
void registerUser();
void loginUser();
void showLimitedMenu();
void showMainMenu();
void addBook();
void deleteBook();
void searchBook();
void reserveBook();
void issueBook();
void returnBook();
void listBooks();
void displayFineSystem();
void displayReports();
void printBanner();

int main() {
    int choice;

    printBanner();

    // Add sample books
    strcpy(books[bookCount].title, "Data Structures");
    strcpy(books[bookCount].author, "Thareja");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

     strcpy(books[bookCount].title, "Discrete Mathematics");
    strcpy(books[bookCount].author, "Kenneth H. Rosen");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Computer Networks");
    strcpy(books[bookCount].author, "Andrew S. Tanenbaum");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Operating System Concepts");
    strcpy(books[bookCount].author, "Abraham Silberschatz");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Database System Concepts");
    strcpy(books[bookCount].author, "Abraham Silberschatz");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Introduction to Algorithms");
    strcpy(books[bookCount].author, "Thomas H. Cormen");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Theory of Computation");
    strcpy(books[bookCount].author, "Michael Sipser");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Artificial Intelligence");
    strcpy(books[bookCount].author, "Stuart Russell");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Digital Logic Design");
    strcpy(books[bookCount].author, "Morris Mano");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Signals and Systems");
    strcpy(books[bookCount].author, "Alan V. Oppenheim");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Computer Architecture");
    strcpy(books[bookCount].author, "John L. Hennessy");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Software Engineering");
    strcpy(books[bookCount].author, "Ian Sommerville");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Compiler Design");
    strcpy(books[bookCount].author, "Aho, Lam, Sethi, Ullman");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Embedded Systems");
    strcpy(books[bookCount].author, "Raj Kamal");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    strcpy(books[bookCount].title, "Machine Learning");
    strcpy(books[bookCount].author, "Tom M. Mitchell");
    books[bookCount].id = ++bookCount;
    books[bookCount - 1].isIssued = 0;

    while (1) {
        if (loggedInUser == -1) {
            showLimitedMenu();
        } else {
            showMainMenu();
        }

        scanf("%d", &choice);

        if (loggedInUser == -1) {
            switch (choice) {
                case 1: registerUser(); break;
                case 2: loginUser(); break;
                case 3: exit(0);
                default: printf(RED "Invalid choice! Please try again.\n" RESET);
            }
        } else {
            switch (choice) {
                case 1: addBook(); break;
                case 2: deleteBook(); break;
                case 3: searchBook(); break;
                case 4: reserveBook(); break;
                case 5: issueBook(); break;
                case 6: returnBook(); break;
                case 7: listBooks(); break;
                case 8: displayFineSystem(); break;
                case 9: displayReports(); break;
                case 10: 
                    printf(GREEN "User logged out successfully!\n" RESET);
                    loggedInUser = -1;
                    break;
                case 11: exit(0);
                default: printf(RED "Invalid choice! Please try again.\n" RESET);
            }
        }
    }

    return 0;
}

// Print program banner
void printBanner() {
    printf(GREEN "\t\t\t\t\t\t************************************************\n");
    printf("\t\t\t\t\t\t**                                            **\n");
    printf("\t\t\t\t\t\t**         Library Management System          **\n");
    printf("\t\t\t\t\t\t**                                            **\n");
    printf("\t\t\t\t\t\t************************************************\n" RESET);
}

// Show limited menu for register/login
void showLimitedMenu() {
    printf(CYAN "\n Menu:\n" RESET);
    printf(YELLOW "1. Register User\n");
    printf("2. Login User\n");
    printf("3. Exit\n" RESET);
    printf("Enter your choice: ");
}

// Show main menu after login
void showMainMenu() {
   printf(CYAN "\n\t\t\t\t\t\t\t  *************************\n");
    printf("\t\t\t\t\t\t\t  **                     **\n");
    printf("\t\t\t\t\t\t\t  **      MAIN MENU      **\n");
    printf("\t\t\t\t\t\t\t  **                     **\n");
    printf("\t\t\t\t\t\t\t  *************************\n" RESET);
    printf(YELLOW "1. Add Book\n");
    printf("2. Delete Book\n");
    printf("3. Search Book\n");
    printf("4. Reserve Book\n");
    printf("5. Issue Book\n");
    printf("6. Return Book\n");
    printf("7. List All Books\n");
    printf("8. Display Fine System\n");
    printf("9. Display Reports\n");
    printf("10. Logout\n");
    printf("11. Exit\n" RESET);
    printf("Enter your choice: ");
}

// Register a new user
void registerUser() {
    if (userCount < MAX_USERS) {
        printf(BLUE "Enter User ID: " RESET);
        scanf("%d", &users[userCount].id);
        printf(BLUE "Enter Name: " RESET);
        scanf("%s", users[userCount].name);
        printf(BLUE "Enter Password: " RESET);
        scanf("%s", users[userCount].password);
        users[userCount].borrowedBookCount = 0;
        userCount++;
        printf(GREEN "User registered successfully!\n" RESET);
    } else {
        printf(RED "User limit reached!\n" RESET);
    }
}

// Login user
void loginUser() {
    int id;
    char password[20];
    printf(BLUE "Enter User ID: " RESET);
    scanf("%d", &id);
    printf(BLUE "Enter Password: " RESET);
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id && strcmp(users[i].password, password) == 0) {
            loggedInUser = i;
            printf(GREEN "Login successful! Welcome, %s.\n" RESET, users[i].name);
            return;
        }
    }
    printf(RED "Invalid ID or Password.\n" RESET);
}

// Other operations (addBook, deleteBook, etc.) remain unchanged...

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf(CYAN "Enter Book ID: " RESET);
        scanf("%d", &books[bookCount].id);
        printf(CYAN "Enter Book Title: " RESET);
        scanf("%s", books[bookCount].title);
        printf(CYAN "Enter Author: " RESET);
        scanf("%s", books[bookCount].author);
        books[bookCount].isIssued = 0;
        bookCount++;
        printf(GREEN "Book added successfully!\n" RESET);
    } else {
        printf(RED "Library is full!\n" RESET);
    }
}
void deleteBook() {
    int id;
    printf(CYAN "Enter Book ID to delete: " RESET);
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            books[i] = books[bookCount - 1];
            bookCount--;
            printf(GREEN "Book deleted successfully!\n" RESET);
            return;
        }
    }
    printf(RED "Book not found.\n" RESET);
}

// Search for a book
void searchBook() {
    int id;
    printf(CYAN "Enter Book ID to search: " RESET);
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf(GREEN "Book found: %s by %s\n" RESET, books[i].title, books[i].author);
            return;
        }
    }
    printf(RED "Book not found.\n" RESET);
}

// Reserve a book
void reserveBook() {
    int id;
    printf(CYAN "Enter Book ID to reserve: " RESET);
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id && books[i].isIssued == 0) {
            printf(GREEN "Book reserved successfully.\n" RESET);
            return;
        }
    }
    printf(RED "Book is already issued or not available.\n" RESET);
}

// Issue a book to a user
void issueBook() {
    int userId, bookId;
    printf(CYAN "Enter User ID: " RESET);
    scanf("%d", &userId);
    printf(CYAN "Enter Book ID to issue: " RESET);
    scanf("%d", &bookId);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && books[i].isIssued == 0) {
            books[i].isIssued = 1;
            books[i].issueDate = time(NULL);
            printf(GREEN "Book issued successfully!\n" RESET);
            return;
        }
    }
    printf(RED "Book is already issued or not available.\n" RESET);
}

// Return a book
void returnBook() {
    int bookId;
    printf(CYAN "Enter Book ID to return: " RESET);
    scanf("%d", &bookId);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && books[i].isIssued == 1) {
            books[i].isIssued = 0;
            time_t now = time(NULL);
            int daysLate = (now - books[i].issueDate) / (60 * 60 * 24) - MAX_DAYS_WITHOUT_FINE;
            if (daysLate > 0) {
                printf(RED "Book is overdue. Fine to pay: %drs\n" RESET, daysLate * FINE_PER_DAY);
            } else {
                printf(GREEN "Book returned successfully without any fine.\n" RESET);
            }
            return;
        }
    }
    printf(RED "Book not found or not issued.\n" RESET);
}

// List all books
void listBooks() {
    printf(CYAN "\nBook List:\n" RESET);
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s, Status: %s\n", books[i].id, books[i].title, books[i].author, books[i].isIssued ? "Issued" : "Available");
    }
}

// Display fine system
void displayFineSystem() {
    printf(CYAN "\nFine System:  %drs per day after %d days.\n" RESET, FINE_PER_DAY, MAX_DAYS_WITHOUT_FINE);
}

// Display reports (summary of issued books)
void displayReports() {
    int issuedCount = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isIssued) issuedCount++;
    }
    printf(CYAN "\nLibrary Reports:\n" RESET);
    printf("Total Books: %d\n", bookCount);
    printf("Issued Books: %d\n", issuedCount);
    printf("Available Books: %d\n", bookCount - issuedCount);
}

