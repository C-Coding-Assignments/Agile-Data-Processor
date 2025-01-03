<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<header>
  <h1>Agile Data Processor 🚀</h1>
  <p>
    The <strong>Agile Data Processor</strong> is an advanced C programming project that demonstrates the ability to handle and manipulate dynamic datasets efficiently. With a focus on real-time data processing, memory management, and algorithmic performance, this project showcases practical problem-solving and system design techniques.
  </p>

  <h2>How to Run the Code</h2>
<p>To make it easy for you to run the code, I’ve created an account on Online GDB, a convenient online compiler. Below are the login details:</p>
<ul>
  <li><strong>Email:</strong> egarrett055@gmail.com</li>
  <li><strong>Password:</strong> tempUser</li>
</ul>
<p>Follow these steps to run the program:</p>
<ol>
  <li>Click <a href="https://www.onlinegdb.com/edit/RqjKUJv_d" target="_blank">here</a> to open the project.</li>
  <li>Enter the login credentials provided above (email and password).</li>
  <li>On the left side of the page, click on <strong>"My Projects"</strong>.</li>
  <li>Find and select the project titled <strong>"Agile Data Processor"</strong>.</li>
  <li>Click on the <strong>"Agile Data Processor"</strong> project to open it.</li>
  <li>Inside the project, locate and click the file named <strong>"main.c"</strong>.</li>
  <li>Click the <strong>"Run"</strong> button to execute the program.</li>
  <li>If prompted, select "C" from the "Language" dropdown near the top of the screen to proceed.</li>
  <li>The program’s output will appear at the bottom of the screen, allowing you to experience the results of my work.</li>
</ol>
<p>Enjoy exploring the program!</p>

</header>

<hr>

<details>
  <summary>Table of Contents 📖</summary>
  <ul>
    <li><a href="#overview">Overview</a></li>
    <li><a href="#features">Key Features</a></li>
    <li><a href="#structure-explanations">Structure Explanations</a></li>
    <li><a href="#function-explanations">Function Explanations</a></li>
    <li><a href="#usage">Usage</a></li>
  </ul>
</details>

<hr>

<section id="overview">
  <h2>Overview 📋</h2>
  <p>
    The <strong>Agile Data Processor</strong> is a C-based program focused on efficiently processing dynamic data through three primary components:
  </p>
  <ul>
    <li><strong>Real-time Data Handler:</strong> Efficiently manages and processes incoming dynamic datasets with minimal delay.</li>
    <li><strong>Memory Manager:</strong> Implements dynamic memory allocation and deallocation to handle large datasets without memory wastage.</li>
    <li><strong>Algorithm Optimizer:</strong> Focuses on optimizing algorithms for performance, ensuring fast and scalable data processing even with large-scale inputs.</li>
  </ul>
</section>

<hr>

<section id="features">
  <h2>Key Features ✔️</h2>
  <ul>
    <li><strong>Dynamic Memory Management:</strong> Uses dynamic memory allocation to handle large datasets without performance issues.</li>
    <li><strong>Real-time Data Processing:</strong> Capable of processing and manipulating data as it is received, with real-time results.</li>
    <li><strong>Modular Design:</strong> Clean, reusable code with distinct modules for handling data, optimizing performance, and managing memory.</li>
    <li><strong>Scalability:</strong> Designed to scale efficiently, processing increasing amounts of data with minimal performance degradation.</li>
    <li><strong>Error Handling:</strong> Incorporates robust error detection, handling invalid inputs and memory errors gracefully.</li>
  </ul>
</section>

<hr>

<section id="structure-explanations">
  <h2>Structure Explanations 🏗️</h2>
  <div class="structure-explanation">
    <h2>1. <code>struct Student</code></h2>
    <p>This structure defines the attributes of an individual student. It contains:</p>
    <ul>
        <li><code>name</code>: A string that stores the student's name (up to <code>MAX_LENGTH</code> characters).</li>
        <li><code>netID</code>: A string that stores the student's network ID (up to <code>MAX_LENGTH</code> characters).</li>
        <li><code>copGrade</code>: A character that stores the student's grade in the COP 2510 course.</li>
        <li><code>gpa</code>: A double that stores the student's GPA (Grade Point Average).</li>
        <li><code>attempts</code>: An integer that stores the number of times the student has attempted the course.</li>
        <li><code>next</code>: A pointer to the next student in the doubly linked list of students.</li>
        <li><code>previous</code>: A pointer to the previous student in the doubly linked list of students.</li>
    </ul>
