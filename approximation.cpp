#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double a1(int n,double*x_wsp,double*y_wsp) {
	double suma_xy = 0;
	double suma_x = 0;
	double suma_y = 0;
	double suma_xx = 0;
	for (int i = 0; i < n; i++) {
		suma_xy += x_wsp[i] * y_wsp[i];
		suma_x += x_wsp[i];
		suma_y += y_wsp[i];
		suma_xx += x_wsp[i] * x_wsp[i];
	}
	double a1 = (n * suma_xy - suma_x * suma_y) / (n * suma_xx - suma_x * suma_x);
	return a1;
}

double a0(int n, double* x_wsp, double* y_wsp) {
	double suma_xy = 0;
	double suma_x = 0;
	double suma_y = 0;
	double suma_xx = 0;
	for (int i = 0; i < n; i++) {
		suma_xy += x_wsp[i] * y_wsp[i];
		suma_x += x_wsp[i];
		suma_y += y_wsp[i];
		suma_xx += x_wsp[i] * x_wsp[i];
	}
	double a0 = (suma_y * suma_xx - suma_x * suma_xy) / (n * suma_xx - suma_x * suma_x);
	return a0;
}

double korelacja(int n, double* x_wsp, double* y_wsp) {
	double suma_xy = 0;
	double suma_x = 0;
	double suma_y = 0;
	double suma_xx = 0;
	double suma_yy = 0;
	for (int i = 0; i < n; i++) {
		suma_xy += x_wsp[i] * y_wsp[i];
		suma_x += x_wsp[i];
		suma_y += y_wsp[i];
		suma_xx += x_wsp[i] * x_wsp[i];
		suma_yy += y_wsp[i] * y_wsp[i];
	}
	//cout << suma_xy << endl << suma_x << endl << suma_y << endl << suma_xx << endl << suma_yy << endl;
	double R = (n * suma_xy - suma_x * suma_y) / (sqrt(n * suma_xx - suma_x * suma_x) * sqrt(n * suma_yy - suma_y * suma_y));
	return R;
}

int main() {

	int n;
	ifstream odczyt("dane.txt");
	odczyt >> n;
	
	double* x_wsp = new double [n];
	double* y_wsp = new double[n];

	for (int i = 0; i < n; i++) {

		odczyt >> x_wsp[i];
		odczyt >> y_wsp[i];
	}
	
	double A1 = a1(n, x_wsp, y_wsp);
	double A0 = a0(n, x_wsp, y_wsp);
	double R = korelacja(n, x_wsp, y_wsp);
	cout << "Ilosc punktow doswiadczalnych wynosi: " << n << endl;
	cout << "Funkcja aproksymujaca: y = " << A0 << " + " << A1 << "x" << endl;
	cout << "Wspolczynnik korelacji wynosi: " << R << endl;

	return 0;
}