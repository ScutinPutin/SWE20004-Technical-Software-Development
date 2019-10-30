/*
    Filename: Task 10.2cpp
    Purpose: Linked list data storage & output
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 30/10/2019
*/

#include <iostream>

using namespace std;

struct studentName {
    char *letter;
    struct studentName *next;
};

typedef struct studentName STUDENTName;
typedef STUDENTName *STUDENTNamePtr;

void display(studentName *contents) {

while (contents != NULL) {
    cout << contents->letter << "\t\t" << endl;
    contents = contents->next;
}
cout << endl;
return;
}


int main()
{
    studentName *root;
    studentName *conductor;

    root = new studentName;
    root->next = 0;
    root->letter = "s";
    conductor = root;
    cout << root->letter << endl;

    if (conductor != 0) {
        while( conductor->next !=0)
            conductor = conductor->next;
    }
    conductor->next = new studentName;
    conductor = conductor->next;
    conductor->next = 0;
    conductor->letter = "c";
    cout << conductor->letter << endl;

    conductor->next = new studentName;
    conductor = conductor->next;
    conductor->next = 0;
    conductor->letter = "o";
    cout << conductor->letter << endl;

    conductor->next = new studentName;
    conductor = conductor->next;
    conductor->next = 0;
    conductor->letter = "t";
    cout << conductor->letter << endl;

    conductor->next = new studentName;
    conductor = conductor->next;
    conductor->next = 0;
    conductor->letter = "t";
    cout << conductor->letter << endl;

    return 0;
}
