#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Book {
    char name[30];
    char author[30];
    int id;
    Book* next;
};

struct Student {
    char name[30];
    char email[20];
    char book[20];
    char a[30];
    int id;
    Student* next;
};

Book* start_lib = nullptr;
Student* start = nullptr;

Book* initializeLib(Book* start);
Student* bookIssue(Student* start);
Student* bookReturn(Student* start);
Book* displayLib(Book* start);
Book* deleteBook(int id);
Book* addBook(const char[], const char[], int);
void display(Student*);
void greetings();
void mainMenu();

int main() {
    start_lib = initializeLib(start_lib);
    greetings();
    mainMenu();
    return 0;
}

void greetings() {
    cout << "\n\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *     ----------------------------     *\n";
    cout << "\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n";
    cout << "\t\t\t     *     ----------------------------     *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\n\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *       ------------------------       *\n";
    cout << "\t\t\t     *           STUDENT LIBRARY            *\n";
    cout << "\t\t\t     *       ------------------------       *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *       Mumbai,Maharashtra,India       *\n";
    cout << "\t\t\t     *     Email: studentlib@gmail.com      *\n";
    cout << "\t\t\t     *     Contact:8800991010,8800992020    *\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\n\n\t\t\t             Press any key to continue: ";
    cin.get();
}

void mainMenu() {
    int choice;
    do {
        cout << "\n\n";
        cout << "\n\t\t\t*************************************************\n";
        cout << "\n\t\t\t\t      MAIN MENU: ";
        cout << "\n\t\t\t\t     1.ISSUE OF BOOKS ";
        cout << "\n\t\t\t\t     2.RETURN OF BOOKS ";
        cout << "\n\t\t\t\t     3.DISPLAY STUDENT DETAILS ";
        cout << "\n\t\t\t\t     3.DISPLAY LIBRARY BOOKS  ";
        cout << "\n\t\t\t\t     5.EXIT\n ";
        cout << "\n\t\t\t*************************************************\n";
        cout << "\n\t\t\t\t      Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                start = bookIssue(start);
                break;
            }
            case 2: {
                start = bookReturn(start);
                break;
            }
            case 3: {
                display(start);
                break;
            }
            case 4: {
                start_lib = displayLib(start_lib);
                break;
            }

            case 5: {
                exit(1);
            }
            default: {
                cout << "\n\t\t\t\t      ...Invalid Option!...\n";
                cout << "\n\t\t\t\t      Press any key to try again: ";
                cin.get();
            }
        }
    } while (choice != 4);
}

Book* initializeLib(Book* start) {
    Book* ptr;
    Book* newBook1;
    Book* newBook2;
    Book* newBook3;
    Book* newBook4;
    Book* newBook5;

    newBook1 = new Book;
    newBook1->next = nullptr;
    start_lib = newBook1;
    strcpy(newBook1->name, "House of Flame and Shadow");
    strcpy(newBook1->author, "Sarah J.Maas");
    newBook1->id = 101;
    ptr = newBook1;

    newBook2 = new Book;
    newBook2->next = nullptr;
    strcpy(newBook2->name, "To Kill A Mockingbird");
    strcpy(newBook2->author, "Harper Lee");
    newBook2->id = 102;
    ptr->next = newBook2;
    ptr = newBook2;

    newBook3 = new Book;
    newBook3->next = nullptr;
    strcpy(newBook3->name, "Harry Potter and the Philosopher's Stone");
    strcpy(newBook3->author, "J.K.Rowling");
    newBook3->id = 103;
    ptr->next = newBook3;
    ptr = newBook3;

    newBook4 = new Book;
    newBook4->next = nullptr;
    strcpy(newBook4->name, "Pride And Prejudice");
    strcpy(newBook4->author, "Jane Austen");
    newBook4->id = 104;
    ptr->next = newBook4;
    ptr = newBook4;

    newBook5 = new Book;
    newBook5->next = nullptr;
    strcpy(newBook5->name, "Atimic Habits");
    strcpy(newBook5->author, "James Clear");
    newBook5->id = 105;
    ptr->next = newBook5;

    return start_lib;
}

