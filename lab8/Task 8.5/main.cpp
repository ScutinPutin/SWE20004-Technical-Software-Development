/*
    Filename: Task 8.5.cpp
    Purpose: Reading and Writing File Data
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 30/10/2019
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int loopCount, lineNumber;
    ifstream myfile;

        myfile.open("price.dat");
        myfile >> loopCount;

        float data[10];
        float maximum = 0;
        float minimum = 1000;
        float total = 0;

        for (int i = 0; i < loopCount; i++) {
            myfile >> lineNumber >> data[i];
            cout << data[i] << endl;
        }
        myfile.close();

        for (int i = 0; i < loopCount; i++) {
            total = data[i] + total;

            if (data[i] > maximum) {
                maximum = data[i];
            }
            if (data[i] < minimum) {
                minimum = data[i];
            }
        }

    ofstream outputFile ("output.dat");
        if (outputFile.is_open()) {
           outputFile << "Number of price readings: " << loopCount << endl;
           outputFile << "Maximum Price: " << maximum << endl;
           outputFile << "Minimum Price: " << minimum << endl;
           outputFile << "Average Price: " << total/loopCount << endl;
        }

    return 0;
}
