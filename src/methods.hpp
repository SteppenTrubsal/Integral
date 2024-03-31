#include "someFunc.hpp"

double leftRectangle(vector<double> n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += fun(func, n[i]) * (n[i + 1] - n[i]);
	}
	return sum;
}
double rightRectangle(vector<double> n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += fun(func, n[i+1]) * (n[i + 1] - n[i]);
	}
	return sum;
}
double centralRectangle(vector<double> n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += fun(func, (n[i+1] + n[i])/2) * (n[i + 1] - n[i]);
	}
	return sum;
}

double trapezoid(vector<double> n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += ((fun(func, n[i])+fun(func,n[i+1]))/2) * (n[i + 1] - n[i]);
	}
	return sum;
}
double poraboloid(vector<double> n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += (fun(func,n[i]) + fun(func, ((n[i+1]+n[i]) / 2)) + fun(func,n[i+1])) * (n[i + 1] - n[i]);
	}
	return sum/3;			//why 3 ?
}

