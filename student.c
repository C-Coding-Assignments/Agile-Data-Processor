#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//function definition for initializeTrieManager which initializes the function pointers that are responsible for manipulating and searching through a declared trie structure
void initializeTrieManager(struct TrieManager *manager)
{
    manager->getNodePtr = getNode;
    manager->insertPtr = insert;
    manager->searchPtr = search;
    manager->trieIndexFinderPtr = trieIndexFinder;
    manager->freeTriePtr = freeTrie;
}

//function definition for getNode which initializes an instance of a trie structure underneath an existing root
struct Trie *getNode()
{
    //variable declaration and initialization using dynamic memory allocation
    struct Trie *root = malloc(sizeof(struct Trie));

    //selection statement which evaluates to true if memory allocation failed for the root node; if so, exit the program
    if (root == NULL)
    {
        printf("Memory allocation failed for new node.\n");
        exit(EXIT_FAILURE);
    }

    //for loop which iterates through the valid characters that can be found in a student's name and sets each of the children to point to NULL
    for (int i = 0; i < ALPHABET_SIZE; i++)
        root->children[i] = NULL;

    //initializing the isEndOfWord flag to false, indicating that the current node is not the end of a word in the trie
    root->isEndOfWord = false;

    return root;
}

//function definition for insert which adds a new string to the trie structure. The string that will be added to the trie is the string provided by the second argument
void insert(struct Trie *root, const char *string, const struct TrieManager *manager)
{
    //variable declarations and initialization
    struct Trie *parent = root;
    int index;

    //for loop which iterates through the characters in the string provided by the second argument and adds each character to the trie structure as a new node under the parent node
    for (const char *ptr = string; *ptr != '\0'; ptr++)
    {
        //calling the trieIndexFinder function to determine what integer index is associated with the *ptr
        index = manager->trieIndexFinderPtr(ptr);

        //selection statement which evaluates to true if the current character does not yet exist in the trie structure underneath its parent node
        if (parent->children[index] == NULL)
            //calling the getNode function to create a new node under the parent node since we are adding the string to the trie structure
            parent->children[index] = getNode();

        //updating the parent node to point to the newly created node
        parent = parent->children[index];
    }

    //marking the last node in the string as the end of a word in the trie structure by setting the isEndOfWord flag to true
    parent->isEndOfWord = true;
}

//function definition for search which searches the trie structure and returns a boolean value indicating whether the string passed in through the second parameter is initalized within the trie
bool search(struct Trie *root, const char *string, const struct TrieManager *manager)
{
    //variable declarations and initialization
    struct Trie *parent = root;
    int index;

    //for loop which iterates through the characters in the string and will return a false value the instant a character in the string is not found in the trie
    for (const char *ptr = string; *ptr != '\0'; ptr++)
    {
        //calling the trieIndexFinder function to determine what integer index is associated with *ptr
        index = manager->trieIndexFinderPtr(ptr);

        //selection statement which evaluates to true if the current character does not exist in the trie structure underneath its parent node; if so, the function will return a false boolean value
        if (parent->children[index] == NULL)
            return false;

        //updating the parent node to point to the child node at index
        parent = parent->children[index];    
    }  

    return (parent != NULL && parent->isEndOfWord);
}

//function definition for trieIndexFinder which is responsible for returning an integer value that represents the index for the character value passed to the function for the trie structure
int trieIndexFinder(const char *ptr)
{
    //selection statement which evaluates to true if the letter in the stirng that ptr points to is an upper-case letter; if so, index is initialized to *ptr - 'A'
    if (*ptr >= 'A' && *ptr <= 'Z')
        return *ptr - 'A';

    //selection statement which evaluates to true if the letter in the stirng that ptr points to is a lower-case letter; if so, index is initialized to *ptr - 'a' + 26
    else if (*ptr >= 'a' && *ptr <= 'z')
        return *ptr - 'a' + 26;    

    //selection statement which evaluates to true if the letter in the string that ptr points to is an apostrophe; if so, index is initialized to 52
    else if (*ptr == APOSTROPHE)
        return APOSTROPHE_INDEX;

    //selection statement which evaluates to true if the letter in the string that ptr points to is a period; if so, index is initialized to 53
    else if (*ptr == PERIOD)
        return PERIOD_INDEX;

    //selection statement which evaluates to true if the letter in the string that ptr points to is a hyphen; if so, index is initialized to 54
    else if (*ptr == HYPHEN)
        return HYPHEN_INDEX;

    return 0;      
}

//function definitition for menu which prints the main menu to the user
void menu()
{
    //printing the menu to the screen
    printf("=================================================\n");
    printf("|                 MENU OPTIONS                  |\n");
    printf("=================================================\n");
    printf("|  h  - Help: Display this menu.                |\n");
    printf("|  a  - Add: Add a student to the queue.        |\n");
    printf("|  p  - Pop: Remove a student from the queue.   |\n");
    printf("|  m  - Modify: Change student information.     |\n");
    printf("|  l  - List: List all students in the queue.   |\n");
    printf("|  s  - Sort: Sort all students in the queue.   |\n");
    printf("|  g  - GPA Search: Search for students with    |\n");
    printf("|       a minimum GPA.                          |\n");
    printf("|  c  - Grade Search: Search for students with  |\n");
    printf("|       a minimum grade in COP2510.             |\n");
    printf("|  q  - Quit: Exit the program.                 |\n");
    printf("=================================================\n");
}

