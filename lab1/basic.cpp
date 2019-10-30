#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float a, b;
	float m, x, y, z;

	cout << "Input two Numbers" << endl;
	cin >> a;
	cin >> b;

	x = a + b;
	y = a - b;
	z = a * b;
	m = a / b;

	cout << "The sum  is " << x << endl;
	cout << "The subtraction is " << y << endl;
	cout << "The multiplication is " << z << endl;
	cout << "The Division is " << m << endl;

	return 0;
}