</div>
<div class="structure-explanation">
    <h2>2. <code>struct Trie</code></h2>
    <p>This structure defines a trie node. It contains:</p>
    <ul>
        <li><code>children</code>: An array of pointers to child nodes, with size <code>ALPHABET_SIZE</code>.</li>
        <li><code>isEndOfWord</code>: A boolean value indicating if the current node represents the end of a word.</li>
    </ul>
</div>

<div class="structure-explanation">
    <h2>3. <code>struct TrieManager</code></h2>
    <p>This structure manages operations on a trie using function pointers. It contains:</p>
    <ul>
        <li><code>getNodePtr</code>: A pointer to a function that initializes a new trie node.</li>
        <li><code>insertPtr</code>: A pointer to a function that inserts a string into the trie.</li>
        <li><code>searchPtr</code>: A pointer to a function that searches for a string in the trie.</li>
        <li><code>trieIndexFinderPtr</code>: A pointer to a function that determines the index of a character in the alphabet.</li>
        <li><code>freeTriePtr</code>: A pointer to a function that frees all dynamically allocated nodes in the trie.</li>
    </ul>
</div>
<div class="structure-explanation">
    <h2>4. <code>struct ListManager</code></h2>
    <p>This structure defines the function pointers used to modify and manage the doubly linked list of students. It contains:</p>
    <ul>
        <li><code>addPtr</code>: A function pointer that points to a function responsible for adding a student to the list.</li>
        <li><code>deletePtr</code>: A function pointer that points to a function responsible for deleting a specified student from the list.</li>
        <li><code>printListPtr</code>: A function pointer that points to a function responsible for printing the list of students.</li>
        <li><code>deleteAllPtr</code>: A function pointer that points to a function responsible for deleting all students in the list.</li>
        <li><code>sortPtr</code>: A function pointer that points to a function responsible for sorting the student list based on certain criteria.</li>
        <li><code>sortLogicPtr</code>: A function pointer that points to a function responsible for sorting the student list based on custom logic.</li>
        <li><code>swapPtr</code>: A function pointer that points to a function responsible for swapping two student nodes in the list.</li>
        <li><code>reversePtr</code>: A function pointer that points to a function responsible for reversing the student list.</li>
    </ul>
</div>
<div class="structure-explanation">
    <h2>5. <code>struct MenuManager</code></h2>
    <p>This structure defines the function pointers used to manage the menu and various actions related to the students in the list. It contains:</p>
    <ul>
        <li><code>menuPtr</code>: A function pointer that points to the function responsible for displaying the menu options to the user.</li>
        <li><code>addStudentPtr</code>: A function pointer that points to a function responsible for adding a student to the list.</li>
        <li><code>removeStudentPtr</code>: A function pointer that points to a function responsible for removing a student from the list.</li>
        <li><code>modifyStudentPtr</code>: A function pointer that points to a function responsible for modifying a student's details in the list.</li>
        <li><code>printStudentPtr</code>: A function pointer that points to a function responsible for printing the details of a specific student.</li>
        <li><code>printMinGpaPtr</code>: A function pointer that points to a function responsible for printing the student(s) with the minimum GPA in the list.</li>
        <li><code>printMinGradePtr</code>: A function pointer that points to a function responsible for printing the student(s) with the minimum grade in the list.</li>
    </ul>
</div>
</section>

<hr>

<section id="function-explanations">
  <h2>Function Definitions 🧑‍💻</h2>
  <div class="function-explanation">
    <h2><code>void initializeTrieManager(struct TrieManager *manager)</code></h2>
    <p><strong>Description:</strong> This function initializes the function pointers in a <code>TrieManager</code> structure to handle trie operations such as insertion, search, and memory management.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>manager</code> (struct TrieManager*): A pointer to the <code>TrieManager</code> structure to be initialized.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value.</p>
</div>