//function definition for initializeManager which initializes its function pointer members
void initializeListManager(struct ListManager *listManager)
{
    listManager->addPtr = add;
    listManager->deletePtr = delete;
    listManager->printListPtr = printList;
    listManager->deleteAllPtr = deleteAll;
    listManager->sortPtr = sort;
    listManager->sortLogicPtr = sortLogic;
    listManager->swapPtr = swap;
    listManager->reversePtr = reverse;
}

//function definition for initializeMenuManager which initializes its function pointer members
void initializeMenuManager(struct MenuManager *menuManager)
{
    menuManager->menuPtr = menu;
    menuManager->addStudentPtr = addStudent;
    menuManager->removeStudentPtr = removeStudent;
    menuManager->modifyStudentPtr = modifyStudent;
    menuManager->printStudentPtr = printStudent;
    menuManager->printMinGpaPtr = printMinGpa;
    menuManager->printMinGradePtr = printMinGrade;
}

//function definition for addMenu which prints the menu for adding a new student to the queue
void addMenu()
{
    //printing the menu to the screen
    printf("\n--------------------------------------------------\n");
    printf("|         ADD A NEW STUDENT TO THE QUEUE        |\n");
    printf("--------------------------------------------------\n");
    printf("|  Please enter the student's information:      |\n");
    printf("|  Name:                                        |\n");
    printf("|  Net ID:                                      |\n");
    printf("|  COP 2510 Grade:                              |\n");
    printf("|  GPA:                                         |\n");
    printf("|  COP 2510 Attempts:                           |\n");
    printf("--------------------------------------------------\n");
    printf("|  Press any key to continue or 'q' to cancel.   |\n");
    printf("--------------------------------------------------\n");
}

//function defintion for removeNewline which removes the new-linecharacters found anywhere within the string and replaces it with the null-character
void removeNewline(char *string)
{   
    //for loop which iterates through the string until the first null-character is being pointed to by ptr
    for (char *ptr = string; *ptr != '\0'; ptr++)
        //selection statement which evaluates to true if *ptr is a new-linecharacter
        if (*ptr == '\n')
            *ptr = '\0';
}

//function defintion for addStudent which is responsible for adding a student to the queue
struct Student *addStudent(struct Student *head, const struct ListManager *manager, struct Trie *root, const struct TrieManager *trieManager)
{
    //variable declarations and initializations using dynamically allocated memory
    char name[MAX_LENGTH + 1], netID[MAX_LENGTH + 1], letter[MAX_LENGTH + 1], gpaStr[MAX_LENGTH + 1], attemptsStr[MAX_LENGTH + 1], temp[MAX_LENGTH + 1];
    double gpa;
    int attempts;
    struct Student *newStudent = malloc(sizeof(struct Student));

