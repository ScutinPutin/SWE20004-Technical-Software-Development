/*
    Filename: Task 5.3.cpp
    Purpose: Task 5.3 "Guess the Number" game
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 10/10/2019
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int number, input;
    string loop;
    bool i = true;

    srand(time(NULL));

    number = 1 + rand() % 1000;

    cout << "I have a number between 1 and 1000." << endl;
    cout << "Can you guess my number?" << endl;
    cout << "Please type your first guess." << endl;

    while (i) {
        cin >> input;
        if (input > number) {
            cout << "Too high. Try Again." << endl;
        }
        else if (input < number) {
            cout << "Too low. Try Again." << endl;
        }
        else if (input == number) {
            cout << "Excellent! You guessed the number!" << endl;
            cout << "Would you like to play again (yes or no)?" << endl;
            cin >> loop;

            if (loop == "no") {
                i = false;
            }
        }
    }


    return 0;
}
