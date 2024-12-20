#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//function pointer that points to the addMenu function that is responsible for printing the add student menu
void (*addMenuPtr) () = addMenu;
//function pointer that points to the sortMenuPtr function that is responsible for printing the sorting menu
void (*sortMenuPtr) () = sortMenu;

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
struct Student *addStudent(struct Student *head, const struct ListManager *manager)
{
    //variable declarations and initializations using dynamically allocated memory
    char name[MAX_LENGTH + 1], netID[MAX_LENGTH + 1], letter[MAX_LENGTH + 1], gpaStr[MAX_LENGTH + 1], attemptsStr[MAX_LENGTH + 1], temp[MAX_LENGTH + 1];
    double gpa;
    int attempts = -1;
    struct Student *newStudent = malloc(sizeof(struct Student));

    //selection statement which evaluates to true if memory was successfully dynamically allocated
    if (newStudent == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    //calling addMenuPtr to display the add student menu to the user
    addMenuPtr();

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
    //variable declarations
    bool flag;
    double gpa;

    //do-while loop which iterates until the user enters a valid GPA (0-4.0) and removes the new-line characters within the input
    do
    {
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
        
        //converting the string to a double value and checking if it is within the valid range (0-4.0)
        gpa = atof(gpaStr);
        flag = (gpa < 0 || gpa > 4.0) ? true : false;

        //ternary expression which evaluates to true if flag is true; if so, an error message is printed to the user; otherwise, the control exits the loop
        (flag) ? (printf("Invalid GPA. Please enter a valid GPA (0-4.0).\n")) : (1);;
    } while (flag);

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
        //assigning the flag to the value true for each iteration of the outer do-while loop
        flag = true;

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
            //selection statement which evaluates to true if *ptr is not a digit; if so, flag is now false and the loop continues
            if (*ptr < '0' || *ptr > '9')    
                flag = false;

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
        (!flag) ? (printf("Invalid number of previous attempts. Please enter a valid positive integer.\n")) : (1);;
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
void modifyStudent(struct Student *head, const struct ListManager *listManager, const struct MenuManager *menuManager)
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
            //for loop which iterates through the linked list to find the student with the entered Net ID
            for (; ptr != NULL; ptr = ptr->next)
                //selection statement which evaluates to true if the student with the entered Net ID was found in the linked list; if so, break from the loop
                if (!strcmp(netID, ptr->netID))
                {
                    found = true;
                    break;
                }    

            //selection statement which evaluates to true if the student with the entered Net ID was not found in the linked list; if so, print an error message to the user and ask for a valid Net ID
            if (!found)
            {
                //print error message and asking the user if it would like a complete list of students in the queue
                printf("A student with the Net ID %s does not exist. If you are unsure of the student's Net ID that you are looking for, type List to display all the students within the queue.\n", netID);
                fgets(input, MAX_LENGTH + 1, stdin);
                //calling removeNewline function to remove the new-line characters from the user's input
                removeNewline(input);

                //selection statement which evaluates to true if the user wants a complete list of students in the queue; if so, call the printListPtr function to display the list
                if (!strcmp(input, "List"))
                    listManager->printListPtr(head, menuManager);
            }

            //selection statement which evaluates to true if the student with the entered Net ID was found in the linked list; if so, break from the do-while loop
            else
                break;  
        }    
    } while (strlen(netID) < 1);

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
        printf(" 2. Modify Net ID\n");
        printf(" 3. Modify Attempts\n");
        printf(" 4. Modify GPA\n");
        printf(" 5. Modify Grade\n");
        printf(" 6. Exit\n");
        printf("------------------------------------------------\n");
        printf("Enter your choice [1-6]: ");

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

            //case 2 to modify the Net ID of the student
            case 2:
                //calling the getNetID function to get the modified Net ID of the student and modifying the Net ID of the student in the linked list
                getNetID(output);
                strcpy(ptr->netID, output);
                break;

            //case 3 to modify the number of attempts of the student
            case 3:
                //calling the getAttempts function to get the modified COP 2510 attempts and modifying the COP 2510 attempts of the student in the linked list
                ptr->attempts = getAttempts(output);
                break;

            //case 4 to modify the grade point average (GPA) of the student
            case 4:
                //calling the getGpa function to get the modified GPA and modifying the GPA of the student in the linked list
                ptr->gpa = getGpa(output);
                break;

            //case 5 to modify the COP 2510 course grade of the student
            case 5:
                //calling the getGrade function to get the modified grade and modifying the grade of the student in the linked list
                getGrade(output);
                ptr->copGrade = *output;
                break;
        }
    } while (selection != 6);

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
    int selection, boolean;
    struct Student *ptr = head, *ptr2;

    //selection statement which evaluates to true if head is equal to NULL; if so, print an error message and exit the function
    if (head == NULL)
    {
        printf("There are no students in the list to sort.\n");
        return head;
    }

    //do-while loop which iterates until the user enters a valid menu option
    do
    {
        //calling sortMenuPtr function to print the sorting menu to the user
        sortMenuPtr();  

        //getting menu option from the user and converting the user's input into an integer
        fgets(temp, MAX_LENGTH + 1, stdin);
        selection = atoi(temp);
    } while (selection > 7 || selection < 1);
    
    //switch statement which determines the sorting criteria based on the user's menu selection
    switch (selection)
    {
        //if user enters 0 from the menu, the function returns the head of the list and no sorting occurs
        case 0:
            return head;

        //if user enters 1 from the menu, the function sorts the linked list by name in ascending order
        case 1:
            //assigning boolean to the result of comparing two strings. This value will be passed to the sortLogicPtr function to determine whether to swap nodes
            boolean = strcmp(ptr2->name, ptr->name);
            //calling the sortLogicPtr function to sort doubly linked list
            manager->sortLogicPtr(head, ptr, ptr2, &boolean, manager);
            printf("Students sorted by name lexicographically (ascending)!\n");
            break;

        //if the user enters 2 from the menu, the functions sorts the linked list by gpa in ascending order
        case 2:
            //ternary expression which evaluates to -1 if the gpa of the student that ptr points to is greater than the gpa of the student that ptr2 points to; otherwise, boolean is assigned the value 1
            boolean = (ptr->gpa > ptr2->gpa) ? (-1) : (1);
            //calling the sortLogicPtr function to sort doubly linked list
            manager->sortLogicPtr(head, ptr, ptr2, &boolean, manager);
            printf("Students sorted by GPA (lowest to highest)!\n");
            break;

        //if the user enters 3 from the menu, the functions sorts the linked list by gpa in descending order
        case 3:
            //ternary expression which evaluates to -1 if the gpa of the student that ptr points is less than the gpa of the student that ptr2 points to; otherwise, boolean is assigned the value 1
            boolean = (ptr->gpa < ptr2->gpa) ? (-1) : (1);
            //calling the sortLogicPtr function to sort doubly linked list
            manager->sortLogicPtr(head, ptr, ptr2, &boolean, manager);
            printf("Students sorted by GPA (highest to lowest)!\n");
            break;

        //if the user enters 4 from the menu, the functions sorts the linked list by attempts in ascending order
        case 4:
            //ternary expression which evaluates to -1 if the COP 2510 letter grade of the student that ptr points to is greater than the COP 2510 letter grade of the student that ptr2 points to; otherwise, boolean is assigned the value 1
            boolean = (ptr->attempts > ptr2->attempts) ? (-1) : (1);
            //calling the sortLogicPtr function to sort doubly linked list
            manager->sortLogicPtr(head, ptr, ptr2, &boolean, manager);
            printf("Students sorted by attempts (fewest to most)!\n");
            break;

        //if the user enters 5 from the menu, the functions sorts the linked list by attempts in descending order
        case 5:
            //ternary expression which evaluates to -1 if the COP 2510 letter grade of the student that ptr points to is less than the COP 2510 letter grade of the student that ptr2 points to; otherwise, boolean is assigned the value 1
            boolean = (ptr->attempts < ptr2->attempts) ? (-1) : (1);
            //calling the sortLogicPtr function to sort doubly linked list
            manager->sortLogicPtr(head, ptr, ptr2, &boolean, manager);
            printf("Students sorted by attempts (most to fewest)!\n");
            break;

        //if the user enters 6 from the menu, the functions reverses the linked list
        case 6:
            //calling the reversePtr function to reverse the doubly linked list and assigning the new head to head
            head = manager->reversePtr(head, manager);
            printf("List reversed!\n");
            break;

        //if the user enters 7 from the menu, the function exits the sorting menu
        case 7:
            break;
    }

    return head;
}