    //selection statement which evaluates to true if memory was successfully dynamically allocated
    if (newStudent == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    //calling addMenu to display the add student menu to the user
    addMenu();

    //getting the user's menu selection and removing the new-line character found at the end of the input
    fgets(temp, MAX_LENGTH + 1, stdin);
    removeNewline(temp);

    //selection statement which evaluates to true if the user entered the single character q, signaling that it would like to terminate the process of adding a student to the queue
    if (!strcmp((temp), "q"))
        return head;         

    //calling the getName function to get the name of the new student
    getName(name);
    //calling the getNetID function to get the net ID of the new student
    getNetID(netID);

    //do-while loop which iterates until the user has entered all the information for creating a new student
    do
    {
        //calling the getGrade function to get the COP 2510 grade of the new student
        getGrade(letter);
        //calling the getGpa function to get the GPA of the new student
        gpa = getGpa(gpaStr);
        //calling the getAttempts function to get the number of attempts the new student has made in COP 2510
        attempts = getAttempts(attemptsStr);
    } while (attempts < 0);
    
    //assigning the values obtained from the user to the new student
    strcpy(newStudent->name, name);
    strcpy(newStudent->netID, netID);
    newStudent->copGrade = *letter;
    newStudent->gpa = gpa;
    newStudent->attempts = attempts;
    newStudent->next = NULL;
    newStudent->previous = NULL;
    
    trieManager->insertPtr(root, newStudent->netID, trieManager);

    //ternary expression where if head is not NULL, add the new student to the linked list; otherwise, the head of the linked list is the newly created student
    return (head != NULL) ? (manager->addPtr(head, newStudent)) : (newStudent);
}

//function definition for getName which gets the new student's name from the user and removes the new-linecharacters within the input
void getName(char *name)
{
    //do-while loop which iterates until the user enters a string, representing the new student's, that is longer than zero characters
    do
    {
        //getting the new student's name
        printf("Enter the name of the student: ");
        fgets(name, MAX_LENGTH + 1, stdin);
        //calling the removeNewline function to remove the new-line characters
        removeNewline(name);

        //selection statement which evaluates to true if the string's length is zero characters long; if so, the program will output an error message
        if (!strlen(name))
            printf("Student's name must be at least one character.\n");
    } while (strlen(name) < 1);
}

//function definition for getNetID which gets the new student's net ID from the user and removes the new-line characters within the input
void getNetID(char *netID)
{
    //do-while loop which iterates until the user enters a string, representing the new student's net ID, that is longer than zero characters
    do
    {
        //getting the new student's net ID
        printf("Enter the Net ID of the student: ");
        fgets(netID, MAX_LENGTH + 1, stdin);
        //calling the removeNewline function to remove the new-line characters
        removeNewline(netID);

        //selection statement which evaluates to true if the string's length is zero characters long; if so, the program will output an error message
        if (!strlen(netID))
            printf("Student's Net ID must be at least one character.\n");
    } while (strlen(netID) < 1);
}

//function definition for getGrade which gets the new student's COP 2510 grade from the user and removes the new-line characters within the input
void getGrade(char *letter)
{
    //variable declaration
    bool flag;

    //do-while loop which iterates until the user enters a valid letter grade (A-F)
    do
    {
        //getting the new student's COP 2510 grade
        printf("Enter the student's COP 2510 letter grade: ");
        fgets(letter, MAX_LENGTH + 1, stdin);
        //calling the removeNewline function to remove the new-line characters
        removeNewline(letter);

        //ternary expression which if evaluated to true assigns the value true to flag; otherwise, flag is false
        flag = (!strcmp(letter, "A") || !strcmp(letter, "a") || 
        !strcmp(letter, "B") || !strcmp(letter, "b") || 
        !strcmp(letter, "C") || !strcmp(letter, "c") || 
        !strcmp(letter, "D") || !strcmp(letter, "d") || 
        !strcmp(letter, "F") || !strcmp(letter, "f")) ? true : false;
            
        //selection statement which evaluates to true if flag is false; if so, an error message is printed to the user    
        if (!flag)
            printf("Invalid letter grade. Please enter a valid grade (A-F).\n");
    } while (!flag);
}

//function definition for getGpa which gets the new student's gpa from the user and removes the new-line characters within the input
double getGpa(char *gpaStr)
{
    //variable declarations and initialization
    bool flag;
    double gpa;
    int dotCounter = 0;

    //do-while loop which iterates until the user enters a valid GPA (0-4.0) and removes the new-line characters within the input
    do
    {
        flag = true;
        dotCounter = 0;

        //do-while loop which iterates until the user enters a valid string input
        do
        {
            //getting the new student's GPA
            printf("Enter the student's GPA: ");
            fgets(gpaStr, MAX_LENGTH + 1, stdin);
            //calling the removeNewline function to remove the new-line characters
            removeNewline(gpaStr);

            //selection statement which evaluates to true if the string's length is zero characters long; if so, an error message is printed to the user
            if (!strlen(gpaStr))
                printf("Student's GPA must be at least one character.\n");
        } while (strlen(gpaStr) < 1);

        //for loop which checks if there are any non-double digits in the string
        for (char *ptr = gpaStr; *ptr != '\0'; ptr++)
        {
            //selection statement which evaluates to true if a non-double digit is detected in the string; if so, set flag to false so the user can be prompted to enter in a new string
            if (!(*ptr >= '0' && *ptr <= '9') && *ptr != '.')
                flag = false;

            //selection statement which evaluates to true if a dot is detected for the first time in the stirng; if so, increment the dot counter to count the number of dots the user has entered
            else if (*ptr == '.' && dotCounter == 0)
                dotCounter++;

            //selection statement which evaluates to true if a second dat is detected in the user's input; if so, set flag to false so the user can be prompted to enter in a new string
            else if (*ptr == '.' && dotCounter == 1)
                flag = false;
        }        

        //selection statement which evaluates to true if flag is false; if so, print an error message and bring the control to the end of the loop so the loop can iterate again
        if (!flag)
        {
            printf("Invalid GPA. Please enter a valid GPA (0-4.0).\n");
            continue;
        }        
        
        //converting the string to a double value
        gpa = atof(gpaStr);

        //ternary expression which evaluates to false if the GPA is outside the valid range (0-4.0); if so, set flag to false so the user can be prompted to enter in a new string; otherwise, set flag to true
        flag = (gpa < 0 || gpa > 4.0) ? false : true;

        //selection statement which evaluates to true if flag is true; if so, an error message is printed to the user; otherwise, the control exits the loop
        if (!flag)
            printf("Invalid GPA. Please enter a valid GPA (0-4.0).\n");
    } while (!flag);

    return gpa;
}

//function definition for getAttempts which gets the new student's COP 2510 attempts from the user and removes the new-line characters within the input
int getAttempts(char *attemptsStr)
{
    //variable declarations
    bool flag;
    int attempts;
    
    //do-while loop which iterates until the user enters a valid positive integer for the number of previous attempts in COP 2510 and removes the new-line characters within the input
    do
    {
        //do-while loop which iterates until the user enters a valid string input and checks if it contains only digits
        do
        {
            //getting the new student's number of previous attempts in COP 2510
            printf("Enter the student's number of previous attempts in COP 2510: ");
            fgets(attemptsStr, MAX_LENGTH + 1, stdin);
            //calling the removeNewline function to remove the new-line characters
            removeNewline(attemptsStr);

            //selection statement which evaluates to true if the string's length is zero characters long; if so, an error message is printed to the user
            if (!strlen(attemptsStr))
                printf("Student's number of COP 2510 attempts must be at least one character.\n");
        } while (strlen(attemptsStr) < 1);
        
        //for loop which iterates through the user's input string using a char pointer until *ptr reaches the first null-character
        for (char *ptr = attemptsStr; *ptr != '\0'; ptr++)
            //ternary expression which evaluates to true if any character in the string is not a digit; if so, flag is false; otherwise, flag is assigned to true
            flag = (*ptr < '0' || *ptr > '9') ? false : true;
        
        //selection statement which evaluates to true if flag is false; if so, print an error message to the user and have the do-while loop continue to iterate
        if (!flag)
        {
            printf("Invalid number of previous attempts. Please enter a valid positive integer.\n");
            continue;
        }

        //converting the string to an integer value and checking if it is a positive integer since flag is true here
        attempts = atoi(attemptsStr);
        //ternary expression which assigns false to flag if attempts is less than zero; otherwise, flag is assigned the value true
        flag = (attempts < 0) ? false : true;
        
        //ternary expression which evaluates to true if flag is false; if so, print an error message to the user and have the do-while loop continue to
        if (!flag)
            printf("Invalid number of previous attempts. Please enter a valid positive integer.\n");
    } while (!flag);

    return attempts;
}

//function definition for add which is responsible for appending a new student to the end of a doubly linked list
struct Student *add(struct Student *head, struct Student *newStudent)
{
    //variable declarations and initialization
    struct Student *ptr = head, *prev = NULL;

