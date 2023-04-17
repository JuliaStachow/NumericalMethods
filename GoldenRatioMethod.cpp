#include <iostream>

using namespace std;

double f(double x) {
	return x*x*x+2*x*x-3*x+10;
}

int main() {

	double zlota_liczba = 0.61803398;
	double dokladnosc = 0.001;
	double a, b;
	cout << "Podaj poczatek i koniec przedzialu: " << endl;
	cin >> a >> b;
	cout << endl;

	double x_l = b - zlota_liczba * (b - a);
	double x_p = a + zlota_liczba * (b - a);

	while ((b - a) > dokladnosc) {
		if (f(x_l) > f(x_p)) {
			a = x_l;
			x_l = x_p;
			x_p = a + zlota_liczba * (b - a);
		}
		else {
			b = x_p;
			x_p = x_l;
			x_l = b - zlota_liczba * (b - a);
		}
	}

	cout << "Minimum znajduje sie w przedziale <" << a << "," << b << ">" << endl;

	return 0;
}