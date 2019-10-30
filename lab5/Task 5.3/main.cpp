#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int number, input;
    string loop;
    bool i = true;

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