//function definition for sortLogic which provides the functionality for how to sort the doubly linked list of students
struct Student *sortLogic(struct Student *head, struct Student *ptr, struct Student *ptr2, const int *logic, const struct ListManager *manager)
{
    //outer for loop which iterates over the list of students
    for (; ptr != NULL; ptr = ptr->next)
        //inner for loop which iterates over the list of students
        for (ptr2 = ptr->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            //selection statement which evaluates to true if logic is a positive value; if so, swap the nodes
            if (*logic)
                //calling the swapPtr function to swap the nodes that ptr and ptr2 point to
                manager->swapPtr(head, ptr, ptr2);

            //selection statement which evaluates to true if logic is 0; if so, compare the students based on the given criteria
            else if (*logic == 0)
            {
                //selection statement which evaluates to true if the COP 2510 letter grade of the student that ptr points to is greater than the COP 2510 letterGrade of the student that ptr2 points to
                if (ptr->copGrade > ptr2->copGrade)
                    //calling the swapPtr function to swap the nodes that ptr and ptr2 point to
                    manager->swapPtr(head, ptr, ptr2); 

                //selection statement which evaluates to true if the COP 2510 letter grade of the student that ptr and ptr2 point to is equal, but the gpa of the student that ptr points to is less than the gpa of the student that ptr2 points to
                else if (ptr->copGrade == ptr2->copGrade && ptr->gpa < ptr2->gpa)
                    //calling the swapPtr function to swap the nodes that ptr and ptr2 point to
                    manager->swapPtr(head, ptr, ptr2);
                
                //selection statement which evaluates to true if the COP 2510 letter grade of the student that ptr and ptr2 point to is equal, the gpa of the student that ptr and ptr2 point to is equal, but the name of the student that ptr points to is lexicographically greater than the name of the student that ptr2 points to
                else if (ptr->copGrade == ptr2->copGrade && ptr->gpa == ptr2->gpa && strcmp(ptr->name, ptr2->name) > 0)
                    //calling the swapPtr function to swap the nodes that ptr and ptr2 point to
                    manager->swapPtr(head, ptr, ptr2);
            }    
        }

