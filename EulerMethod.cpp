#include <iostream>
#include <cmath>

using namespace std;

double f_xy(double x, double y) {
	return log(x)+y;
}

double RK(double h,double xp,double xk, double y0) {

	double N = (xk - xp) / h; //liczba krokow
	
	double x = xp;
	double y = y0;
	double F;
	
	for (int i = 0; i <= N; i++) {
		
		F = f_xy(x, y);
		y += h * F;
		x += h;
	}

	return y;
}

int main() {

	double h;
	double xp, xk;
	double y0;
	
	cout << "Podaj:" << endl << " h - ";
	cin >> h;
	cout << endl << " przedzial - ";
	cin >> xp >> xk;
	cout << endl << " warunek poczatkowy - y(0)=";
	cin >> y0;
	cout << endl;

	double y = RK(h, xp, xk, y0);
	cout << endl << "Rozwiazanie: " << endl << " y = " << y << endl;

	return 0;
}