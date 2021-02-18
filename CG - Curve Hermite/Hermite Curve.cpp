/*
 *  Hermite Curve / Hermite Curve
 *  15 - Nov - 2016
 *  Author : Gourav Siddhad
 */

#include "iostream.h"
#include "conio.h"
#include "graphics.h"

void hermite(int, int, int, int, float, float);

int main() {
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	int x1, y1, x2, y2;
	cout << "\n Enter first point X, Y : ";
	cin >> x1 >> y1;
	cout << " Enter second point X, Y :  ";
	cin >> x2 >> y2;

	float m1, m2;
	cout << " Enter two slopes : ";
	cin >> m1 >> m2;

	hermite(x1, y1, x2, y2, m1, m2);

	getch();
	closegraph();
	return 0;
}

void hermite(int x1, int y1, int x2, int y2, float slope1, float slope2) {
	float x, y;
	int color = getcolor();
	for (float u = 0.00; u <= 1.0; u += 0.001) {
		x = (2 * u * u * u - 3 * u * u + 1) * x1
				+ (-2 * u * u * u + 3 * u * u) * x2
				+ (u * u * u - 2 * u * u + u) * slope1 * x1
				+ (u * u * u - u * u) * slope2 * x2;
		y = (2 * u * u * u - 3 * u * u + 1) * y1
				+ (-2 * u * u * u + 3 * u * u) * y2
				+ (u * u * u - 2 * u * u + u) * slope1 * x1
				+ (u * u * u - u * u) * slope2 * x2;
		putpixel(20 + (int) (x + 0.5), 240 - (int) (y + 0.5), color);
	}
}
