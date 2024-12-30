#ifndef STUDENT
#define STUDENT

#include <stdio.h>
#include <stdbool.h>

//macro definition for the maximum length of the user's inputs
#define MAX_LENGTH 100
//macro definition for the total number of possible characters in a student's name
#define ALPHABET_SIZE 55
//macro definition for the ASCII value of an apostrophe
#define APOSTROPHE 39
//macro definition for the trie index that represents if a character in a string is an apostrophe
#define APOSTROPHE_INDEX ALPHABET_SIZE - 3
//macro definition for the ASCII value of a period
#define PERIOD 46
//macro definition for the trie index that represents if a character in a string is a period
#define PERIOD_INDEX ALPHABET_SIZE - 2
//macro definition for the ASCII value of a hyphen
#define HYPHEN 45
//macro definition for the trie index that represents if a character in a string is a hyphen
#define HYPHEN_INDEX ALPHABET_SIZE - 1

//struct definition for Student which defines the members that each student obtains
struct Student
{
    char name[MAX_LENGTH + 1], netID[MAX_LENGTH + 1], copGrade;
    double gpa;
    int attempts;
    struct Student *next;
    struct Student *previous;
};

//struct definition for Trie which defines a trie structure that contains children that it points to and a boolean value representing if the current trie node is the end of a word
struct Trie
{
    struct Trie *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

//struct definition for TrieManager which defines the function pointers are used to modify the trie structure
struct TrieManager
{
    //function pointer which points to the getNode function, which initializes a new trie node
    struct Trie *(*getNodePtr) ();
    //function pointer determines the index of a character in the alphabet
    void (*insertPtr) (struct Trie *, const char *, const struct TrieManager *);
    //function pointer determines the index of a character in the alphabet
    bool (*searchPtr) (struct Trie *, const char *, const struct TrieManager *);
    //function pointer which determines the index of a character in the alphabet
    int (*trieIndexFinderPtr) (const char *);
    //function pointer which frees all the dynamically allocated parent tries and child tries in the structure
    void (*freeTriePtr) (struct Trie *);
};

//calling MenuManager struct since it is used in some of the function pointers' definitions
struct MenuManager;

//struct defintion for ListManager which defines the function pointers that are used to modify the doubly linked list of students
struct ListManager
{
    //function pointer which adds a new node to the list of students
    struct Student *(*addPtr)(struct Student *, struct Student *);
    //function pointer which deletes a node from the existing list of students
    struct Student *(*deletePtr)(struct Student *, struct Student *);
    //function pointer which prints all the students in the linked list
    void (*printListPtr)(const struct Student *, const struct MenuManager *);
    //function pointer which deletes all the students in the linked list and frees them from memory
    struct Student *(*deleteAllPtr)(struct Student *);
    //function pointer whichs sorts the linked list of students based on how the user specifies to sort the students
    struct Student *(*sortPtr)(struct Student *, const struct ListManager *);
    //function pointer which implements the sorting logic and moves the pointers to point to different students
    struct Student *(*sortLogicPtr)(struct Student *, const int *, const struct ListManager *);
    //function pointer which swaps two nodes that are passed as the second and third arguments
    void (*swapPtr)(struct Student *, struct Student *, struct Student *);
    //function pointer which reverses the list of students
    struct Student *(*reversePtr)(struct Student *, const struct ListManager *);
};

//struct definition for MenuManager which defines
struct MenuManager
{
    //function pointer which prints the main menu to the screen
    void (*menuPtr)();
    //function pointer which helps to add a student to the linked list of students
    struct Student *(*addStudentPtr)(struct Student *, const struct ListManager *, struct Trie *, const struct TrieManager *);
    //function pointer which removes a students from the list
    struct Student *(*removeStudentPtr)(struct Student *, const struct ListManager *);
    //function pointer which modifies a student in the linked list
    void (*modifyStudentPtr)(struct Student *, const struct ListManager *, const struct MenuManager *, struct Trie *, const struct TrieManager *);
    //function pointer which prints the information of each student in the list to the screen
    void (*printStudentPtr)(const struct Student *);
    //function pointer which prints all the students in the linked list that have earned a minimum GPA that the user specifies
    void (*printMinGpaPtr)(const struct Student *, const struct MenuManager *);
    //function pointer which prints all the students in the linked list that have earned a minimum grade in COP 2510 that the user specifies
    void (*printMinGradePtr)(const struct Student *, const struct MenuManager *);
};

//function prototype for initializeTrieManager which initializes the function pointers for an instance of TrieManager that help manipulate a trie to accommodate more student Net IDs or even to change existing student Net IDs
void initializeTrieManager(struct TrieManager *);

//function prototype for getNode which creates a new trie and initializes its children to all be NULL and its boolean value to false
struct Trie *getNode();

//function prototype for insert which adds a new string to the existing trie structure
void insert(struct Trie *, const char *, const struct TrieManager *);

//function prototype for search which searches a trie structure and returns true if the second argument can be found in the trie; otherwise, the function returns false
bool search(struct Trie *, const char *, const struct TrieManager *);

//function prototype for trieIndexFinder which returns the index of the trie child node needed for the trie structure
int trieIndexFinder(const char *);

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
void modifyStudent(struct Student *, const struct ListManager *, const struct MenuManager *, struct Trie *, const struct TrieManager *);

//function prototype for addStudent which adds a student to the linked list and returns the new head of the linked list after adding the student
struct Student *addStudent(struct Student *, const struct ListManager *, struct Trie *, const struct TrieManager *);

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
struct Student *sortLogic(struct Student *, const int *, const struct ListManager *);

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

//function prototype for freeTrie which frees the dynamically allocated memory within the trie structure
void freeTrie(struct Trie *);

#endif
