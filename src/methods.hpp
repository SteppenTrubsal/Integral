#include "someFunc.hpp"

double leftRectangle(vector<double>& n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += fun(func, n[i]) * (n[i + 1] - n[i]);
	}
	return sum;
}
double rightRectangle(vector<double>& n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += fun(func, n[i+1]) * (n[i + 1] - n[i]);
	}
	return sum;
}
double centralRectangle(vector<double>& n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += fun(func, (n[i+1] + n[i])/2) * (n[i + 1] - n[i]);
	}
	return sum;
}

double trapezoid(vector<double>& n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += ((fun(func, n[i])+fun(func,n[i+1]))/2) * (n[i + 1] - n[i]);
	}
	return sum;
}
double poraboloid(vector<double>& n, string func) {
	double sum = 0;
	for (int i = 0; i < n.size() - 1; i++) {
		sum += (fun(func,n[i]) + fun(func, ((n[i+1]+n[i]) / 2)) + fun(func,n[i+1])) * (n[i + 1] - n[i]);
	}
	return sum/3;			//why 3 ?

	//HZ, rabotaet ved 
}

vector<graphic> getRes(double a, double b, string func, double preciseMeaning, int num) {
	vector<graphic> res(5);
	
	res[0].name = "Method of left rectangles";
	res[1].name = "Method of right rectangles";
	res[2].name = "Method of central rectangles";
	res[3].name = "Method of trapezoid";
	res[4].name = "Method of paraboloid";

	for (int i = 2; i < num; i++) {
		vector<double> X = getX(a, b, i);
		for (int j = 0; j < 5; j++) {
			res[j].x.push_back(i);
		}
		double lR = leftRectangle(X, func);
		double di = lR - preciseMeaning;
		double ab = abs(di);
		res[0].y.push_back(abs(leftRectangle(X, func) - preciseMeaning));
		res[1].y.push_back(abs(rightRectangle(X, func) - preciseMeaning));
		res[2].y.push_back(abs(centralRectangle(X, func) - preciseMeaning));
		res[3].y.push_back(abs(trapezoid(X, func) - preciseMeaning));
		res[4].y.push_back(abs(poraboloid(X, func) - preciseMeaning));
	}

	return res;
}