#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //variable declarations and initializations
    char temp[MAX_LENGTH + 1];
    struct Student *head = NULL;
    struct MenuManager *menuManager = malloc(sizeof(struct MenuManager));
    struct ListManager *listManager = malloc(sizeof(struct ListManager));
    FILE *filePtr;
    void (*writeStudentsPtr) (FILE *, const struct Student *) = writeStudents;

    //selection statement which evaluates to true if dynamic memory allocation failed for menuManager and/or listManager
    if (menuManager == NULL || listManager == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //initializing the function pointer members associated with the MenuManager struct
    initializeMenuManager(menuManager);
    //initializing the function pointer members associated with the ListManager struct
    initializeListManager(listManager);

    //printing the main menu to the user
    menuManager->menuPtr();

    //do-while loop which iterates until the user enters q to quit the program
    do
    {
        //getting the user's menu input
        printf("Enter operation code (press h for menu): ");
        fgets(temp, MAX_LENGTH + 1, stdin);
        //removing the new-line characters within the user's input
        removeNewline(temp);

        //selection statement which evaluates to true if the user has entered h to display the main menu
        if (!strcmp(temp, "h"))
            menuManager->menuPtr();

        //selection statement which evaluates to true if the user has entered a to add a new student to the queue
        else if (!strcmp(temp, "a"))   
            head = menuManager->addStudentPtr(head, listManager); 

        //selection statement which evaluates to true if the user has entered p to remove one of the students in the queue
        else if (!strcmp(temp, "p"))
            head = menuManager->removeStudentPtr(head, listManager); 

        //selection statement which evaluates to true if the user has entered m to modify a student in the queue
        else if (!strcmp(temp, "m"))
            menuManager->modifyStudentPtr(head, listManager, menuManager);

        //selection statement which evaluates to true if the user has entered l to list all the students in the queue
        else if (!strcmp(temp, "l"))
            listManager->printListPtr(head, menuManager);

        //selection statement which evaluates to true if the user has entered s to sort all the students in the queue
        else if (!strcmp(temp, "s"))
            head = listManager->sortPtr(head, listManager);

        //selection statement which evaluates to true if the user has entered g to search for students with a minimum GPA and print them to the screen
        else if (!strcmp(temp, "g"))
            menuManager->printMinGpaPtr(head, menuManager);    

        //selection statement which evaluates to true if the user has entered c to search for students with a minimum grade in COP2510 and print them to the screen
        else if (!strcmp(temp, "c"))
            menuManager->printMinGradePtr(head, menuManager);

        //selection statement which evaluates to true if the user has entered an invalid menu option; if so, print an error message
        else
            printf("Invalid menu option. Try again.\n");

        putchar('\n');    
    } while (strcmp(temp, "q"));

    //printing the final list of students to the user
    printf("Here are your students:\n");
    //calling the printListPtr to print all the students in the queue
    listManager->printListPtr(head, menuManager);

    //opening the file to write the list of students in the queue in the text file
    filePtr = fopen("student.txt", "w");

    //selection statement which evaluates to true if the file opening failed; if so, print an error message and exit the program
    if (filePtr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    //calling the writeStudentsPtr function to write the list of students in the queue to the text file
    writeStudentsPtr(filePtr, head);

    //closing the file after writing the list of students in the queue to the text file
    fclose(filePtr);

    //calling the deleteAllPtr function to free all dynamically allocated students in the queue
    listManager->deleteAllPtr(head);

    //freeing the dynamically allocated memory for menuManager and listManager
    free(menuManager);
    free(listManager);

    return 0;
}