Student* bookIssue(Student* start) {
    Book* ptr;
    Student* ptr2;
    Student* newStudent;
    int i = 1, id, flag = 0;
    if (start_lib == nullptr) {
        cout << "\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n";
    } else {
        system("cls");
        ptr = start_lib;
        cout << "\n\t*************** Books Available: ****************\n";
        while (ptr != nullptr) {
            cout << "\n\t_________________________________________________\n";
            cout << "\n\t Book " << i;
            cout << "\n\t Book Title: " << ptr->name;
            cout << "\n\t Name of Author: " << ptr->author;
            cout << "\n\t Book ID: " << ptr->id;
            cout << "\n\t_________________________________________________\n";
            ptr = ptr->next;
            i++;
        }
        cout << "\n\n\t Enter the Book ID: ";
        cin >> id;
        ptr = start_lib;
        while (ptr != nullptr) {
            if (ptr->id == id) {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1) {
            ptr = start_lib;
            while (ptr->id != id) {
                ptr = ptr->next;
            }
            newStudent = new Student;
            cout << "\n\t Enter Student Details:\n ";
            cout << "\n\t Enter your Name: ";
            cin >> newStudent->name;
            cout << "\n\t Enter your Email: ";
            cin >> newStudent->email;
            strcpy(newStudent->book, ptr->name);
            strcpy(newStudent->a, ptr->author);
            newStudent->id = ptr->id;
            newStudent->next = nullptr;
            cout << "\n\t Issue of Book ID " << newStudent->id << " done successfully!\n";
            cout << "\n\n\t*************************************************\n";
            if (start == nullptr) {
                start = newStudent;
            } else {
                ptr2 = start;
                while (ptr2->next != nullptr) {
                    ptr2 = ptr2->next;
                }
                ptr2->next = newStudent;
            }
            start_lib = deleteBook(newStudent->id);
            cout << "\n\n\t Press any key to go to the main menu: ";
            cin.get();
            system("cls");
        } else {
            cout << "\n\t\t      ...Invalid Option!...\n";
            cout << "\n\t\t      Press any key to try again: ";
            cin.get();
            system("cls");
        }
    }
    return start;
}

Student* bookReturn(Student* start) {
    Student* ptr;
    Student* preptr;
    char bookname[30], authorname[30];
    int flag = 0, id, identity, c = 0, d = 1;
    cout << "\n\n\t*************** Books Submission: ****************\n";
    cout << "\n\n\t Enter your Book ID: ";
    cin >> identity;
    ptr = start;
    while (ptr != nullptr) {
        if (ptr->id == identity) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 1) {
        ptr = start;
        while (ptr != nullptr) {
            c++;
            ptr = ptr->next;
        }
        ptr = start;
        while (ptr->id != identity) {
            d++;
            ptr = ptr->next;
        }
        ptr = start;
        if (d == 1) {
            cout << "\n\t_________________________________________________\n";
            cout << "\n\t Student Name: " << start->name;
            cout << "\n\t Student Email: " << start->email;
            cout << "\n\t Name of Book Issued: " << start->book;
            cout << "\n\t_________________________________________________\n";
            cout << "\n\n\t Return of Book ID " << identity << " done successfully!\n";
            cout << "\n\n\t*************************************************\n";
            strcpy(bookname, start->book);
            strcpy(authorname, start->a);
            id = start->id;
            start = start->next;
            delete ptr;
            addBook(bookname, authorname, id);
        } else {
            ptr = start;
            while (ptr->id != identity) {
                preptr = ptr;
                ptr = ptr->next;
            }
            cout << "\n\t_________________________________________________\n";
            cout << "\n\t Student Name: " << ptr->name;
            cout << "\n\t Student Email: " << ptr->email;
            cout << "\n\t Name of Book Issued: " << ptr->book;
            cout << "\n\t Book ID: " << ptr->id;
            cout << "\n\t_________________________________________________\n";
            strcpy(bookname, ptr->book);
            strcpy(authorname, ptr->a);
            id = ptr->id;
            preptr->next = ptr->next;
            delete ptr;
            addBook(bookname, authorname, id);
        }
        cout << "\n\t Thank you! \n\t Do visit again! ";
        cout << "\n\n\t Press any key to go to the main menu: ";
        cin.get();
        system("cls");
    } else {
        cout << "\n\tSorry the book doesn't exist! Please recheck the entered ID";
        cout << "\n\t\t\t\t      Press any key to try again: ";
        cin.get();
        system("cls");
    }
    return start;
}

void display(Student* start) {
    Student* ptr = start;
    while (ptr != nullptr) {
        cout << "\n\t************* Details of Students: **************\n";
        cout << "\n\t_________________________________________________\n";
        cout << "\n\t\t Student Name: " << ptr->name;
        cout << "\n\t\t Student Email: " << ptr->email;
        cout << "\n\t\t Name of Book Issued: " << ptr->book;
        cout << "\n\t\t Book ID: " << ptr->id;
        cout << "\n\t_________________________________________________\n";
        cout << "\n\n\t*************************************************\n";
        ptr = ptr->next;
    }
    cout << "\n\n\t Press any key to go to the main menu: ";
    cin.get();
    // system("cls");
}

Book* deleteBook(int id) {
    Book* ptr;
    Book* preptr;
    int c = 0;
    ptr = start_lib;
    while (ptr != nullptr) {
        c++;
        ptr = ptr->next;
    }
    if (c == 1) {
        ptr = start_lib;
        start_lib = nullptr;
        delete ptr;
    } else if (start_lib->id == id) {
        ptr = start_lib;
        start_lib = start_lib->next;
        delete ptr;
    } else {
        ptr = start_lib;
        while (ptr->id != id) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        delete ptr;
    }
    return start_lib;
}

   
Book* addBook(const char bookname[30], const char authorname[30], int id) {
    Book* ptr;
    Book* newBook = new Book;
    strcpy(newBook->name, bookname);
    strcpy(newBook->author, authorname);
    newBook->id = id;
    newBook->next = nullptr;

    if (start_lib == nullptr) {
        start_lib = newBook;
    } else {
        ptr = start_lib;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newBook;
    }

    return start_lib;
}

Book* displayLib(Book* start) {
    Book* ptr = start;
    while (ptr != nullptr) {
        cout << "\n\t*************** Details of Books Available: **************\n";
        cout << "\n\t_________________________________________________\n";
        cout << "\n\t Book Title: " << ptr->name;
        cout << "\n\t Author: " << ptr->author;
        cout << "\n\t Book ID: " << ptr->id;
        cout << "\n\t_________________________________________________\n";
        cout << "\n\n\t*************************************************\n";
        ptr = ptr->next;
    }
    cout << "\n\n\t Press any key to go back to the main menu: ";
    cin.ignore();
    cin.get();
    system("cls");

    return start;
}


