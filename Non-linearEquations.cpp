#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

double f(double x) {
	return x*x*x+2;
}
double F(double x) {
	return x*x*x+2;
}
double FP(double x) {
	return 3*x*x;
}

double bisekcja(double a, double b, double dokladnosc) {

	double x1 = (a + b) / 2;
	double f1 = f(x1);
	double fa = f(a);
	double fb = f(b);

	if (f(x1) == 0) {
		cout << "Rozwiazaniem rownania jest: " << (a + b) / 2 << endl;
	}
	else {
		while (fabs(a-b) > dokladnosc) {

			x1 = (a + b) / 2;
			f1 = f(x1);

			if (fa * f1 < 0) {
				b = x1;
			}
			else {
				a = x1;
				fa = f1;
			}
		}
	}
	return (a+b)/2;
}

double NR(double X0, double EPS) {
	
	double H = F(X0) / FP(X0);
	double X1 = X0 - H;

	while (fabs(X1 - X0) > EPS) {
		X0 = X1;
		H = F(X1) / FP(X1);
		X1 = X0 - H;
	}

	return X1;
}

int main() {

	double a, b;
	double dokladnosc;
	cout << "METODA BISEKCJI" << endl << "Podaj przedzial: ";
	cin >> a >> b;
	cout << endl << "Podaj dokladnosc: ";
	cin >> dokladnosc;
	cout << endl;
	double rozw = bisekcja(a, b, dokladnosc);
	cout << "Rozwiazaniem rownania jest: " << rozw << endl;
	
	double X0;
	double EPS;
	cout << "\n\nMETODA N-R\n" << endl << "Podaj punkt startowy: ";
	cin >> X0;
	cout << endl << "Podaj dokladnosc: ";
	cin >> EPS;
	cout << endl;

	double X1 = NR(X0,EPS);
	cout << "Rozwiazaniem jest: " << X1 << endl;

	return 0;
}