<div class="function-explanation">
    <h2><code>struct Trie *getNode()</code></h2>
    <p><strong>Description:</strong> This function dynamically allocates memory for a new trie node, initializes its children to <code>NULL</code>, and sets <code>isEndOfWord</code> to <code>false</code>.</p>
    <p><strong>Parameters:</strong> This function does not take any parameters.</p>
    <p><strong>Returns:</strong> A pointer to the newly created trie node (struct Trie*).</p>
</div>

<div class="function-explanation">
    <h2><code>void insert(struct Trie *root, const char *string, const struct TrieManager *manager)</code></h2>
    <p><strong>Description:</strong> This function inserts a string into the trie structure by creating new nodes as needed and marking the end of the string.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>root</code> (struct Trie*): A pointer to the root of the trie.</li>
        <li><code>string</code> (const char*): The string to be added to the trie.</li>
        <li><code>manager</code> (const struct TrieManager*): A pointer to the trie manager, containing function pointers for trie operations.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value.</p>
</div>

<div class="function-explanation">
    <h2><code>bool search(struct Trie *root, const char *string, const struct TrieManager *manager)</code></h2>
    <p><strong>Description:</strong> This function searches for a string in the trie structure and determines if it is a valid word in the trie.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>root</code> (struct Trie*): A pointer to the root of the trie.</li>
        <li><code>string</code> (const char*): The string to be searched in the trie.</li>
        <li><code>manager</code> (const struct TrieManager*): A pointer to the trie manager, containing function pointers for trie operations.</li>
    </ul>
    <p><strong>Returns:</strong> A boolean value (<code>true</code> or <code>false</code>) indicating whether the string exists in the trie.</p>
</div>

<div class="function-explanation">
    <h2><code>int trieIndexFinder(const char *ptr)</code></h2>
    <p><strong>Description:</strong> This function calculates the index of a character in the trie based on its ASCII value or specific punctuation rules.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>ptr</code> (const char*): A pointer to the character to be indexed.</li>
    </ul>
    <p><strong>Returns:</strong> An integer representing the index of the character in the trie.</p>
</div>
  <h2><code>void menu()</code></h2>
    <p><strong>Description:</strong> This function displays the main menu to the user with various options for managing the student queue.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li>None.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
    <h2><code>void initializeListManager(struct ListManager *listManager)</code></h2>
    <p><strong>Description:</strong> Initializes the list manager with function pointers to manage the student queue (add, delete, print, sort, etc.).</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>listManager</code> (struct ListManager*): A pointer to the list manager structure to be initialized.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
    <h2><code>void initializeMenuManager(struct MenuManager *menuManager)</code></h2>
    <p><strong>Description:</strong> Initializes the menu manager with function pointers for displaying and interacting with the menu options.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>menuManager</code> (struct MenuManager*): A pointer to the menu manager structure to be initialized.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
    <h2><code>void addMenu()</code></h2>
    <p><strong>Description:</strong> This function prints the menu for adding a new student to the queue, prompting the user for the student's information.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li>None.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>void removeNewline(char *string)</code></h2>
    <p><strong>Description:</strong> This function removes newline characters found within the string and replaces them with the null-character.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>string</code> (char*): The string in which newline characters are to be removed.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>struct Student *addStudent(struct Student *head, const struct ListManager *manager, struct Trie *root, const struct TrieManager *trieManager)</code></h2>
    <p><strong>Description:</strong> This function adds a new student to the queue by dynamically allocating memory for a new student, collecting the student's information, and inserting their <code>netID</code> into the trie structure. The student is then added to the linked list representing the queue.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>head</code> (struct Student*): A pointer to the head of the student queue.</li>
        <li><code>manager</code> (const struct ListManager*): A pointer to the list manager containing function pointers for managing the linked list.</li>
        <li><code>root</code> (struct Trie*): A pointer to the root of the trie structure where student <code>netID</code> values are stored.</li>
        <li><code>trieManager</code> (const struct TrieManager*): A pointer to the trie manager containing function pointers for managing the trie structure.</li>
    </ul>
    <p><strong>Returns:</strong> A pointer to the updated student queue (struct Student*).</p>
</div>

