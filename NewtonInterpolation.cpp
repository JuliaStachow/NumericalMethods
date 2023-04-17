#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	int i, j;
	int n;
	cout << "Podaj ilosc znanych wezlow: ";
	cin >> n;
	cout << endl;

	double* wspolrzedne_x = new double[n];
	double* wspolrzedne_y = new double[n];

	for (i = 0; i < n; i++) {
		cout << "Podaj wspolrzedna x dla " << i + 1 << ". punktu: ";
		cin >> wspolrzedne_x[i];
		cout << endl;
		cout << "Podaj wspolrzedna y dla " << i + 1 << ". punktu: ";
		cin >> wspolrzedne_y[i];
		cout << endl;
	}

	double x;
	cout << "Podaj wartosc x, dla ktorej chcesz wyznaczyc wartosc: ";
	cin >> x;
	cout << endl;

	double pom;
	double y = 0;

	for (j = 0; j < n - 1; j++)
	{
		for (i = n - 1; i > j; i--)
			wspolrzedne_y[i] = (wspolrzedne_y[i] - wspolrzedne_y[i - 1]) / (wspolrzedne_x[i] - wspolrzedne_x[i - j - 1]);
	}

	/*for (i = 0; i < n; i++) {
		cout << wspolrzedne_y[i] << endl;
	}*/

	for (i = n - 1; i >= 0; i--)
	{
		pom = 1;
		for (j = 0; j < i; j++)
			pom *= (x - wspolrzedne_x[j]);
		
		pom *= wspolrzedne_y[j];
		y += pom;
	}
	cout << "Wartosc dla podanego x wynosi: " << y;

	return 0;
}