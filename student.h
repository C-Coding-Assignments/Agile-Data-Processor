#ifndef STUDENT
#define STUDENT

#include <stdio.h>

//macro definition for the maximum length of the user's inputs
#define MAX_LENGTH 100

//struct definition for Student which defines the members that each student obtains
struct Student
{
    char name[MAX_LENGTH + 1], netID[MAX_LENGTH + 1], copGrade;
    double gpa;
    int attempts;
    struct Student *next;
    struct Student *previous;
};

//calling MenuManager struct since it is used in some of the function pointers' definitions
struct MenuManager;

//struct defintion for ListManager which defines the function pointers that are used to modify the doubly linked list of students
struct ListManager
{
    struct Student *(*addPtr)(struct Student *, struct Student *);
    struct Student *(*deletePtr)(struct Student *, struct Student *);
    void (*printListPtr)(const struct Student *, const struct MenuManager *);
    struct Student *(*deleteAllPtr)(struct Student *);
    struct Student *(*sortPtr)(struct Student *, const struct ListManager *);
    struct Student *(*sortLogicPtr)(struct Student *, struct Student *, struct Student *, const int *, const struct ListManager *);
    void (*swapPtr)(struct Student *, struct Student *, struct Student *);
    struct Student *(*reversePtr)(struct Student *, const struct ListManager *);
};

//struct definition for MenuManager which defines
struct MenuManager
{
    void (*menuPtr)();
    struct Student *(*addStudentPtr)(struct Student *, const struct ListManager *);
    struct Student *(*removeStudentPtr)(struct Student *, const struct ListManager *);
    void (*modifyStudentPtr)(struct Student *, const struct ListManager *, const struct MenuManager *);
    void (*printStudentPtr)(const struct Student *);
    void (*printMinGpaPtr)(const struct Student *, const struct MenuManager *);
    void (*printMinGradePtr)(const struct Student *, const struct MenuManager *);
};

//function prototype for menu which prints the menu to the screen
void menu();

//function prototype for initializeListManager which initializes the function pointers of ListManager
void initializeListManager(struct ListManager *);

//function prototype for initializeMenuManager which initializes the function pointers of MenuManager
void initializeMenuManager(struct MenuManager *);

//function prototype for addMenu which prints the add student to the queue menu
void addMenu();

//function prototype for removeNewline which removes new-line characters from the string that is passed as an argument
void removeNewline(char *);

//function prototype for modifyStudent which modifies students within the linked list
void modifyStudent(struct Student *, const struct ListManager *, const struct MenuManager *);

//function prototype for addStudent which adds a student to the linked list and returns the new head of the linked list after adding the student
struct Student *addStudent(struct Student *, const struct ListManager *);

//function prototype for getName which gets the name of the student from the user and modifies the string that is passed as an argument
void getName(char *);

//function prototype for getNetID which gets the netID of the student from the user and modifies the string that is passed as an argument
void getNetID(char *);

//function prototype for getGrade which gets the grade of the student from the user and modifies the string that is passed as an argument
void getGrade(char *);

//function prototype for getGpa which gets the GPA of the student from the user and modifies the string that is passed as an argument
double getGpa(char *);

//function prototype for getAttempts which gets the number of attempts the student has made in the course from the user and modifies the string that is passed as an argument
int getAttempts(char *);

//function prototype for add which adds a student to the end of the linked list
struct Student *add(struct Student *, struct Student *);

//function prototype for removeStudent which removes a student from the linked list
struct Student *removeStudent(struct Student *, const struct ListManager *);

//function prototype for printList which prints the students in the list
void printList(const struct Student *, const struct MenuManager *);

//function prototype for printStudent which helps to print the students in the list
void printStudent(const struct Student *);

//function prototype for printMinGpa which helps to print the students in the list who have earned a minimum gpa given by the user
void printMinGpa(const struct Student *, const struct MenuManager *);

//function prototype for printMinGrade which helps to print the students in the list who have earned a minimum grade given by the user
void printMinGrade(const struct Student *, const struct MenuManager *);

//function prototype for sortMenu which prints the sorting menu to the user
void sortMenu();

//function prototype for sort which sorts the linked list of students based on the user's selection
struct Student *sort(struct Student *, const struct ListManager *);

//function prototype for sortLogic which sorts the linked list of students based on the user's selection and swaps the nodes if necessary
struct Student *sortLogic(struct Student *, struct Student *, struct Student *, const int *, const struct ListManager *);

//function prototype for swap which swaps two nodes within the linked list based on the user's selection of sorting criteria and order
void swap(struct Student *, struct Student *, struct Student *);

//function prototype for reverse which reverses the linked list of students
struct Student *reverse(struct Student *, const struct ListManager *);

//function prototype for delete which deletes a node from the linked list
struct Student *delete(struct Student *, struct Student *);

//function prototype for deleteAll which deletes all the nodes within the linked list
struct Student *deleteAll(struct Student *);

//function prototype for writeStudents which writes the linked list of students and stores the information in the file given by the file pointer
void writeStudents(FILE *, const struct Student *);

#endif