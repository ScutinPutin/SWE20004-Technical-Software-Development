/*
    Filename: 102581840_assignment3Part1.cpp
    Purpose: Part 1, Assignment 3
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 30/10/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//Structure of student array
struct student{
    string name;
    int id;
    float mark;
};

// Reading in values from file into array
struct student readFile(student studentArray[100], string fileLocation) {
    ifstream file(fileLocation.c_str());

    for (int i = 0; i < 100; i++) {
        file >> studentArray[i].name >> studentArray[i].id >> studentArray[i].mark;

        if (file.eof()) {
            break;
        }
    }

    file.close();
}

// Menu Function
int menu() {
    int menuSelection;

    cout << "" << endl;
    cout << "" << endl;
    cout << "1. Display student's details" << endl;
    cout << "2. Calculate average of all student's marks" << endl;
    cout << "3. Sort the student's details" << endl;
    cout << "4. Search for a particular student's mark" << endl;
    cout << "5. Find maximum grade" << endl;
    cout << "6. Add new student to the record" << endl;
    cout << "7. Quit Program" << endl;

    cin >> menuSelection;

    return menuSelection;
}

// Print students to screen
void displayStudents(student studentArray[100], int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        cout << studentArray[i].name << " | " << studentArray[i].id << " | " << studentArray[i].mark << endl;
    }
    cout << "" << endl;
}

// Calculate Average Student Mark
int calculateAverage(student studentArray[100], int sizeOfArray) {
    float gradeTotal = 0;
    float average = 0;
    int divisor = 0;

    for (int i = 0; i < sizeOfArray; i++) {
        gradeTotal = studentArray[i].mark + gradeTotal;
        divisor = divisor + 1;
    }
    average = gradeTotal / divisor;
    return average;
}

// Calculate the size of the array, based up how many rows are contained within "grades.txt"
int sizeOfArray(student studentArray[100], string fileLocation) {
    int counter = 0;
    string line;
    ifstream file(fileLocation.c_str());
    while(getline(file, line)) {
        counter++;
    }
    return counter;
}

// Contains two different sorts based on user input (A-Z or Highest-Lowest)
void sortStudents(student studentArray[100], int sizeOfArray) {
    int menu;
    cout << "" << endl;
    cout << "1. Sort by name (A-Z)" << endl;
    cout << "2. Sort by marks (Highest-Lowest)" << endl;
    cin >> menu;

    if (menu == 1) {
        for (int i = 0; i < sizeOfArray; i++) {
            for (int j = i + 1; j < sizeOfArray; j++) {
                if (studentArray[i].name > studentArray[j].name) {
                    swap(studentArray[i], studentArray[j]);
                }
            }
        }
        cout << "Sorted Results by name (A-Z)" << endl;
        cout << "----------------------------" << endl;
        displayStudents(studentArray, sizeOfArray);
    }
    else if (menu == 2) {
        for (int i = 0; i < sizeOfArray; i++) {
            for (int j = i + 1; j < sizeOfArray; j++) {
                if (studentArray[i].mark < studentArray[j].mark) {
                    swap(studentArray[i], studentArray[j]);
                }
            }
        }
        cout << "Sorted Results by mark (Highest-Lowest)" << endl;
        cout << "---------------------------------------" << endl;
        displayStudents(studentArray, sizeOfArray);
    }
}

// Search for a student record based of user input (Linear or Binary)
int searchStudent(student studentArray[100], int arraySize) {
    int menuOption;
    int flag = 0;
    int searchIndex = 0;
    string studentName;

    cout << "Enter Student Name to search for: " << endl;
    cin >> studentName;

    cout << "Search for student: " << studentName << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cin >> menuOption;

    if (menuOption == 1) {
        for (int i = 0; i < arraySize; i++) {
            if (studentArray[i].name == studentName) {
                searchIndex = i;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            searchIndex = -1;
        }
        return searchIndex;
    }
    else if (menuOption == 2) {
        int first = 0;
        int last = arraySize;
        int middle = (first + last) / 2;

        while (first <= arraySize) {
            if (studentArray[middle].name < studentName) {
                first = middle + 1;
            }
            else if (studentArray[middle].name == studentName) {
                return middle + 1;
                break;
            }
            else {
                last = middle - 1;
            }
            middle = (first + last) / 2;
        }

    }
}

// Find the student with the highest mark
int findMaximum(student studentArray[100], int sizeOfArray) {
    float maximumMark = 1.0;

    for (int i = 0; i < sizeOfArray; i++) {
        if (maximumMark < studentArray[i].mark) {
            maximumMark = studentArray[i].mark;
        }
    }
    return maximumMark;
}

// Update File Function that adds user input into "grades.txt" file
int updateFile(student studentArray[100], string fileLocation, int sizeOfArray) {
    //Local vairables to write to file
    string name;
    int id;
    float mark;
    sizeOfArray = sizeOfArray + 1;

    // Prompt user for values
    cout << "Please enter student name: " << endl;
    cin >> name;
    studentArray[sizeOfArray + 1].name = name;

    cout << "Please enter student id: " << endl;
    cin >> id;
    studentArray[sizeOfArray + 1].id = id;

    cout << "Please enter student mark: " << endl;
    cin >> mark;
    studentArray[sizeOfArray + 1].mark = mark;

    // Write changes to file
    ofstream file;

    file.open(fileLocation.c_str(), ios::app);
    file << "\n" << name << " " << id << " " << mark;

    file.close();

    return sizeOfArray;
}

/*int readUpdatedFile (student studentArray[100], string fileLocation, int sizeOfArray()) {
    ifstream file(fileLocation.c_str());
    sizeOfArray = sizeOfArray + 1;
    file >> studentArray[sizeOfArray].name >> studentArray[sizeOfArray].id >> studentArray[sizeOfArray].mark;

    file.close();
}*/


int main()
{
    // Variable Initilization
    struct student studentArray[100];
    string fileLocation = "grades.txt";
    int menuSelcetion, gradeAverage;
    int searchIndex = 0;
    bool z = true;
    string studentName = "default";
    float maximumMark;

    // Start of Program
    cout << "Welcome to the Student Management Program!" << endl;
    cout << "To continue, please enter the file location of student grades: " << endl;
    cin >> fileLocation;

    // Reading grades.txt file, function call.
    readFile(studentArray, fileLocation);

    // Calling the menu function
    while (z) {
    // Continues to keep track of array size
    int arraySize = sizeOfArray(studentArray, fileLocation);
    menuSelcetion = menu();
        switch(menuSelcetion) {
            case 1:
                displayStudents(studentArray, arraySize);
                break;
            case 2:
                gradeAverage = calculateAverage(studentArray, arraySize);
                cout << "The student average is " << gradeAverage << endl;
                break;
            case 3:
                sortStudents(studentArray, arraySize);
                break;
            case 4:
               searchIndex = searchStudent(studentArray, arraySize);

               if (searchIndex == -1) {
                    cout << "Couldn't find student name" << endl;
                }
                else {
                    cout << "Found student at array index: " << searchIndex << endl;
                    cout << studentArray[searchIndex].name << " | " << studentArray[searchIndex].id << " | " << studentArray[searchIndex].mark << endl;
                 }
                break;
            case 5:
                maximumMark = findMaximum(studentArray, arraySize);
                cout << "Maximum mark is: " << maximumMark << endl;
                break;
            case 6:
                updateFile(studentArray, fileLocation, arraySize);
                break;
            case 7:
                cout << "Thank you for using the student management program!" << endl;
                cout << "Exiting Program..." << endl;
                z = false;
                break;
        }
    }
    return 0;
}