    //selection statement which evaluates to true if head is NULL; if so, the new instance of Student is now the head of the linked list
    if (head == NULL)
        return newStudent;

    //for loop which iterates through the linked list and breaks at the last item in the linked list. This means that ptr points to the last item in the list
    for (; ptr->next != NULL; prev = ptr, ptr = ptr->next);

    //assigning the new student to the next pointer of the last item in the list
    ptr->next = newStudent;
    //assigning the previous pointer as the previous item in the list to the new student
    ptr->previous = prev;

    return head;
}

//function definition for removeStudent which is responsible for removing a specified student from the linked list
struct Student *removeStudent(struct Student *head, const struct ListManager *manager)
{
    //variable declarations and initialization
    struct Student *ptr = head;
    char netID[MAX_LENGTH + 1];

    //selection statement which evaluates to true if the linked list is empty; if so, print an error message and return NULL to main
    if (head == NULL)
    {
        printf("\nYou have not entered any students yet into the queue.\n");
        return NULL;
    }   

    //getting the Net ID of the student to be removed from the user and removing the new-line characters within the input
    printf("What is the Net ID of the student would you like to remove?: ");
    fgets(netID, MAX_LENGTH + 1, stdin);
    //calling removeNewline function to remove the new-line characters
    removeNewline(netID);
    
    //for loop which iterates through the linked list
    for (; ptr != NULL; ptr = ptr->next)
        //selection statement which evaluates to true if the net ID of the student that ptr points is the same as the net ID that the user entered
        if (!strcmp(netID, ptr->netID))
            //calling the deletePtr function to remove the student in the linked list with with the net ID that the user entered
            head = manager->deletePtr(head, ptr); 

