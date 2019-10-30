/*
    Filename: Task4.9.cpp
    Purpose: Task 4.9 User Decicisons
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 6/09/2019
*/
#include <iostream>

using namespace std;

int main() {

    // Declaring vairables
    int raining, a, x;
    bool i = true;

    // Loop forever if I = true
    while(i) {
        cout << "Please enter the day of the week as a number (Monday = 1, Sunday = 7)" << endl;
        cin >> a;
        if (a < 6) {
            cout << "Is it raining outside? (1 for yes, 0 for no)" << endl;
            cin >> raining;

            if (raining) {
                cout << "Take an umbrella!" << endl;
            }
            else {
                cout << "Go to your university class!" << endl;
            }
        }
        else {
            cout << "Is it raining outside? (1 for yes, 0 for no)" << endl;
            cin >> raining;

            if (raining) {
                cout << "Read in bed!"<< endl;
            }
            else {
                cout << "Go out and have fun!" << endl;
            }
        }
        cout << "Do you want to continue? (1 for yes, 0 for no)" << endl;
        cin >> x;
        // If user wants to exit i = 0 = false
        if (!x) {
            i = false;
            cout << "Exiting program!" << endl;
        }
    }
    return 0;
}
