#include <muParser.h>
#include <vector>
using namespace std;

double fun(string& fun, double x) {
	mu::Parser parser;
	parser.SetExpr(fun);
	parser.DefineVar("x", &x);
	return parser.Eval();
}

vector<double> getX(double a, double b, double n) {
	vector<double> X;
	n += 1;
	if (n == 1) { X.push_back(a); X.push_back(b); }
	else {
		double it = (b - a) / (n - 1);
		for (double i = a; i <= b; i += it) {
			X.push_back(i);
		}
	}
	return X;
}

struct graphic {
	vector<double> x;
	vector<double> y;
	string name;
};