#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float PI = 3.14159;

    float f, r, c, l, e, i;
    float a1, a2, a3, a4, a5, a6, a7;
    // i = e / (sqrt(pow(r, 2.0)) + pow(2 * PI * f * l - 1 / (2* PI * f * c), 2));

   // cout << "Please input the values for E, R, F, L, C" << endl;
   //     cin >> e >> r >> f >> l >> c;
    cout << "Input for Electromotive Force in Volts (E):" << endl;
    cin >> e;

    cout << "Resistance in Ohms (R):" << endl;
    cin >> r;

    cout << "Frequency of the Current in Hertz (F):" << endl;
    cin >> f;

    cout << "Indutance in Henrys (L):" << endl;
    cin >> l;

    cout << "Capacitance in Farads (C):" << endl;
    cin >> c;

    a1 = pow(r, 2);
    a2 = (2 * PI * f * l);
    a3 = 1 / (2 * PI * f * c);
    a4 = a2 - a3;
    a5 = pow(a4, 2);
    a6 = a1 + a5;
    a7 = sqrt(a6);
    i = e / a7;


    cout << "The Current in Amps is " << i << "A" << endl;
    return 0;
}
