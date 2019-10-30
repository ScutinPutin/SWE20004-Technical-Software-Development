#include <iostream>

using namespace std;

int main()
{
    int a;

    for (int i = 0; i < 5; i++) {
        cout << "Please enter an integer between 0 to 100 to find out the pollution index" << endl;
        cin >> a;

        if (a < 35) {
            cout << "Pleasent" << endl;
        }
        else if (a < 60) {
            cout << "Unpleasent" << endl;
        }
        else {
            cout << "Hazard" << endl;
        }
    }
    return 0;
}
