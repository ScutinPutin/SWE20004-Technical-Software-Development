#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float f, n, v;
    float a1, a2, a3;
    cout << "The frequency in Hz (f):" << endl;
    cin >> f;

    cout << "The number of stages in the ampifier (n):" << endl;
    cin >> n;

    a1 = pow(23, 2.0) + (0.5 * pow(f, 2.0));
    a2 = sqrt(a1);
    a3 = 275 / a2;
    v = pow(a3, n);

    cout << "At a frquency of " << f << " hertz, the voltage gain is " << v << endl;

    return 0;
}