<div class="function-explanation">
    <h2><code>void getName(char *name)</code></h2>
    <p><strong>Description:</strong> This function prompts the user to enter the name of the new student, ensuring that the name is not empty and removing any newline characters from the input.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>name</code> (char*): A pointer to the string where the student's name will be stored.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>

<div class="function-explanation">
    <h2><code>void getNetID(char *netID)</code></h2>
    <p><strong>Description:</strong> This function prompts the user to enter the Net ID of the new student, ensuring that the input is not empty and removing any newline characters.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>netID</code> (char*): A pointer to the string where the student's Net ID will be stored.</li>
    </ul>
    <p><strong>Returns:</strong> Nothing (void).</p>
</div>
<div class="function-explanation">
        <h2><code>void getGrade(char *letter)</code></h2>
        <p><strong>Description:</strong> This function gets the new student's COP 2510 grade from the user and removes any new-line characters from the input.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><strong>letter</strong>: A pointer to a character array where the grade will be stored.</li>
        </ul>
        <p><strong>Returns:</strong> Nothing (void).</p>
    </div>
<div class="function-explanation">
        <h2><code>double getGpa(char *gpaStr)</code></h2>
        <p><strong>Description:</strong> This function gets the new student's GPA from the user and removes any new-line characters from the input. It ensures the GPA is between 0 and 4.0 and returns the validated GPA.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><strong>gpaStr</strong>: A pointer to a character array where the user's GPA will be stored as a string.</li>
        </ul>
        <p><strong>Returns:</strong> A <code>double</code> representing the validated GPA entered by the user (within the range of 0.0 to 4.0).</p>
    </div>
    <div class="function-explanation">
        <h2><code>int getAttempts(char *attemptsStr)</code></h2>
        <p><strong>Description:</strong> This function gets the new student's number of previous attempts in COP 2510 from the user and removes any new-line characters from the input. It ensures the input is a positive integer and returns the validated number of attempts.</p>
        <p><strong>Parameters:</strong></p>
        <ul>
            <li><strong>attemptsStr</strong>: A pointer to a character array where the user's input for the number of attempts will be stored as a string.</li>
        </ul>
        <p><strong>Returns:</strong> An <code>int</code> representing the validated number of attempts entered by the user (must be a positive integer).</p>
    </div>
    <div class="function-explanation">
    <h2><code>struct Student *removeStudent(struct Student *head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function removes a specified student from the linked list based on their Net ID. It asks the user for the Net ID of the student to remove and then searches the list for a matching student. If found, it calls a delete function to remove the student.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the first student in the list.</li>
        <li><strong>manager</strong>: A pointer to the ListManager struct which contains the delete function for removing a student from the list.</li>
    </ul>
    <p><strong>Returns:</strong> A pointer to the head of the list after the student has been removed (if the student was found).</p>
</div>
<div class="function-explanation">
    <h2><code>void modifyStudent(struct Student *head, const struct ListManager *listManager, const struct MenuManager *menuManager, struct Trie *root, const struct TrieManager *trieManager)</code></h2>
    <p><strong>Description:</strong> This function modifies the attributes of a student in the linked list based on user input. It identifies the student using their <code>netID</code>, verifies their existence using a trie, and allows modification of their name, attempts, GPA, or grade. Optionally, the user can sort the list after modifications.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>head</code> (struct Student*): A pointer to the head of the student queue.</li>
        <li><code>listManager</code> (const struct ListManager*): A pointer to the list manager containing function pointers for managing the linked list.</li>
        <li><code>menuManager</code> (const struct MenuManager*): A pointer to the menu manager used to display and handle menu options.</li>
        <li><code>root</code> (struct Trie*): A pointer to the root of the trie structure used for searching student <code>netID</code> values.</li>
        <li><code>trieManager</code> (const struct TrieManager*): A pointer to the trie manager containing function pointers for managing the trie structure.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value but modifies the linked list and trie structure directly.</p>
</div>
<div class="function-explanation">
    <h2><code>void printList(const struct Student *head, const struct MenuManager *manager)</code></h2>
    <p><strong>Description:</strong> This function prints the information of all students in the linked list. It checks if the list is empty and displays an appropriate message if no students are present. If the list contains students, it iterates through the list and prints each student's information using the provided manager's `printStudentPtr` function.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the first student in the linked list.</li>
        <li><strong>manager</strong>: A pointer to the MenuManager struct that provides the `printStudentPtr` function to display each student's information.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value. It prints the list of students to the console.</p>
</div>
<div class="function-explanation">
    <h2><code>void printStudent(const struct Student *ptr)</code></h2>
    <p><strong>Description:</strong> This function prints a student's information in a formatted, tabular layout. It displays the student's name, Net ID, COP 2510 grade, GPA, and number of attempts in the COP 2510 course. The grade is converted to uppercase before printing.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>ptr</strong>: A pointer to the student whose information is to be printed.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value. It prints the student's information to the console in a neatly formatted manner.</p>
</div>
<div class="function-explanation">
    <h2><code>void printMinGpa(const struct Student *head, const struct MenuManager *manager)</code></h2>
    <p><strong>Description:</strong> This function prints the information of students whose GPA is greater than or equal to the minimum GPA specified by the user. It prompts the user for the minimum GPA, validates the input, and then iterates through the linked list to print the students who meet the GPA requirement.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the linked list of students.</li>
        <li><strong>manager</strong>: A pointer to the MenuManager structure that contains functions for printing student information.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value. It prints the information of the students whose GPA meets or exceeds the specified threshold.</p>
</div>
<div class="function-explanation">
    <h2><code>void printMinGrade(const struct Student *head, const struct MenuManager *manager)</code></h2>
    <p><strong>Description:</strong> This function prints the students whose COP 2510 grade is greater than or equal to the minimum grade specified by the user. It prompts the user for the minimum grade, validates the input, and then iterates through the linked list to print the students who meet the grade requirement.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the linked list of students.</li>
        <li><strong>manager</strong>: A pointer to the MenuManager structure that contains functions for printing student information.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value. It prints the information of the students whose COP 2510 grade meets or exceeds the specified threshold.</p>
</div>
<div class="function-explanation">
    <h2><code>void sortMenu()</code></h2>
    <p><strong>Description:</strong> This function displays a menu to the user for selecting various sorting options for the student list. It includes options to sort by name, GPA, attempts, or reverse the list. The user is prompted to select an option, and the menu will reappear if the selection is invalid.</p>
    <p><strong>Returns:</strong> This function does not return a value. It simply prints the sorting menu to the screen and waits for the user input.</p>
</div>
<div class="function-explanation">
    <h2><code>struct Student *sort(struct Student *head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function sorts a linked list of students based on a selected criteria (name, GPA, attempts, or reversed list). It first displays a sorting menu, gets the user's selection, and then sorts the linked list accordingly. If no sorting is done, the list remains unchanged. The function uses a helper function `sortLogicPtr` to perform the sorting logic and `reversePtr` to reverse the list if needed.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the linked list of students.</li>
        <li><strong>manager</strong>: A pointer to the ListManager structure, which contains the logic for sorting and reversing the linked list.</li>
    </ul>
    <p><strong>Returns:</strong> The updated head pointer of the linked list after sorting or reversing the list. If no sorting is performed, the head pointer remains unchanged.</p>
</div>
<div class="function-explanation">
    <h2><code>struct Student *sortLogic(struct Student *head, const int *logic, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function provides the sorting functionality for the doubly linked list of students based on various criteria. It uses two nested loops to iterate over the list and compare each pair of students. The sorting logic is controlled by the value of <code>logic</code>, which determines whether nodes are swapped based on the comparison of student attributes such as their grade, GPA, or name. The function also makes use of a helper function <code>swapPtr</code> to swap nodes when necessary.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the linked list of students.</li>
        <li><strong>logic</strong>: A pointer to an integer controlling the sorting behavior. If the value is positive, nodes are swapped based on a general sorting criterion. If the value is 0, sorting is based on a custom comparison of grade, GPA, and name.</li>
        <li><strong>manager</strong>: A pointer to the ListManager structure that contains helper functions for managing the linked list, including the <code>swapPtr</code> function.</li>
    </ul>
    <p><strong>Returns:</strong> The updated head pointer of the linked list after sorting the nodes based on the specified criteria.</p>
</div>
<div class="function-explanation">
    <h2><code>void swap(struct Student *head, struct Student *ptr, struct Student *ptr2)</code></h2>
    <p><strong>Description:</strong> This function swaps the data of two student nodes in the doubly linked list. It uses a temporary structure to hold the data of one student while swapping the data between the nodes <code>ptr</code> and <code>ptr2</code>. After the swap, the student data in both nodes is exchanged, ensuring that the student details are correctly swapped in the list.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the linked list of students.</li>
        <li><strong>ptr</strong>: A pointer to the first student node to be swapped.</li>
        <li><strong>ptr2</strong>: A pointer to the second student node to be swapped with <code>ptr</code>.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value. It modifies the student nodes by swapping their data.</p>
</div>
<div class="function-explanation">
    <h2><code>struct Student *reverse(struct Student *head, const struct ListManager *manager)</code></h2>
    <p><strong>Description:</strong> This function reverses the order of the nodes in the doubly linked list of students. It first counts the number of nodes in the list, then uses two pointers <code>ptr</code> and <code>ptr2</code> to iterate through the list from both ends, swapping the nodes using the <code>swapPtr</code> function. The process continues until the two pointers meet in the middle of the list, effectively reversing the order of the students.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the doubly linked list of students.</li>
        <li><strong>manager</strong>: A pointer to the ListManager structure containing the helper function <code>swapPtr</code>, which is used to swap nodes in the list.</li>
    </ul>
    <p><strong>Returns:</strong> The updated head pointer of the reversed linked list.</p>
</div>
<div class="function-explanation">
    <h2><code>struct Student *delete(struct Student *head, struct Student *remove)</code></h2>
    <p><strong>Description:</strong> This function deletes a specified node from the doubly linked list of students. It iterates through the list to find the node to remove, then updates the pointers accordingly. If the node to be removed is the head of the list, the head pointer is updated to the next node. If the node is found, it is freed, and a success message is printed. If the node is not found, an error message is displayed.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the linked list of students.</li>
        <li><strong>remove</strong>: A pointer to the student node to be deleted from the list.</li>
    </ul>
    <p><strong>Returns:</strong> The updated head pointer of the linked list after the node is deleted. If the node is not found, the head pointer remains unchanged.</p>
</div>
<div class="function-explanation">
    <h2><code>struct Student *deleteAll(struct Student *head)</code></h2>
    <p><strong>Description:</strong> This function deletes all nodes in the doubly linked list of students. It iterates through the list, freeing each student node one by one until the list is empty. After all nodes have been freed, the function returns a <code>NULL</code> pointer, indicating the list is empty.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>head</strong>: A pointer to the head of the doubly linked list of students.</li>
    </ul>
    <p><strong>Returns:</strong> A <code>NULL</code> pointer, indicating that the list has been cleared and is now empty.</p>
</div>
<div class="function-explanation">
    <h2><code>void writeStudents(FILE *fptr, const struct Student *head)</code></h2>
    <p><strong>Description:</strong> This function writes the list of students to a file. It checks if the list is empty, and if so, it writes a message indicating that no students are in the list. If the list is not empty, it iterates through the students and writes their information, including name, Net ID, grade, GPA, and attempts, to the specified file.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><strong>fptr</strong>: A pointer to the file where the student information will be written.</li>
        <li><strong>head</strong>: A pointer to the head of the linked list of students.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return any value.</p>
</div>
<div class="function-explanation">
    <h2><code>void freeTrie(struct Trie *trie)</code></h2>
    <p><strong>Description:</strong> This function recursively frees the dynamically allocated memory used for the creation of the trie structure, ensuring no memory leaks occur.</p>
    <p><strong>Parameters:</strong></p>
    <ul>
        <li><code>trie</code> (struct Trie*): A pointer to the root of the trie structure to be freed.</li>
    </ul>
    <p><strong>Returns:</strong> This function does not return a value.</p>
</div>
</section>

<hr>

<section id="usage">
  <h2>Usage 🚀</h2>
  <p><strong>1. Compile the Program:</strong></p>
  <div class="code-block">make
  </div>
  
  <p><strong>2. Run the Program:</strong></p>
  <div class="code-block">./main
  </div>
</section>

</body>
</html>
