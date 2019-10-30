/*
    Filename: 102581840.cpp
    Purpose: Assignment 1 Encoding and Decoding Program
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 6/09/2019
*/
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;
// Global vairable that determines if second encoding is true or false
string secondEncryption;

// Function that validates the users input
int numberInput() {
    unsigned int input;
    string input_string;
    bool i = true;

    // A while loop that only exits if a valid number is entered.
    while (i) {
    cout << "Enter a Number: " << endl;
    cin >> input;

    // Convert Input Number into String for validation
    string input_convert;
    ostringstream convert;
    convert << input;
    input_convert = convert.str();

    // Digit Validation based on the length of the number.
    unsigned int digits = input_convert.length();

        if (digits == 1) {
            cout << "Not a valid input, re enter the number" << endl;
        }

        else if (digits == 2) {
            cout << "Number contains " << digits << " digits" << endl;
            i = false;
        }

        else if (digits == 3) {
            cout << "Number contains " << digits << " digits" << endl;
            i = false;
        }

        else if (digits > 3 && digits < 8) {
            cout << "Number contains " << digits << " digits" << endl;
            i = false;
        }

        else if (digits == 8) {
            cout << "Number contains " << digits << " digits" << endl;
            i = false;
        }

        else {
            cout << "Not a valid input, re enter the number" << endl;
        }
     }
    return input;
}

int modify(int input){
    // Convert input Number into String for validation
    string input_string;
    ostringstream convert;
    convert << input;
    input_string = convert.str();


    //Assign inputLength used to modify the data for transmission according to different sets of rules.
    int inputLength = input_string.length();

    //Rule set for a two digit number
    if (inputLength == 2) {
        int first_digit = input / 10;
        int last_digit = input % 10;
        int swapped_number = (last_digit * 10) + first_digit;
        return swapped_number;
    }

    //Rule set for a three digit number
    else if (inputLength == 3) {
        int last_digit = input % 10;
        int middle_digit = (input / 10) % 10;
        int first_digit = input / 100;

        int swapped_number = (last_digit * 100) + (middle_digit * 10) + first_digit;
        return swapped_number;
    }

    // Rule set for a four digit number.
    else if (inputLength == 4) {
        double array[inputLength];

        array[1] = input % 10;
        array[2] = (input / 10) % 10;
        array[3] = (input / 100) % 10;
        array[4] = input / 1000;

        for (int i = inputLength; i >= 1; i--) {
            array[i] = array[i] * 3;
            array[i] = array[i] / 10;
            array[i] = fmod(array[i], 1);
            array[i] = array[i] * 10;
        }

        int product = (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1] + 1;
        return product;
    }

    //Rule set for a five digit number.
    else if (inputLength == 5) {
        double array[inputLength];

        array[1] = input % 10;
        array[2] = (input / 10) % 10;
        array[3] = (input / 100) % 10;
        array[4] = (input / 1000) % 10;
        array[5] = (input / 10000) % 10;

        for (int i = inputLength; i >= 1; i--) {
            array[i] = array[i] * 3;
            array[i] = array[i] / 10;
            array[i] = fmod(array[i], 1);
            array[i] = array[i] * 10;
        }

        int product = (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1] + 1;
        return product;
    }

    //Rule set for a six digit number.
    else if (inputLength == 6) {
        double array[inputLength];

        array[1] = input % 10;
        array[2] = (input / 10) % 10;
        array[3] = (input / 100) % 10;
        array[4] = (input / 1000) % 10;
        array[5] = (input / 10000) % 10;
        array[6] = (input / 100000) % 10;

        for (int i = inputLength; i >= 1; i--) {
            array[i] = array[i] * 3;
            array[i] = array[i] / 10;
            array[i] = fmod(array[i], 1);
            array[i] = array[i] * 10;
        }
        int product = (array[6] * 100000) + (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1] + 1;
        return product;
    }

    //Rule set for a seven digit number.
    else if (inputLength == 7) {
        double array[inputLength];

        array[1] = input % 10;
        array[2] = (input / 10) % 10;
        array[3] = (input / 100) % 10;
        array[4] = (input / 1000) % 10;
        array[5] = (input / 10000) % 10;
        array[6] = (input / 100000) % 10;
        array[7] = (input / 1000000);

        for (int i = inputLength; i >= 1; i--) {
            array[i] = array[i] * 3;
            array[i] = array[i] / 10;
            array[i] = fmod(array[i], 1);
            array[i] = array[i] * 10;
        }

        int product = (array[7] * 1000000) + (array[6] * 100000) + (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1] + 1;
        return product;
    }

    //Rule set for a eight digit number.
    else if (inputLength == 8) {
        double array[inputLength];

        array[1] = input % 10;
        array[2] = (input / 10) % 10;
        array[3] = (input / 100) % 10;
        array[4] = (input / 1000) % 10;
        array[5] = (input / 10000) % 10;
        array[6] = (input / 100000) % 10;
        array[7] = (input / 1000000) % 10;
        array[8] = (input / 10000000);

        for (int i = inputLength; i >= 1; i--) {
            array[i] = array[i] * 3;
            array[i] = array[i] / 10;
            array[i] = fmod(array[i], 1);
            array[i] = array[i] * 10;
        }
        int product = (array[8] * 10000000) + (array[7] * 1000000) + (array[6] * 100000) + (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1] + 1;

        cout << "Do you want a second level of encryption, (yes or no)?";
        cin >> secondEncryption;

        if (secondEncryption == "yes") {
            int product = (array[1] * 10000000) + (array[2] * 1000000) + (array[3] * 100000) + (array[4] * 10000) + (array[5] * 1000) + (array[6] * 100) + (array[7] * 10) + array[8] + 1;
            return product;
        }
        else {
            return product;

        }
    }
}

