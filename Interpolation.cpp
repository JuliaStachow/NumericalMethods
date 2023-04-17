#include <iostream>

using namespace std;

int main() {

	int n;

	cout << "Podaj liczbe znanych punktow: ";
	cin >> n;
	cout << endl;

	double* wspolrzedne_x = new double[n];
	double* wspolrzedne_y = new double[n];

	for (int i = 0; i < n; i++) {
		cout << "Podaj wspolrzedna x dla " << i+1 << ". punktu: ";
		cin >> wspolrzedne_x[i];
		cout << endl << "Podaj wspolrzedne y dla " << i + 1 << ". punktu: ";
		cin >> wspolrzedne_y[i];
		cout << endl;
	}
	
	double x_l;
	cout << "Podaj wspolrzedna x, dla ktorej chcesz wyznaczyc wartosc: ";
	cin >> x_l;
	cout << endl;

	double* wielomiany = new double[n];

	for (int i = 0; i < n; i++) {
		wielomiany[i] = wspolrzedne_y[i];
		for (int j = 0; j < n; j++) {
			if (wspolrzedne_x[i] != wspolrzedne_x[j])
			{
				wielomiany[i] *= (x_l - wspolrzedne_x[j]);
			}
		}
		for (int j = 0; j < n; j++) {
			if (wspolrzedne_x[i] != wspolrzedne_x[j])
			{
				wielomiany[i] /= (wspolrzedne_x[i] - wspolrzedne_x[j]);
			}
		}
	}

	double y_l = 0;
		for (int i = 0; i < n; i++) {
			y_l +=wielomiany[i];
		}

	cout << "Wartosc dla podanego x wynosi: " << y_l << endl;
	
	delete [] wspolrzedne_x;
	delete [] wspolrzedne_y;
	delete [] wielomiany;

	return 0;
}