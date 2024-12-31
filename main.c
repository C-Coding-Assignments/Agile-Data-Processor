#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //variable declarations and initializations using dynamic memory allocation
    char temp[MAX_LENGTH + 1];
    struct Student *head = NULL;
    struct MenuManager *menuManager = malloc(sizeof(struct MenuManager));
    struct ListManager *listManager = malloc(sizeof(struct ListManager));
    struct TrieManager *trieManager = malloc(sizeof(struct TrieManager));
    struct Trie *trie;
    FILE *filePtr;

    //selection statement which evaluates to true if dynamic memory allocation failed for menuManager and/or listManager
    if (menuManager == NULL || listManager == NULL || trieManager == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //initializing the function pointer members associated with the MenuManager struct
    initializeMenuManager(menuManager);
    //initializing the function pointer members associated with the ListManager struct
    initializeListManager(listManager);
    //initializing the function pointer members associated with the TrieManager struct
    initializeTrieManager(trieManager);

    //calling the getNode function to initialize the root of the trie structure
    trie = trieManager->getNodePtr();

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
            head = menuManager->addStudentPtr(head, listManager, trie, trieManager); 

        //selection statement which evaluates to true if the user has entered p to remove one of the students in the queue
        else if (!strcmp(temp, "p"))
            head = menuManager->removeStudentPtr(head, listManager); 

        //selection statement which evaluates to true if the user has entered m to modify a student in the queue
        else if (!strcmp(temp, "m"))
            menuManager->modifyStudentPtr(head, listManager, menuManager, trie, trieManager);

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
        else if (strcmp(temp, "q"))
            printf("Invalid menu option. Try again.\n");

        putchar('\n');    
    } while (strcmp(temp, "q"));

    //printing the final list of students to the user
    printf("Here are all the students in the queue:\n");
    //calling the printList to print all the students in the queue
    listManager->printListPtr(head, menuManager);

    //opening the file to write the list of students in the queue in the text file
    filePtr = fopen("student.txt", "w");

    //selection statement which evaluates to true if the file opening failed; if so, print an error message and exit the program
    if (filePtr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    //calling the writeStudents function to write the list of students in the queue to the text file
    writeStudents(filePtr, head);

    //closing the file after writing the list of students in the queue to the text file
    fclose(filePtr);

    //calling the deleteAll function to free all dynamically allocated students in the queue
    listManager->deleteAllPtr(head);

    //calling the freeTrie function to free the dynamically allocated memory within the trie structure
    trieManager->freeTriePtr(trie);

    //freeing the dynamically allocated memory for menuManager, listManager, and trieManager
    free(menuManager);
    free(listManager);
    free(trieManager);

    return 0;
}