    return head;
}

//function definition for modifyStudent which provides the functionality for modifying the students' members within the linked list
void modifyStudent(struct Student *head, const struct ListManager *listManager, const struct MenuManager *menuManager, struct Trie *root, const struct TrieManager *trieManager)
{
    //variable declarations and initializations
    char netID[MAX_LENGTH + 1], input[MAX_LENGTH + 1], output[MAX_LENGTH + 1];
    struct Student *ptr = head;
    int selection, attempts;
    double gpa;
    bool found = false;

    //selection statement which evaluates to true if head is equal to NULL; if so, print an error message to the user
    if (head == NULL)
    {
        printf("\nYou have not entered any students yet into the queue.\n\n");
        return;
    }

    //do-while loop which iterates until the user enters a string that is valid
    do
    {
        //getting user input for the net ID of the student that the user would like to have modified
        printf("What is the Net ID of the student would you like to modify?: ");
        fgets(netID, MAX_LENGTH + 1, stdin);
        //calling the removeNewline function to remove the new-line character from the user's input
        removeNewline(netID);

        //selection statement which evaluates to true if the string's length is zero characters long; if so, an error message is printed to the user
        if (!strlen(netID))
            printf("Student's Net ID must be at least one character.\n");

        //selection statement which evaluates to true if the string's length is greater than zero characters
        else
        {
            //selection statement which evaluates to true 
            if (trieManager->searchPtr(root, netID, trieManager))
            {
                //for loop which iterates over the students in the list and breaks once a student with the same Net ID as netID is encountered
                for (; ptr != NULL; ptr = ptr->next)
                    //selection statement which evaluates to true if the current student's net ID matches the entered Net ID; if so, break from the nested for loop
                    if (!strcmp(netID, ptr->netID))
                        break;

                break;        
            }    

            //print error message and asking the user if it would like a complete list of students in the queue
            printf("A student with the Net ID %s does not exist. If you are unsure of the student's Net ID that you are looking for, type List to display all the students within the queue.\n", netID);
            fgets(input, MAX_LENGTH + 1, stdin);
            //calling removeNewline function to remove the new-line characters from the user's input
            removeNewline(input);

            //selection statement which evaluates to true if the user wants a complete list of students in the queue; if so, call the printListPtr function to display the list
            if (!strcmp(input, "List"))
                listManager->printListPtr(head, menuManager);
        }   
    } while (!trieManager->searchPtr(root, netID, trieManager));

    //do-while loop which iterates until the user enters a valid menu option
    do
    {
        //printing the student information modification menu to the user
        printf("\n===============================================\n");
        printf("        Student Information Modification\n");
        printf("===============================================\n");
        printf("Please select the information you want to modify:\n");
        printf("------------------------------------------------\n");
        printf(" 1. Modify Name\n");
        printf(" 2. Modify Attempts\n");
        printf(" 3. Modify GPA\n");
        printf(" 4. Modify Grade\n");
        printf(" 5. Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter your choice [1-5]: ");

        //getting user input for the menu option and converting it to an integer
        fgets(input, MAX_LENGTH + 1, stdin);
        selection = atoi(input);

        //switch statement which checks what the user entered and provides the functionality for running the menu option that the user entered
        switch (selection)
        {
            //case 1 to modify the name of the student
            case 1:
                //calling the getName function to get the modified name of the student and modifying the name of the student in the linked list
                getName(output);
                strcpy(ptr->name, output);
                break;

            //case 2 to modify the number of attempts of the student
            case 2:
                //calling the getAttempts function to get the modified COP 2510 attempts and modifying the COP 2510 attempts of the student in the linked list
                ptr->attempts = getAttempts(output);
                break;

            //case 3 to modify the grade point average (GPA) of the student
            case 3:
                //calling the getGpa function to get the modified GPA and modifying the GPA of the student in the linked list
                ptr->gpa = getGpa(output);
                break;

            //case 4 to modify the COP 2510 course grade of the student
            case 4:
                //calling the getGrade function to get the modified grade and modifying the grade of the student in the linked list
                getGrade(output);
                ptr->copGrade = *output;
                break;
        }
    } while (selection != 5);

    //printing a success message to the user and asking if the user would like to sort the students with the updated information
    printf("\n%s's information has been successfully modified!\n\n", ptr->name);
    printf("Now that %s's information has been altered, would you like to sort the students with the updated information?\n", ptr->name);
    
    //do-while loop which iterates until the user enters a valid yes or no input
    do
    {
        //getting user input for sorting the students with the updated information
        printf("Selection (Y or N): ");
        fgets(input, MAX_LENGTH + 1, stdin);
        //calling the removeNewline function to remove the new-line characters from the user's input
        removeNewline(input);

        //selection statement which evaluates to true if the user entered either "Y" or "y" to sort the students with the updated information; if so, call the sortPtr function to sort the students in the linked list
        if (!strcmp(input, "Y") || !strcmp(input, "y")) 
            //calling the sortPtr function to sort the students
            head = listManager->sortPtr(head, listManager);

        //selection statement which evaluates to true if the user entered either "N" or "n" to not sort the students with the updated information; if so, call the
        else if (!strcmp(input, "N") || !strcmp(input, "n"))
            break;    
    } while (strcmp(input, "Y") != 0 && strcmp(input, "y") != 0 && strcmp(input, "N") != 0 && strcmp(input, "n") != 0);
}

//function defintion for printList which is responsible for printing all the students within the linked list
void printList(const struct Student *head, const struct MenuManager *manager)
{
    //variable declaration and initialization
    int nodes = 1;

    //selection statement which evaluates to true if the head of the linked list is equal to NULL; if so, print an error message to the user
    if (head == NULL)
    {
        //printing error message to the user
        printf("\n--------------------------------------------------\n");
        printf("|           NO STUDENTS IN THE LIST              |\n");
        printf("--------------------------------------------------\n");

        return;
    }

    //for loop which iterates through the entire linked list
    for (const struct Student *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("\n                   STUDENT #%d", nodes++);
        //calling the printStudentPtr function to print the student information that ptr points to
        manager->printStudentPtr(ptr);
    }
}

//function definition for printStudent which is responsible for printing the student information to the user
void printStudent(const struct Student *ptr)
{
    //printing the student information to the user in a tabular format with appropriate spacing and alignment
    printf("\n--------------------------------------------------\n");
    printf("|              STUDENT INFORMATION               |\n");
    printf("--------------------------------------------------\n");
    printf("|  Name: %-39s |\n", ptr->name);
    printf("|  Net ID: %-37s |\n", ptr->netID);
    printf("|  COP 2510 Grade: %-29c |\n", toupper(ptr->copGrade));
    printf("|  GPA: %-40.2f |\n", ptr->gpa);
    printf("|  COP 2510 Attempts: %-26d |\n", ptr->attempts);
    printf("--------------------------------------------------\n");
}

//function definition for printMinGpa which prints the students within the linked list who have a greater or equal gpa than what the user requested
void printMinGpa(const struct Student *head, const struct MenuManager *manager)
{
    //variable declarations and initialization
    char temp[MAX_LENGTH + 1];
    int minGpa, nodes = 1;
    bool flag;

    //selection statement which evaluates to true if head is equal to NULL; if so, print an error message and exit the function
    if (head == NULL)
    {
        //calling printStudentPtr function to print an error message and exit the function
        manager->printStudentPtr(head);
        return;
    }

    //do-while loop which iterates until the user enters a valid minimum GPA for printing to the screen
    do
    {
        //getting user input for the minimum GPA for printing to the screen
        printf("What is the minimum GPA of the students you would like to have printed to the screen?: \n");
        fgets(temp, MAX_LENGTH + 1, stdin);
        //converting user's input into an integer
        minGpa = atoi(temp);

        //ternary expression which assigns the value true to flag if the gpa the user entered is invalid; otherwise, the value false is assigned to flag
        flag = (minGpa < 0 || minGpa > 4.0) ? true : false;

        //ternary expression which if evaluated to true, print an error message; otherwise, exit from the loop
        (flag) ? (printf("Invalid GPA. Please enter a valid GPA (0-4.0).\n")) : (1);;
    } while (flag);

    //for loop which iterates through the entire linked list
    for (const struct Student *ptr = head; ptr != NULL; ptr = ptr->next)
        //selection statement which evaluates to true if the student's gpa that pointer points to is greater than or equal to the minimum gpa that the user entered
        if (ptr->gpa >= minGpa)
        {
            printf("\n                   STUDENT #%d", nodes++);
            //calling printStudentPtr function which is responsible for printing the students in the linked list with the minimum gpa
            manager->printStudentPtr(ptr);
        }    
}

//function definition for printMinGrade which prints the students who have earned a grade greater than or equal to the minium COP 2510 grade that the user entered
void printMinGrade(const struct Student *head, const struct MenuManager *manager)
{
    //variable declarations and initialization
    char temp[MAX_LENGTH + 1];
    int nodes = 1;
    bool flag;

    //selection statement which evaluates to true if head is equal to NULL; if so, print an error message and exit the function
    if (head == NULL)
    {
        //function definition for printStudentPtr which prints the error message if there are no students in the queue
        manager->printStudentPtr(head);
        return;
    }

    //do-while loop which iterates until the user enters a valid minimum grade for printing to the screen
    do
    {
        //getting user input for the minimum grade for printing to the screen
        printf("What is the minimum COP 2510 letter grade of the students you would like to have printed to the screen?: \n");
        fgets(temp, MAX_LENGTH + 1, stdin);
        //calling the removeNewline function to remove the new-line characters from the input
        removeNewline(temp);

        //ternary expression which assigns the value false to flag if the grade the user entered is invalid; otherwise, the value true is assigned to flag
        flag = (!strcmp(temp, "A") || !strcmp(temp, "a") || 
        !strcmp(temp, "B") || !strcmp(temp, "b") || 
        !strcmp(temp, "C") || !strcmp(temp, "c") || 
        !strcmp(temp, "D") || !strcmp(temp, "d") || 
        !strcmp(temp, "F") || !strcmp(temp, "f")) ? true : false;
    } while (flag);

    //for loop which iterates through the linked list
    for (const struct Student *ptr = head; ptr != NULL; ptr = ptr->next)
        //selection statement which evaluates to true if the COP 2510 grade of the student that the pointer points to is greater than or equal to
        if (ptr->copGrade >= *temp)
        {
            //printing students with high enough COP 2510 grade
            printf("\n                   STUDENT #%d", nodes++);
            //calling the printStudentPtr function which is responsible for printing the students in the linked list with the minimum grade
            manager->printStudentPtr(ptr);
        }
}

//function definition for sortMenu which prints to student sorting menu to the user
void sortMenu()
{
    //printing the menu
    printf("\n=================================================\n");
    printf("|           STUDENT SORTING MENU                |\n");
    printf("=================================================\n");
    printf("|  1 - Sort by Name (A-Z)                       |\n");
    printf("|  2 - Sort by GPA (Lowest to Highest)          |\n");
    printf("|  3 - Sort by GPA (Highest to Lowest)          |\n");
    printf("|  4 - Sort by Attempts (Fewest to Most)        |\n");
    printf("|  5 - Sort by Attempts (Most to Fewest)        |\n");
    printf("|  6 - Reverse the Current List                 |\n");
    printf("|  7 - Exit Sorting Menu                        |\n");
    printf("=================================================\n");
    printf("Enter menu selection: ");
}

//function definition for sort which sorts the linked list of students by a variety of criteria
struct Student *sort(struct Student *head, const struct ListManager *manager)
{
    //variable declarations and initialization
    char temp[MAX_LENGTH + 1];
    int selection;

