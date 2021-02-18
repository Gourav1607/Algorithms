/*
 *  Bezier Curve / Bezier Curve
 *  15 - Nov - 2016
 *  Author : Gourav Siddhad
 */

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "graphics.h"
#include "math.h"

void bezier(int[], int[]);

int main() {
	int x[4], y[4];
	int i;

	cout << "\n Enter the X, Y co-ordinates of the four control points : ";
	for (i = 0; i < 4; i++)
	cin >> x[i] >> y[i]
	);

	bezier(x, y);
	getch();
	return 0;
}

void bezier(int x[4], int y[4]) {
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	for (double t = 0.0; t < 1.0; t += 0.0005) {
		double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1]
				+ 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
		double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1]
				+ 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
		putpixel(xt, yt, WHITE);
	}

	for (int i = 0; i < 4; i++)
		putpixel(x[i], y[i], YELLOW);

	getch();
	closegraph();
}
