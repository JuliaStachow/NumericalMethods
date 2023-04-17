#include <iostream>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <math.h>

using namespace std;

double f(double x) {
	return sqrt(x)-4;
}

int main() {

	int n;
	double x_p, x_k;
	cout << "Podaj przedzial calkowania: " << endl;
	cin >> x_p >> x_k;
	cout << "Podaj na ile czesci chcesz podzielic obszar calkowania: " << endl;
	cin >> n;

	double dx = (x_k - x_p) / n;
	//cout << dx << endl;
	double wynik_p=0;

	for (int i = 1; i < n+1; i++) {
		wynik_p += dx * f(x_p + i * dx);
		//cout << wynik_p << endl;
	}
	
	cout << "Wynik uzyskany metoda prostokatow: " << wynik_p << endl;

	double wynik_t=0;

	for (int i = 0; i < n; i++) {
		int j = i + 1;
		wynik_t += dx * (f(x_p+i*dx)+f(x_p + j* dx))/2;
		//cout << wynik_t << endl;
	}

	cout << "Wynik uzyskany metoda trapezow: " << wynik_t;

	return 0;
}