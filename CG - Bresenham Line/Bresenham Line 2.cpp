/*
 *  Bresenham Line / Bresenham Line Algorithm
 *  15 - Nov - 2016
 *  Author : Gourav Siddhad
 */

#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "math.h"

#define sign(x) ((x > 0)? 1 : ((x < 0)? -1: 0))

int main() {
	int x1, y1, x2, y2;

	cout << "\n Enter Initial Points X1, Y1 : ";
	cin >> x1 >> y1;
	cout << " Enter Final Points X2, Y2 : ";
	cin >> x2 >> y2;

	int gd = DETECT, gm = 0;
	initgraph(&gd, &gx, "C:\\TC\\BGI");

	getch();
	return 0;
}

void bresenham(int x1, int y1, int x2, int y2) {
	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	int s1 = sign(x2 - x1);
	int s2 = sign(y2 - y1);

	int temp = 0, swap = 0;

	if (dy > dx) {
		temp = dx;
		dx = dy;
		dy = temp;
		swap = 1;
	}

	int D = 2 * dy - dx;
	for (int i = 0; i < dx; i++) {
		putpixel(x, y, 50);
		while (D >= 0) {
			D -= 2 * dx;
			if (swap)
				x += s1;
			else
				y += s2;
		}
		D += 2 * dy;
		if (swap)
			y += s2;
		else
			x += s1;
	}
}
