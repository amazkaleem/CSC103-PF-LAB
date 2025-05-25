#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BOOKS 100

struct Library {
    int accessNum;
    char title[50];
    char authorName[50];
    float bookPrice;
    bool isIssued;
};

void addBook(struct Library books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter accession number: ");
    scanf("%d", &books[*count].accessNum);
    getchar(); // clear newline

    printf("Enter book title: ");
    fgets(books[*count].title, sizeof(books[*count].title), stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = '\0'; // remove newline

    printf("Enter author name: ");
    fgets(books[*count].authorName, sizeof(books[*count].authorName), stdin);
    books[*count].authorName[strcspn(books[*count].authorName, "\n")] = '\0';

    printf("Enter price: ");
    scanf("%f", &books[*count].bookPrice);

    printf("Is the book issued? (1 for Yes, 0 for No): ");
    int issued;
    scanf("%d", &issued);
    books[*count].isIssued = issued;

    (*count)++;
    printf("Book added successfully.\n");
}

void displayBooks(struct Library books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n%-5s %-20s %-20s %-10s %-10s\n", "ID", "Title", "Author", "Price", "Issued");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-20s %-10.2f %-10s\n",
               books[i].accessNum,
               books[i].title,
               books[i].authorName,
               books[i].bookPrice,
               books[i].isIssued ? "Yes" : "No");
    }
}

void listBooksByAuthor(struct Library books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    char author[50];
    getchar();
    printf("Enter author's name: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    printf("Books by %s:\n", author);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].authorName, author) == 0) {
            printf("- %s\n", books[i].title);
            found = true;
        }
    }

    if (!found) {
        printf("No books found by this author.\n");
    }
}

void findBookTitle(struct Library books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    int accNum;
    printf("Enter accession number: ");
    scanf("%d", &accNum);

    for (int i = 0; i < count; i++) {
        if (books[i].accessNum == accNum) {
            printf("Book title: %s\n", books[i].title);
            return;
        }
    }
    printf("Book not found.\n");
}

void countBooks(int count) {
    printf("Total books in the library: %d\n", count);
}

void listBooksByAccession(struct Library books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    // Simple bubble sort by accession number
    struct Library temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].accessNum > books[j + 1].accessNum) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    displayBooks(books, count);
}

int main() {
    int thisChoice;
    struct Library books[MAX_BOOKS];
    int bookCount = 0;

    printf("\nWelcome to the COMSATS Main Library!\n");

    do {
        printf("\n------ Library Menu ------\n");
        printf("1. Add Book Information\n");
        printf("2. Display Book Information\n");
        printf("3. List all books of given author\n");
        printf("4. List the title of specified book\n");
        printf("5. List the count of books in the library\n");
        printf("6. List the books in the order of accession number\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &thisChoice);

        switch (thisChoice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                displayBooks(books, bookCount);
                break;
            case 3:
                listBooksByAuthor(books, bookCount);
                break;
            case 4:
                findBookTitle(books, bookCount);
                break;
            case 5:
                countBooks(bookCount);
                break;
            case 6:
                listBooksByAccession(books, bookCount);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (thisChoice != 7);

    return 0;
}
