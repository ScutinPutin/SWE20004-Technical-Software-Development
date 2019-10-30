/*
    Filename: 102581840.cpp
    Purpose: Assignment Luhn Algorithm Credit Card Validity Checker
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 1/10/2019
*/

#include <iostream>
#include <cmath>

using namespace std;

// Global variable assigned to the postion of the check number in the array
int checkSumPostion = 0;

// Assigns global variable value, by caluclating checksum postion
int chkNum(int sumOne[]) {
    for (int i = 0; i < 20; i++) {
        if (sumOne[i] == -1) {
            int checkNumber = sumOne[i-1];
            checkSumPostion = i - 1;
            return checkNumber;
        }
    }
}

// Function thhat calucales sum1 total
int sum1(int sumOne[]) {
    int sumOneTotal = 0;
    cout << "" << endl;
    cout << "Numbers for sum 1 are: ";
        for (int i = 0; i < checkSumPostion; i+=2) {
            if (sumOne[i] < 0) {
                break;
            }
            cout << sumOne[i] << " ";
            sumOne[i] = sumOne[i] + sumOne[i];

                if (sumOne[i] >= 10) {
                    int first_digit = sumOne[i] / 10;
                    int last_digit = sumOne[i] % 10;
                    sumOne[i] = first_digit + last_digit;
                }
            sumOneTotal += sumOne[i];
        }
        cout << "" << endl;
        return sumOneTotal;
}

// Function that calculates sum two total
int sum2(int sumTwo[]) {
    int sumTwoTotal = 0;
    cout << "Numbers for sum 2 are: ";
        for (int i = 1; i < checkSumPostion; i+=2) {
            if (sumTwo[i] < 0) {
                break;
            }
            cout << sumTwo[i] << " ";
            sumTwoTotal += sumTwo[i];
        }
    return sumTwoTotal;
}

int main() {
    int creditCard[20];

    cout << "Please enter credit card numbers:" << endl;

    for (int i = 0; i < 20; i++) {
        cin >> creditCard[i];

        if (creditCard[i] == -1) {
            break;
        }
    }

    cout << "Credit card number is: ";

    for (int j = 0; j < 20; j++) {
        if (creditCard[j] == -1 ) {
            break;
        }

        cout << creditCard[j];
    }

    // Calcualtes check sum postion and sum 1 & 2
    int checkNumber = chkNum(creditCard);
    int totalOne = sum1(creditCard);
    int totalTwo = sum2(creditCard);

    int total = totalOne + totalTwo;
    total = total * 9;
    int checkSumDigit = total % 10;

    // Print out total values
    cout << "" << endl;
    cout << "" << endl;
    cout << "Sum 1 is: " << totalOne << endl;
    cout << "Sum 2 is: " << totalTwo << endl;
    cout << "" << endl;
    cout << "Check Number is: " << checkNumber << endl;
    cout << "" << endl;

    // Check if credit card is valid
    if (checkSumDigit == checkNumber) {
        cout << "Check sum is " << checkSumDigit << " and the last digit " << checkNumber << " are the same: Valid credit card number" << endl;
    }
    else {
        cout << "Check sum is " << checkSumDigit << " and the last digit " << checkNumber << " are not the same: Invalid credit card number" << endl;
    }
    return 0;
}