    return head;    
}

//function definition for swap which is responsible for swapping the data of the nodes within the doubly linked list of the students
void swap(struct Student *head, struct Student *ptr, struct Student *ptr2)
{
    //variable declarations using dynamically allocated memory
    struct Student *temp = malloc(sizeof(struct Student));
    char tempName[MAX_LENGTH + 1], tempNetid[MAX_LENGTH + 1], tempCop2510_grade;
    double tempGPA;
    int tempAttempts;

    //selection statement which evaluates to true if temp was not successfully allocated memory; if so, terminate the function
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

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

    //reassigning ptr to the head of the list and ptr2 to the next element after the head of the list
    ptr = head;
    ptr2 = ptr->next;
}

//function definition for reverse which reverses the doubly linked list of students
struct Student *reverse(struct Student *head, const struct ListManager *manager)
{
    //variable declarations and initializations
    struct Student *ptr = head, *ptr2 = head;
    int nodes = 1;

    //for loop which counts the number of nodes in the list
    for (; ptr2->next != NULL; ptr2 = ptr2->next, nodes++);

    //for loop which reverses the doubly linked list of students by calling the swapPtr function
    for (int i = 0; i < nodes / 2 && ptr != NULL && ptr2 != NULL; manager->swapPtr(head, ptr, ptr2), ptr2 = ptr2->previous, ptr = ptr->next, i++);

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
