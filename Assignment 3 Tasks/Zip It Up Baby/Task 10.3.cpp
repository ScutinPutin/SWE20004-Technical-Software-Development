/*
    Filename: Task 10.3.cpp
    Purpose: Number Sorting into Linked List
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 30/10/2019
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node {
    int number;
    node *next;
};

struct node *head = NULL;

void insertNode(int insertNumber) {
    struct node *newNode = new node;

    newNode->number= insertNumber;

    newNode->next = head;
    head = newNode;
}

void display() {
    int i = 1;

    if (head == NULL) {
        cout << "List is empty." << endl;
    }

    struct node *temp = head;

    while(temp != NULL) {
        cout << i << ": " <<temp->number << endl;
        temp = temp->next;
        i++;
    }
    cout << "" << endl;
}

void numberSort(node randomNumber[10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if(randomNumber[i].number < randomNumber[j].number) {
                swap(randomNumber[i].number, randomNumber[j].number);
            }
        }
    }
}

void calculateAverage(node randomNumber[10]) {
    int numberTotal = 0;
    int divisor = 0;
    int average = 0;

    struct node *temp = head;

    while (temp != NULL) {
        numberTotal += temp->number;
        divisor++;
        temp = temp->next;
    }
    average = (numberTotal/divisor);
    cout << "The average of all random numbers is: " << average << endl;
}

int main() {
    srand(time(0));

    struct node randomNumber[10];

    for (int i = 0; i < 10; i++) {
        randomNumber[i].number = rand() % 50 + 1;
    }

    numberSort(randomNumber);


    for (int i = 0; i < 10; i++) {
        insertNode(randomNumber[i].number);
    }

    display();

    calculateAverage(randomNumber);

    return 0;
}