int decode(int encrypted) {
    // Convert input Number into String for validation
    string input_string;
    ostringstream convert;
    convert << encrypted;
    input_string = convert.str();

    int inputLength = input_string.length();

    // Decoding Rules set for a 2 digit number
    if (inputLength == 2) {
        int first_digit = encrypted / 10;
        int second_digit = encrypted % 10;
        int swapped_number = (second_digit * 10) + first_digit;
        return swapped_number;
    }

    // Decoding Rule set for a 3 digit number
    if (inputLength == 3) {
        int last_digit = encrypted % 10;
        int middle_digit = (encrypted / 10) % 10;
        int first_digit = encrypted / 100;

        int swapped_number = (last_digit * 100) + (middle_digit * 10) + first_digit;
        return swapped_number;
    }

    // Decoding Rule set for a 4 digit number
    if (inputLength == 4) {
        int array[inputLength];

        array[1] = encrypted % 10;
        array[2] = (encrypted / 10) % 10;
        array[3] = (encrypted / 100) % 10;
        array[4] = encrypted / 1000;

        for (int i = inputLength; i >= 1; i--) {
            if (array[i] == 3 || array[i] == 6 || array[i] == 9) {
                array[i] = array[i] / 3;
            }
            else if (array[i] == 2 || array[i] == 5 || array[i] == 8) {
                array[i] = array[i] + 10;
                array[i] = array[i] / 3;
            }
            else if (array[i] == 1 || array[i] == 4 || array[i] == 7) {
                array[i] = array[i] + 20;
                array[i] = array[i] / 3;
            }
        }
        int product = (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1];
        return product;
    }

    // Decoding Rule set for a 5 digit number
    else if (inputLength == 5) {
        int array[inputLength];

        array[1] = encrypted % 10;
        array[2] = (encrypted / 10) % 10;
        array[3] = (encrypted / 100) % 10;
        array[4] = (encrypted / 1000) % 10;
        array[5] = (encrypted / 10000) % 10;

        for (int i = inputLength; i >= 1; i--) {
            if (array[i] == 3 || array[i] == 6 || array[i] == 9) {
                array[i] = array[i] / 3;
            }
            else if (array[i] == 2 || array[i] == 5 || array[i] == 8) {
                array[i] = array[i] + 10;
                array[i] = array[i] / 3;
            }
            else if (array[i] == 1 || array[i] == 4 || array[i] == 7) {
                array[i] = array[i] + 20;
                array[i] = array[i] / 3;
            }
        }
        int product = (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1];
        return product;
    }

    // Decoding Rule set for a 6 digit number
    else if (inputLength == 6) {
        int array[inputLength];

        array[1] = encrypted % 10;
        array[2] = (encrypted / 10) % 10;
        array[3] = (encrypted / 100) % 10;
        array[4] = (encrypted / 1000) % 10;
        array[5] = (encrypted / 10000) % 10;
        array[6] = (encrypted / 100000) % 10;

         for (int i = inputLength; i >= 1; i--) {
            if (array[i] == 3 || array[i] == 6 || array[i] == 9) {
                array[i] = array[i] / 3;
            }
            else if (array[i] == 2 || array[i] == 5 || array[i] == 8) {
                array[i] = array[i] + 10;
                array[i] = array[i] / 3;
            }
            else if (array[i] == 1 || array[i] == 4 || array[i] == 7) {
                array[i] = array[i] + 20;
                array[i] = array[i] / 3;
            }
        }
        int product = (array[6] * 100000) + (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1];
        return product;
    }

    // Decoding Rule set for a 7 digit number
    else if (inputLength == 7) {
        int array[inputLength];

        array[1] = encrypted % 10;
        array[2] = (encrypted / 10) % 10;
        array[3] = (encrypted / 100) % 10;
        array[4] = (encrypted / 1000) % 10;
        array[5] = (encrypted / 10000) % 10;
        array[6] = (encrypted / 100000) % 10;
        array[7] = (encrypted / 1000000);

        for (int i = inputLength; i >= 1; i--) {
            if (array[i] == 3 || array[i] == 6 || array[i] == 9) {
                array[i] = array[i] / 3;
            }
            else if (array[i] == 2 || array[i] == 5 || array[i] == 8) {
                array[i] = array[i] + 10;
                array[i] = array[i] / 3;
            }
            else if (array[i] == 1 || array[i] == 4 || array[i] == 7) {
                array[i] = array[i] + 20;
                array[i] = array[i] / 3;
            }
        }
        int product = (array[7] * 1000000) + (array[6] * 100000) + (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1];
        return product;
    }

    // Decoding Rule set for a 8 digit number
    else if (inputLength == 8) {
        string secondDecode;
        int array[inputLength];

        array[1] = encrypted % 10;
        array[2] = (encrypted / 10) % 10;
        array[3] = (encrypted / 100) % 10;
        array[4] = (encrypted / 1000) % 10;
        array[5] = (encrypted / 10000) % 10;
        array[6] = (encrypted / 100000) % 10;
        array[7] = (encrypted / 1000000) % 10;
        array[8] = (encrypted / 10000000);

        for (int i = inputLength; i >= 1; i--) {
            if (array[i] == 3 || array[i] == 6 || array[i] == 9) {
                array[i] = array[i] / 3;
            }
            else if (array[i] == 2 || array[i] == 5 || array[i] == 8) {
                array[i] = array[i] + 10;
                array[i] = array[i] / 3;
            }
            else if (array[i] == 1 || array[i] == 4 || array[i] == 7) {
                array[i] = array[i] + 20;
                array[i] = array[i] / 3;
            }
        }

        // If not used a second level of incoding impliment the following decoding rule set
        int product = (array[8] * 10000000) + (array[7] * 1000000) + (array[6] * 100000) + (array[5] * 10000) + (array[4] * 1000) + (array[3] * 100) + (array[2] * 10) + array[1];
        // If used second level decoding impliment the following decoding rule set
         if (secondEncryption == "yes") {
            int product = (array[1] * 10000000) + (array[2] * 1000000) + (array[3] * 100000) + (array[4] * 10000) + (array[5] * 1000) + (array[6] * 100) + (array[7] * 10) + array[8];
            return product;
        }
        else {
            return product;
        }
    }
}

int main()
{
    // Title only shown once at start of program
    cout << "Assignment 1: Number Encrypter" << endl;

    //Function that takes user input and outputs into the variable that is passed on to the modification ruleset.
    int input = numberInput();

    // Function that takes user input and encrypts the data based on the amount of digits in the users input
    int encrypted = modify(input);

    // Function that takes the encrypted number and decodes it based on the length of digit
    int decodeNumber = decode(encrypted);

    // Output both the encoded and decoded values as well as a blank line to format the programs output (so the user can read it better)
    cout << "" << endl;
    cout << "Encrypted Number: " << encrypted << endl;
    cout << "Orignal Number: " << decodeNumber << endl;

    return 0;
}
