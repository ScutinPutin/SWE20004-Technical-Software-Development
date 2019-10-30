#include <iostream>

using namespace std;

int main()
{
    string Name;
    int greetingsCount;
    cout << "Type in your name" << endl;
    cin >> Name;

    cout << "How many greetings?" << endl;
    cin >> greetingsCount;

    for (int i = 0; i < greetingsCount; i++){
        cout << "Welcome to my world!" << endl;
    }

    return 0;
}
