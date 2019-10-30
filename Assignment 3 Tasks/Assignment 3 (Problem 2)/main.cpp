/*
    Filename: 102581840_assignment3Part2.cpp
    Purpose: Part 2, Assignment 3
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 30/10/2019
*/


#include <iostream>
#include <fstream>

using namespace std;

// Linked List Structure
struct student{
    string name;
    int id;
    float mark;
    student *next;
};

// Assigning the pointer of head to null
struct student *head = NULL;

// Function to insertNode into the linked list
void insertNode(string studentName, int studentID, float studentMark) {
    struct student *newNode = new student;
    newNode->name = studentName;
    newNode->id = studentID;
    newNode->mark = studentMark;

    newNode->next = head;
    head = newNode;
}

// Function to read in data from file
void readFile() {
    // Variable Initilization to be passed
    string studentName;
    int studentID;
    float studentMark;

    ifstream file("grades.txt");

    for (int i = 0; i < 4; i++) {
        file >> studentName >> studentID >> studentMark;
        insertNode(studentName, studentID, studentMark);
    }

    file.close();
}

// Function to display data from linked list to screen
void display() {
     if (head == NULL) {
        cout << "Student List is empty!" << endl;
        return;
     }
     struct student *temp = head;

     while(temp != NULL) {
        cout << temp->name << ", " << temp->id << ", " << temp->mark << endl;
        temp = temp->next;
     }
    cout << " " << endl;
}

// Function to calculate the average mark of students within the list
int calculateAverage() {
    int markTotal = 0;
    int divisor = 0;
    int average = 0;

    struct student *temp = head;

    while(temp != NULL) {
        markTotal += temp->mark;
        divisor++;
        temp = temp->next;
    }
    average = markTotal / divisor;

    return average;
}

// Function to search for a student from the list
void searchStudent() {
    string searchString;
    int flag = 0;

    cout << " " << endl;
    cout << "Please enter a student name to search for: " << endl;
    cin >> searchString;

    cout << "" << endl;

    struct student *temp = head;

    while(temp != NULL) {
        if (temp->name == searchString) {
            flag = 1;
            cout << "Student Found: " << endl;
            cout << temp->name << ", " << temp->id << ", " << temp->mark << endl;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0) {
        cout << "Error: Student not found" << endl;
    }
}

// Function to find the maximum mark within the list
void findMaximum() {
    float maximumMark = 1.0;

    struct student *temp = head;

    while(temp != NULL) {
        if(maximumMark < temp->mark) {
            maximumMark = temp->mark;
        }
        temp = temp->next;
    }
    cout << "The maximum mark for all students is: " << maximumMark << endl;
}

// Function to add a new node to the list
void updateFile() {
    // Variable Initilzation for Input to file.
    string studentName;
    int studentID;
    float studentMark;

    cout << "Please enter student name: " << endl;
    cin >> studentName;

    cout << "Please enter the student ID: " << endl;
    cin >> studentID;

    cout << "Please enter the student mark: " << endl;
    cin >> studentMark;

    // Write new student to node
    insertNode(studentName, studentID, studentMark);
}

// Function to display the menu to the screen
int menu() {
    int menuSelection;

    cout << "1. Display student's details" << endl;
    cout << "2. Calculate average of all student's marks" << endl;
    cout << "3. Search for a particular student's mark" << endl;
    cout << "4. Find maximum grade" << endl;
    cout << "5. Add a new student to the record" << endl;
    cout << "6. Exit Program" << endl;

    cin >> menuSelection;

    return menuSelection;
}

int main() {
    // Variable Initilization
    int menuSelection;
    float studentAverage;
    bool z = true;

    // Processing Data From File in Main
    readFile();

    // Redirecting to Menu Option
    while(z) {
        menuSelection = menu();
            switch(menuSelection) {
                case 1:
                    display();
                    break;
                case 2:
                    studentAverage = calculateAverage();
                    cout << "The average mark of all students is: " << studentAverage << endl;
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    findMaximum();
                    break;
                case 5:
                    updateFile();
                    break;
                case 6:
                    cout << "Thank you for using student management program!" << endl;
                    z = false;
                    break;
        }
    }

    return 0;
}
