/*
    Filename: Task2.11.cpp
    Purpose: Task 2.11 Voltage Gain Calulcator
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 6/09/2019
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Declaring Variables
    float f, n, v;
    float a1, a2, a3;

    // Getting user input for vairables
    cout << "The frequency in Hz (f):" << endl;
    cin >> f;

    cout << "The number of stages in the ampifier (n):" << endl;
    cin >> n;

    // Using formula to caluclate voltage gain
    a1 = pow(23, 2.0) + (0.5 * pow(f, 2.0));
    a2 = sqrt(a1);
    a3 = 275 / a2;
    v = pow(a3, n);

    // Outputting calulcated product
    cout << "At a frquency of " << f << " hertz, the voltage gain is " << v << endl;

    return 0;
}
