#include <iostream>
#include <cmath>

using namespace std;

double f_xy(double x, double y) {
	return sin(2*x)+cos(2*x);
}

double f_xy4(double x, double y) {
	return sin(2 * x) + cos(2 * x);
}

double RK2(double h,double xp, double xk, double y0) {

	double N = (xk - xp) / h;
	double x = xp;
	double y = y0;
	double F1;
	double F2;
	
	for (int i = 0; i < N; i++) {
		F1 = f_xy(x, y);
		F2 = f_xy(x + h, y + h * F1);
		y += (h / 2) *(F1+F2);
		x += h;
	}
	
	return y;
}

double RK4(double h, double xp, double xk, double y0) {
	
	double N = (xk - xp) / h;
	double x = xp;
	double y = y0;
	double k1, k2, k3, k4;

	for (int i=0; i <N; i++) {
		k1 = h * f_xy4(x, y);
		k2 = h * f_xy4(x + h / 2, y + k1 / 2);
		k3 = h * f_xy4(x + h / 2, y + k2 / 2);
		k4 = h * f_xy4(x + h, y + k3);

		y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		x += h;
	}

	return y;
}

int main() {

	double h, xp, xk, y0;

	cout << "METODA R-K-2:\nPodaj: " << endl << " h - ";
	cin >> h;
	cout << endl << " przedzial - ";
	cin >> xp >> xk;
	cout << endl << " warunek poczatkowy - y(0)=";
	cin >> y0;

	double rozw_RK2 = RK2(h, xp, xk, y0);

	cout << "\nRozwiazanie: y = " << rozw_RK2;

	cout << "\n\nMETODA R-K-4:\nPodaj: " << endl << " h - ";
	cin >> h;
	cout << endl << " przedzial - ";
	cin >> xp >> xk;
	cout << endl << " warunek poczatkowy - y(0)=";
	cin >> y0;

	double rozw_RK4 = RK4(h, xp, xk, y0);

	cout << "\nRozwiazanie: y = " << rozw_RK4 << endl;


	return 0;
}