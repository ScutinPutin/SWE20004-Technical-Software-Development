#include <iostream>

using namespace std;

void reOrder(int *a, int *b, int *c) {
    cout << "Current List: " << a << ", " << b << ", " << c << endl;
}

int main()
{
    int a = 50;
    int b = 72;
    int c = 44;

    reOrder(a,*b, *c);
    return 0;
}
