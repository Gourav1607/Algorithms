#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void func(int x, int y, int xc, int yc) {
	putpixel(xc + x, yc + y, RED);
	putpixel(xc - x, yc + y, RED);
	putpixel(xc + x, yc - y, RED);
	putpixel(xc - x, yc - y, RED);
}

void main() {
	int xc, yc, x, y, a, b;
	float p1, p2;

	int gc, gd = DETECT;
	initgraph(&gd, &gc, "C:\\TurboC3\\BGI");

	cout << endl << "Enter center coordinates ";
	cin >> xc >> yc;
	cout << endl << "Enter a and b ";
	cin >> a >> b;

	x = 0;
	y = b;
	func(x, y, xc, yc);

	p1 = (b * b) - (a * a * b) + (a * a) / 4;

	while ((b * b * x) <= (a * a * y)) {
		x++;
		if (p1 <= 0)
			p1 = p1 + 2 * b * b * x + b * b;
		else {
			y--;
			p1 = p1 + 2 * b * b * x + b * b - 2 * a * a * y;
		}

		func(x, y, xc, yc);
		x = -x;
		func(x, y, xc, yc);
		x = -x;
	}

	x = a;
	y = 0;
	func(x, y, xc, yc);

	p2 = (a * a) + (2 * b * b * a) + (b * b) / 4;

	while ((b * b * x) > (a * a * y)) {
		y++;
		if (p2 > 0)
			p2 = p2 + a * a - 2 * a * a * y;
		else {
			x--;
			p2 = p2 + 2 * b * b * x - 2 * a * a * y + a * a;
		}
		func(x, y, xc, yc);
		y = -y;
		func(x, y, xc, yc);
		y = -y;
	}

	getch();
}