    //selection statement which evaluates to true if head is equal to NULL; if so, print an error message and exit the function
    if (head == NULL)
    {
        printf("There are no students in the list to sort.\n");
        return head;
    }

    //do-while loop which iterates until the user enters a valid menu option
    do
    {
        //calling sortMenu function to print the sorting menu to the user
        sortMenu();  

        //getting menu option from the user and converting the user's input into an integer
        fgets(temp, MAX_LENGTH + 1, stdin);
        selection = atoi(temp);
    } while (selection > 7 || selection < 1);

    //selection statement which evaluates to true if selection does not equal 7; if so, sort the students according to the user's selection
    if (selection < 6)
        //calling the sortLogicPtr function to sort doubly linked list
        manager->sortLogicPtr(head, &selection, manager); 
    
    //switch statement which determines the sorting criteria based on the user's menu selection
    switch (selection)
    {
        case 1: printf("Students sorted by name lexicographically (ascending)!\n"); break;
        case 2: printf("Students sorted by GPA (lowest to highest)!\n"); break;
        case 3: printf("Students sorted by GPA (highest to lowest)!\n"); break;
        case 4: printf("Students sorted by attempts (fewest to most)!\n"); break;
        case 5: printf("Students sorted by attempts (most to fewest)!\n"); break;
        case 6: head = manager->reversePtr(head, manager); printf("List reversed!\n"); break;
        case 7: break;
    }

