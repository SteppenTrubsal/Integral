#include "methods.hpp"
#include <iostream>
using namespace std;

int main() {
	/*double a, b;
	cout << "Enter integration limits (through enter): ";
	cin >> a >> b;
	*/
	double a = 0, b = 10, n = 3;
	string func;
	cout << "Enter an equation(without dx): ";
	getline(cin, func);

	cout << leftRectangle(getX(a, b, n), func) << endl;
	cout << rightRectangle(getX(a, b, n), func) << endl;
	cout << centralRectangle(getX(a, b, n), func) << endl;
	cout << trapezoid(getX(a, b, n), func) << endl;
	cout << poraboloid(getX(a, b, n), func) << endl;
}