#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <clocale>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    cout << "Enter 20 alphabets" << endl;
    int i,k,j,x, check;
    bool z = true;
    unsigned char array[20];
    for (i=0; i < 20; i++) {
        check = 0;
        cin >> array[i];

        if (!(bool)std::isalpha(array[i])) {
            while (z) {
                cout << array[i] << "Is not a letter" << endl;
                cin >> array[i];
                if ((bool)std::isalpha(array[i])) {
                    z = false;
                }
            }
        }

        for (k=0; k < i; k++) {
            if (array[i] == array[k])
            check = 1;
        }
        if (check == 1) {
        cout << array[i] << " is a duplicate letter" << endl;
        }
    }
    cout << "" << endl;
    cout << "The Original array is: " << endl;
    for (j=0; j < 20; j++) {
        cout << array[j];
    }

    cout << "" << endl;
    cout << "The Sorted array is: " << endl;
    int n = sizeof(array)/sizeof(array[0]);
    sort(array, array+n);
    for (x=0; x < 20; x++) {
        cout << array[x];
    }

    return 0;
}
