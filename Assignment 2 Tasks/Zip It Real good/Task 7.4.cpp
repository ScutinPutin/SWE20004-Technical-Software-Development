/*
    Filename: Task 7.4.cpp
    Purpose: Task 7.4, Dice rolling game
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 10/10/2019
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Function that rolls dice
int diceRoll() {
    return rand() % 6 + 1;
}

int main()
{
    srand(time(NULL));

    // Initalizes 2 Dimentional array and sets defualt values to 0
    int roll[7][7] = {0};

    // Rolls dice 50,000 times and stores each time dice is rolled into array
    for (int i = 0; i < 50000; i++) {
        roll[diceRoll()][diceRoll()] += 1;
    }

    // Prints combination of rolls to the screen in table format
    for (int j = 1; j < 7; j++) {
        cout << "" << endl;
        for (int k = 1; k < 7; k++) {
        cout << "|" << roll[j][k] << " |  ";
    }
}
    cout << "" << endl;
    cout << "" << endl;
    cout << "The sum of the diagonal elements is: " << endl;
    int total = 0;

    // Calulcates total rolls for all diaginal rolls
    for (int x = 1; x < 7; x++) {
        cout << roll[x][x] << endl;
        total = roll[x][x] + total;
    }

    cout << "------" << endl;
    cout << total << endl;

    // Determines if player wins or loses game
    if (total > 8350) {
        cout << total << " is greater than 8350, the player won the game!!" << endl;
    }
    else {
        cout << total << " is less than 8350, the player lost the game :(" << endl;
    }

    return 0;
}
