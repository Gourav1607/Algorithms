#include "graphics.h"
#include "iostream.h"
#include "conio.h"

int main() {
	int gd = DETECT, gm = DETECT;
	int i, xmid, ymid, x1, y1, x2, y2, x, y, dy, dx, p, gap = 50;
	float m;
	char str[3];

	initgraph(&gd, &gm, "c:\\tc\\bgi");

	cout << "\n Enter Starting Co-ordinates : ";
	cout << "\n Enter X : ";
	cin > x1;
	cout << " Enter Y : ";
	cin > y1;
	cout << " Enter Ending Co-ordinates : ";
	cout << "\n Enter X : ";
	cin > x2;
	cout << " Enter Y : ";
	cin > y2;

	if (y1 > y2) {    // needed for -ve slope to work
		int temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}

	dy = abs(y2 - y1);
	dx = abs(x2 - x1);
	m = (float) (dy) / (dx);
	dy = abs(dy);
	dx = abs(dx);

	xmid = getmaxx() / 2;
	ymid = getmaxy() / 2;

	x2 = x2 + xmid;
	y2 = ymid - y2;

	x = x1;
	y = y1;
	if (m > 1.0) {
		x = y1;
		y = x1;
	}

	line(5, ymid, getmaxx() - 5, ymid);
	line(xmid + 3, 5, xmid + 3, getmaxy() - 5);

	for (i = xmid + gap; i < getmaxx() - 5; i += gap) {
		outtextxy(i, ymid - 3, "|");
		itoa(i - xmid, str, 10);
		outtextxy(i, ymid + 3, str);
	}

	for (i = ymid - gap; i > 5; i -= gap) {
		outtextxy(xmid, i, "-");
		itoa(ymid - i, str, 10);
		outtextxy(xmid + 5, i, str);
	}

	for (i = xmid - gap; i > 5; i -= gap) {
		outtextxy(i, ymid - 3, "|");
		itoa(-(xmid - i), str, 10);
		outtextxy(i - 6, ymid + 3, str);
	}

	for (i = ymid + gap; i < getmaxy() - 5; i += gap) {
		outtextxy(xmid, i, "-");
		itoa(-(i - ymid), str, 10);
		outtextxy(xmid + 8, i, str);
	}

	x += xmid;
	y = ymid - y;
	p = 2 * dy - dx;
	while (x < x2) {
		if (p >= 0) {
			putpixel(x, y, 5);
			y -= 1;
			p += 2 * dy - 2 * dx;
		} else {
			putpixel(x, y, 5);
			p += 2 * dy;
		}
		x += 1;
	}
	getch();
	closegraph();
}
