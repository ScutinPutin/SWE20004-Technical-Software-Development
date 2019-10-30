#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int diceRoll() {
    return rand() % 6 + 1;
}

int main()
{
bool i = true;
int bankBalance = 100;

while(i) {
    bool j = true;
    int bet;
    srand(time(NULL));

    cout << "You have $" << bankBalance << " in the bank." << endl;
    cout << "Place your wager: ";
    cin >> bet;
    bankBalance = bankBalance - bet;

    int diceOne = diceRoll();
    int diceTwo = diceRoll();
    int diceTotal = diceOne + diceTwo;

    if (diceTotal == 2 || diceTotal == 3 || diceTotal == 12) {
        cout << "Player Loses, better luck next time!" << endl;
    }

    else if (diceTotal == 7 || diceTotal == 11) {
        cout << "Player Wins!!" << endl;
        bankBalance = bet * 2 + bankBalance;
    }

    else {
        cout << "Player Rolled " << diceOne << " + " << diceTwo << " = " << diceTotal << endl;
        cout << "Point is " << diceTotal << endl;
        cout << "Way too lucky! THose dice have to be loaded!" << endl;
        cout << "You're up big. Now's the time to cash in your chips!" << endl;

        while(j) {
            int diceThree = diceRoll();
            int diceFour = diceRoll();
            int subDiceTotal = diceThree + diceFour;

            cout << "Player Rolled " << diceThree << " + " << diceFour << " = " << subDiceTotal << endl;

            if (subDiceTotal == 7) {
                cout << "Player Loses!" << endl;
                j = false;
            }

            else if (subDiceTotal == diceTotal) {
                cout << "Player Wins!!" << endl;
                bankBalance = bet * 2 + bankBalance;
                j = false;
            }

        }
    }
    string userInput;
    cout << "Would you like to try again( y/n)?" << endl;
    cin >> userInput;

    if (userInput == "n") {
        cout << "Thank you for playing!" << endl;
        i = false;
        break;
    }
}
    return 0;
}
