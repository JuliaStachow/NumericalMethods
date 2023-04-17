#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <time.h>
using namespace std;

double f(double x) {
	return x*x*x+2;
}

int main() {

	int n;
	double x_p, x_k;
	cout << "Podaj przedzial calkowania: " << endl;
	cin >> x_p >> x_k;
	cout << endl << "Metoda Simpsona: " << endl;
	cout << "Podaj na ile czesci chcesz podzielic obszar calkowania: " << endl;
	cin >> n;

	double h = (x_k - x_p) / n;
	//cout << h << endl;
	double* punktyS = new double[n + 1];
	
	for (int i = 0; i < n+1; i++) {
		punktyS[i] = x_p + i*h;
		//cout << punktyS[i] << endl;
	}
	
	double wynik_s=0;
	for (int i = 0; i < n/2; i++) {
		wynik_s += (f(punktyS[2*i]) + 4 * f(punktyS[2*i + 1]) + f(punktyS[2*i + 2])) * (h / 3);
	}
	cout << "Wynik calki metoda Simpsona: " << wynik_s << endl << endl;

	int k;
	cout << "Metoda Monte Carlo" << endl << "Podaj ilosc losowych punktow: " << endl;
	cin >> k;

	double* punktyMC = new double[k];
	cout << "Podaj punkty" << endl;
	for(int i=0;i<k;i++) {
		cin >> punktyMC[i];
	}

	double f_sr = 0;
	for (int j = 0; j < k; j++) {
		f_sr += f(punktyMC[j]) / k;
	}

	double wartosc_bw = x_k - x_p;
	if (wartosc_bw < 0) {
		wartosc_bw *= -1;
	}

	double wynik_MC = f_sr * wartosc_bw;
	cout << "Wartosc calki metoda Monte Carlo: " << wynik_MC << endl;

	return 0;
}