    return head;
}

//function definition for sortLogic which provides the functionality for how to sort the doubly linked list of students
struct Student *sortLogic(struct Student *head, const int *logic, const struct ListManager *manager)
{
    //variable declarations and initialization
    bool swap = false;
    struct Student *ptr, *ptr2;
    char lowerCasePtr[MAX_LENGTH + 1], lowerCasePtr2[MAX_LENGTH + 1];

    //outer for loop which iterates over the linked list and sorts the students
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        //selection statement which evaluates to true if a swapped just occurred; if so, make ptr point to the beginning of the list so the sorting of the linked list can continue from the beginning
        if (swap)
            ptr = head;

        //inner for loop which iterates over the linked list and sorts the students
        for (ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            //switch statement which determines the sorting criteria based on the logic pointer's value
            switch (*logic)
            {
                case 1: 
                    //copying the contents of the students' name that ptr and ptr2 point to into temporary strings
                    strcpy(lowerCasePtr, ptr->name);
                    strcpy(lowerCasePtr2, ptr2->name);

                    //for loop which converts each character in the name that ptr points to into a lower-case character and stores this string in a temporary string variable
                    for (char *ptrChar = lowerCasePtr; *ptrChar != '\0'; *ptrChar = tolower(*ptrChar), ptrChar++);
                    //for loop which converts each character in the name that ptr2 points to into a lower-case character and stores this stirng in a temporary string variable
                    for (char *ptrChar2 = lowerCasePtr2; *ptrChar2!= '\0'; *ptrChar2 = tolower(*ptrChar2), ptrChar2++);

                    swap = (strcmp(lowerCasePtr, lowerCasePtr2) > 0);
                    break;

                case 2: swap = (ptr->gpa > ptr2->gpa); break;
                case 3: swap = (ptr->gpa < ptr2->gpa); break;
                case 4: swap = (ptr->attempts > ptr2->attempts); break;
                case 5: swap = (ptr->attempts < ptr2->attempts); break;          
            }

            //selection statement which evaluates to true if swap is true, meaning that the students ptr and ptr2 point to should be swapped
            if (swap)
            {
                //calling the swapPtr function to swap the nodes within the doubly linked list of the students
                manager->swapPtr(head, ptr, ptr2);

                //updating the head pointer if the swapped node is the head
                ptr = head;

                break;
            }
        }
    }    

    return head;    
}

//function definition for swap which is responsible for swapping the data of the nodes within the doubly linked list of the students
void swap(struct Student *head, struct Student *ptr, struct Student *ptr2)
{
    //variable declarations
    char tempName[MAX_LENGTH + 1], tempNetid[MAX_LENGTH + 1], tempCop2510_grade;
    double tempGPA;
    int tempAttempts;

    //swapping the data in the nodes
    strcpy(tempName, ptr->name);
    strcpy(tempNetid, ptr->netID);
    tempCop2510_grade = ptr->copGrade;
    tempGPA = ptr->gpa;
    tempAttempts = ptr->attempts;

    //swapping the data in the nodes
    strcpy(ptr->name, ptr2->name);
    strcpy(ptr->netID, ptr2->netID);
    ptr->copGrade = ptr2->copGrade;
    ptr->gpa = ptr2->gpa;
    ptr->attempts = ptr2->attempts;
        
    //swapping the data in the nodes
    strcpy(ptr2->name, tempName);
    strcpy(ptr2->netID, tempNetid);
    ptr2->copGrade = tempCop2510_grade;
    ptr2->gpa = tempGPA;
    ptr2->attempts = tempAttempts;
}

//function definition for reverse which reverses the doubly linked list of students
struct Student *reverse(struct Student *head, const struct ListManager *manager)
{
    //variable declarations and initializations
    struct Student *ptr = head, *ptr2 = head;
    int nodes = 0, i = 0;

