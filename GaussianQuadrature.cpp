#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

double pole1(double x[], double y[]) {
	double ax, bx, cx, ay, by, cy;
	ax = x[0];
	bx = x[1];
	cx = x[3];
	ay = y[0];
	by = y[1];
	cy = y[3];
	double p1 = (fabs((bx - ax) * (cy - ay) - (by - ay) * (cx - ax))) / 2;
	return p1;
}
double pole2(double x[], double y[]) {
	double ax, bx, cx, ay, by, cy;
	ax = x[1];
	bx = x[2];
	cx = x[3];
	ay = y[1];
	by = y[2];
	cy = y[3];
	double p2 = (fabs((bx - ax) * (cy - ay) - (by - ay) * (cx - ax))) / 2;
	return p2;
}

int main() {

	ifstream odczyt("punkty.txt");

	double wsp_x[4];
	double wsp_y[4];

	for (int i = 0; i < 4; i++) {
		odczyt >> wsp_x[i] >> wsp_y[i];
	}

	double punkty[2] = {-0.5773502692,0.5773502692};
	int wagi[2] = { 1,1 };

	double f_ksztaltu[2][2][4];
	double poch_ksi[2][4];
	double poch_ni[2][4];

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			f_ksztaltu[i][j][0] = 0.25 * (1 - punkty[i]) * (1 - punkty[j]);
			f_ksztaltu[i][j][1] = 0.25 * (1 + punkty[i]) * (1 - punkty[j]);
			f_ksztaltu[i][j][2] = 0.25 * (1 + punkty[i]) * (1 + punkty[j]);
			f_ksztaltu[i][j][3] = 0.25 * (1 - punkty[i]) * (1 + punkty[j]);

			poch_ksi[j][0] = -0.25 * (1 - punkty[j]);
			poch_ksi[j][1] = 0.25 * (1 - punkty[j]);
			poch_ksi[j][2] = 0.25 * (1 + punkty[j]);
			poch_ksi[j][3] = -0.25 * (1 + punkty[j]);
			poch_ni[i][0] = -0.25 * (1 - punkty[i]);
			poch_ni[i][1] = -0.25 * (1 + punkty[i]);
			poch_ni[i][2] = 0.25 * (1 + punkty[i]);
			poch_ni[i][3] = 0.25 * (1 - punkty[i]);

		}
	}
	
	double dxdKSI = 0;
	double dxdNI = 0;
	double dydKSI = 0;
	double dydNI = 0;
	double fun_detJ[2][2];

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			dxdKSI = poch_ksi[j][0] * wsp_x[0] + poch_ksi[j][1] * wsp_x[1] + poch_ksi[j][2] * wsp_x[2] + poch_ksi[j][3] * wsp_x[3];
			dydKSI = poch_ksi[j][0] * wsp_y[0] + poch_ksi[j][1] * wsp_y[1] + poch_ksi[j][2] * wsp_y[2] + poch_ksi[j][3] * wsp_y[3];
			dxdNI = poch_ni[i][0] * wsp_x[0] + poch_ni[i][1] * wsp_x[1] + poch_ni[i][2] * wsp_x[2] + poch_ni[i][3] * wsp_x[3];
			dydNI = poch_ni[i][0] * wsp_y[0] + poch_ni[i][1] * wsp_y[1] + poch_ni[i][2] * wsp_y[2] + poch_ni[i][3] * wsp_y[3];

			fun_detJ[i][j] = dxdKSI * dydNI - dxdNI * dydKSI;
		}
	}

	double surface = 0;

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			surface = surface + fabs(fun_detJ[i][j]) * wagi[i] * wagi[j];
		}
	}

	cout << "Powierzchnia wynosi " << surface << endl;

	double p1 = pole1(wsp_x, wsp_y);
	double p2 = pole2(wsp_x, wsp_y);

	cout << endl << endl << "SPRAWDZENIE:  " << endl << "Powierzchnia wynosi " << p1 + p2 << endl;

	return 0;
}