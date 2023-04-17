#include <iostream>
#include <fstream>

using namespace std;

int main() {

	int n;
	ifstream odczyt("daneEG.txt");
	odczyt >> n;

	double ** AB = new double * [n];
	double* X = new double[n];
	
	for (int i = 0; i < n; i++) {
		AB[i] = new double[n+1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			odczyt >> AB[i][j];
		}
	}

	cout << endl << "Macierz rozszerzona AB: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			cout << AB[i][j] << " ";
		}
		cout << endl;
	}

	int i, j, k;
	double m, s;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (AB[i][i] == 0) {
				cout << "BLAD: DZIELENIE PRZEZ ZERO" << endl;
				return 0;
			}
			else
				m = -AB[j][i] / AB[i][i];
			for (k = i + 1; k < n + 1; k++) {
				AB[j][k] += m * AB[i][k];
			}
		}
	}

	for (i = n - 1; i >= 0; i--) {
		s = AB[i][n];
		for (j = n - 1; j >= i + 1; j--) {
			s -= AB[i][j] * X[j];
		}
		if (AB[i][i] == 0) {
			cout << "BLAD: DZIELENIE PRZEZ ZERO" << endl;
			return 0;
		}
		else
		X[i] = s / AB[i][i];
	}
	
	cout << endl << "Rozwiazania: " << endl;
	for (i = 0; i < n; i++) {
		cout << "x" << i+1 << " = " << X[i] << endl;
	}

	delete[] AB;
	delete[] X;

	return 0;
}