/*
 *  Mid Point Circle / Circle
 *  15 - Nov - 2016
 *  Author : Gourav Siddhad
 */

#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

void quadrant() {
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
}

void func(int x, int y, int xc, int yc) {
	putpixel(xc + x, yc + y, RED);
	putpixel(xc + x, yc - y, RED);
	putpixel(xc - x, yc - y, RED);
	putpixel(xc - x, yc + y, RED);
	putpixel(xc + y, yc + x, RED);
	putpixel(xc + y, yc - x, RED);
	putpixel(xc - y, yc - x, RED);
	putpixel(xc - y, yc + x, RED);
}

int main() {
	int gd = DETECT, gm, errorcode, x, y, xc, yc, r, p;

	cout << "Enter the central coordinates of the Circle: ";
	cin >> xc >> yc;
	cout << "\n\nEnter The Radius: ";
	cin >> r;

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	quadrant();

	x = 0;
	y = r;
	p = 1 - r;
	xc += getmaxx() / 2;
	yc = getmaxy() / 2 - yc;
	func(x, y, xc, yc);
	while (x <= y) {
		if (p < 0)
			p += 2 * x + 3;
		else {
			p += 2 * x - 2 * y + 5;
			y--;
		}
		x++;
		func(x, y, xc, yc);
	}
	return 0;
}