    //for loop which iterates and counts all the nodes in the doubly linked list
    for (struct Student *ptr = head; ptr != NULL; ptr = ptr->next, nodes++);

    //variable declaration
    struct Student allNodes[nodes];

    //for loop which copies all the nodes from the doubly linked list to an array
    for (struct Student *ptr = head; ptr != NULL; ptr = ptr->next)
        allNodes[i++] = *ptr;

    //for loop which reverses the doubly linked list of students by swapping the nodes with the nodes in the array
    for (struct Student *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        //swapping the data in the nodes
        strcpy(ptr->name, allNodes[--i].name);
        strcpy(ptr->netID, allNodes[i].netID);
        ptr->copGrade = allNodes[i].copGrade;
        ptr->gpa = allNodes[i].gpa;
        ptr->attempts = allNodes[i].attempts;
    }

    return head;  
}

//function definition for delete which deletes a node from the list
struct Student *delete(struct Student *head, struct Student *remove)
{
    //variable declarations and initializations
    struct Student *cur = head, *prev = NULL;
    char name[MAX_LENGTH + 1];
    strcpy(name, remove->name);

    //for loop which iterates over the list of students and terminates if cur is equal to the student that the user has requested to remove from the queue
    for (; cur != NULL; prev = cur, cur = cur->next)
        //selection statement which evaluates to true if the student that cur points to is the student that the user has requested to remove
        if (cur == remove)
            break;

    //selection statement which evaluates to true if cur is equal to the head of the list; if so, head is updated to the next node in the list and the node is freed
    if (cur == head)
    {
        //make the head of the list point to the second student within the list
        head = head->next;
        
        //freeing the student that remove points to
        free(remove);

        //printing that this student has been successfully removed
        printf("%s has been removed successfully!\n\n", name);

        return head;
    }

    //selection statement which evaluates to true if cur is equal to NULL; if so, print an error message and return to main
    else if (cur == NULL)
    {
        printf("\nThe student you are trying to remove does not exist in the queue.\n\n");
        return head;
    }
    
    //make the student one before the student that cur points to point to the student one after the student that cur points to
    prev->next = cur->next;

    //freeing the student that cur points to
    free(cur);

    //printing that this student has been successfully removed
    printf("%s has been removed successfully!\n", name);

    return head;
}

//function definition for deleteAll which deletes all the nodes within the doubly linked list once ther program is almost finished
struct Student *deleteAll(struct Student *head)
{
    //variable declaration
    struct Student *temp;

    //while loop which iterates until the head is not equal to NULL
    while (head != NULL)
    {
        //assigning the next node to a temporary variable and freeing the current node
        temp = head->next;
        free(head);
        head = temp;
    }
    
    return NULL;
}

//function definition for writeStudents which writes the finished queue of students to a file once the program is almost finished
void writeStudents(FILE *fptr, const struct Student *head)
{
    //variable declaration and initialization
    int nodes = 1;

    //selection statement which evaluates to true if the head of the doubly linked list is NULL; if so, write to the file that there are no students in the queue
    if (head == NULL)
    {
        //printing that there are no students in the queue to the file
        fprintf(fptr, "\n--------------------------------------------------\n");
        fprintf(fptr, "|           NO STUDENTS IN THE LIST              |\n");
        fprintf(fptr, "--------------------------------------------------\n");

        return;
    }

    //for loop which iterates over the entire linked list of students
    for (const struct Student *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        //printing the students' information to the file
        fprintf(fptr, "                   STUDENT #%d", nodes++);
        fprintf(fptr, "\n--------------------------------------------------\n");
        fprintf(fptr, "|              STUDENT INFORMATION               |\n");
        fprintf(fptr, "--------------------------------------------------\n");
        fprintf(fptr, "|  Name: %-39s |\n", ptr->name);
        fprintf(fptr, "|  Net ID: %-37s |\n", ptr->netID);
        fprintf(fptr, "|  COP 2510 Grade: %-29c |\n", toupper(ptr->copGrade));
        fprintf(fptr, "|  GPA: %-40.2f |\n", ptr->gpa);
        fprintf(fptr, "|  COP 2510 Attempts: %-26d |\n", ptr->attempts);
        fprintf(fptr, "--------------------------------------------------\n");
    }
}

//function definition for freeTrie which frees the dynamically allocated memory used for the creation of the trie structure
void freeTrie(struct Trie *trie)
{
    //selection statement which evaluates to true if the root of the trie structure is NULL; if so, simply return back to main
    if (trie == NULL)
        return;

    //for loop which iterates over all the children nodes of the current node and recursively frees the dynamically allocated memory for each child node
    for (int i = 0; i < ALPHABET_SIZE; i++)
        //selection statement which evaluates to true if the children nodes of the current node does not equal NULL; if so, recursively call the function to navigate to an inner node within the trie
        if (trie->children[i] != NULL)  
            //calling freeTrie function to free the trie structure
            freeTrie(trie->children[i]);

    //freeing the dynamically allocated memory for the current node
    free(trie);        
}
