#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int diceRoll() {
    return rand() % 6 + 1;
}

int main()
{
    srand(time(NULL));

    int roll[7][7] = {0};

    for (int i = 0; i < 50000; i++) {
        roll[diceRoll()][diceRoll()] += 1;
    }

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

    for (int x = 1; x < 7; x++) {
        cout << roll[x][x] << endl;
        total = roll[x][x] + total;
    }

    cout << "------" << endl;
    cout << total << endl;

    if (total > 8350) {
        cout << total << " is greater than 8350, the player won the game!!" << endl;
    }
    else {
        cout << total << " is less than 8350, the player lost the game :(" << endl;
    }

    return 0;
}
