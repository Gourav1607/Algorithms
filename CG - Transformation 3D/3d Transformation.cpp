#include<iostream.h>
#include<dos.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>

int gd = DETECT, gm;
double x1, x2, y1, y2;

void draw_cube(double edge[20][3]) {
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	int i;
	clearviewport();
	for (i = 0; i < 19; i++) {
		x1 = edge[i][0] + edge[i][2] * (cos(2.3562));
		y1 = edge[i][1] - edge[i][2] * (sin(2.3562));
		x2 = edge[i + 1][0] + edge[i + 1][2] * (cos(2.3562));
		y2 = edge[i + 1][1] - edge[i + 1][2] * (sin(2.3562));
		line(x1 + 320, 240 - y1, x2 + 320, 240 - y2);
	}
	line(320, 240, 320, 25);
	line(320, 240, 550, 240);
	line(320, 240, 150, 410);
	getch();
	closegraph();
}

void scale(double edge[20][3]) {
	double a, b, c;
	int i;
	cout << "Enter The Scaling Factors ";
	cin >> a >> b >> c;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	clearviewport();
	for (i = 0; i < 20; i++) {
		edge[i][0] = edge[i][0] * a;
		edge[i][1] = edge[i][1] * b;
		edge[i][2] = edge[i][2] * c;
	}
	draw_cube(edge);
	closegraph();
}

void translate(double edge[20][3]) {
	int a, b, c;
	int i;
	cout << "Enter The Translation Factors ";
	cin >> a >> b >> c;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	clearviewport();
	for (i = 0; i < 20; i++) {
		edge[i][0] += a;
		edge[i][0] += b;
		edge[i][0] += c;
	}
	draw_cube(edge);
	closegraph();
}

void rotate(double edge[20][3]) {
	int ch;
	int i;
	double temp, theta, temp1;
	clrscr();
	cout << "Rotation About\n";
	cout << "1:X-Axis\n";
	cout << "2:Y-Axis\n";
	cout << "3:Z-Axis\n";
	cout << "Enter Your Choice ";
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Enter The Angle ";
		cin >> theta;
		theta = (theta * 3.14) / 180;
		for (i = 0; i < 20; i++) {
			edge[i][0] = edge[i][0];
			temp = edge[i][1];
			temp1 = edge[i][2];
			edge[i][1] = temp * cos(theta) - temp1 * sin(theta);
			edge[i][2] = temp * sin(theta) + temp1 * cos(theta);
		}
		draw_cube(edge);
		break;

	case 2:
		cout << "Enter The Angle ";
		cin >> theta;
		theta = (theta * 3.14) / 180;
		for (i = 0; i < 20; i++) {
			edge[i][1] = edge[i][1];
			temp = edge[i][0];
			temp1 = edge[i][2];
			edge[i][0] = temp * cos(theta) + temp1 * sin(theta);
			edge[i][2] = -temp * sin(theta) + temp1 * cos(theta);
		}
		draw_cube(edge);
		break;

	case 3:
		cout << "Enter The Angle ";
		cin >> theta;
		theta = (theta * 3.14) / 180;
		for (i = 0; i < 20; i++) {
			edge[i][2] = edge[i][2];
			temp = edge[i][0];
			temp1 = edge[i][1];
			edge[i][0] = temp * cos(theta) - temp1 * sin(theta);
			edge[i][1] = temp * sin(theta) + temp1 * cos(theta);
		}
		draw_cube(edge);
		break;
	}
}

void reflect(double edge[20][3]) {
	int ch;
	int i;
	clrscr();
	cout << "Reflection About\n";
	cout << "1:X-Axis\n";
	cout << "2:Y-Axis\n";
	cout << "3:Z-Axis\n";
	cout << "Enter Your Choice\n";
	cin >> ch;
	switch (ch) {
	case 1:
		for (i = 0; i < 20; i++) {
			edge[i][0] = edge[i][0];
			edge[i][1] = -edge[i][1];
			edge[i][2] = -edge[i][2];
		}
		draw_cube(edge);
		break;

	case 2:
		for (i = 0; i < 20; i++) {
			edge[i][1] = edge[i][1];
			edge[i][0] = -edge[i][0];
			edge[i][2] = -edge[i][2];
		}
		draw_cube(edge);
		break;

	case 3:
		for (i = 0; i < 20; i++) {
			edge[i][2] = edge[i][2];
			edge[i][0] = -edge[i][0];
			edge[i][1] = -edge[i][1];
		}
		draw_cube(edge);
		break;
	}
}

void perspect(double edge[20][3]) {
	int ch;
	int i;
	double p, q, r;
	clrscr();
	cout << "Perspective Projection About\n";
	cout << "1:X-Axis\n";
	cout << "2:Y-Axis\n";
	cout << "3:Z-Axis\n";
	cout << " Enter Your Choice ";
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "Enter P ";
		cin >> p;
		for (i = 0; i < 20; i++) {
			edge[i][0] = edge[i][0] / (p * edge[i][0] + 1);
			edge[i][1] = edge[i][1] / (p * edge[i][0] + 1);
			edge[i][2] = edge[i][2] / (p * edge[i][0] + 1);
		}
		draw_cube(edge);
		break;

	case 2:
		cout << "Enter Q ";
		cin >> q;
		for (i = 0; i < 20; i++) {
			edge[i][1] = edge[i][1] / (edge[i][1] * q + 1);
			edge[i][0] = edge[i][0] / (edge[i][1] * q + 1);
			edge[i][2] = edge[i][2] / (edge[i][1] * q + 1);
		}
		draw_cube(edge);
		break;

	case 3:
		cout << "Enter R ";
		cin >> r;
		for (i = 0; i < 20; i++) {
			edge[i][2] = edge[i][2] / (edge[i][2] * r + 1);
			edge[i][0] = edge[i][0] / (edge[i][2] * r + 1);
			edge[i][1] = edge[i][1] / (edge[i][2] * r + 1);
		}
		draw_cube(edge);
		break;
	}
	closegraph();
}

void parallel(double edge[20][3]) {
	int ch;
	int i;

	clrscr();
	cout << "Perspective Projection About\n";
	cout << "1:X=0 plane\n";
	cout << "2:Y=0 plane\n";
	cout << "3:Z=0 plane\n";
	cout << " Enter Your Choice ";
	cin >> ch;
	switch (ch) {
	case 1:
		for (i = 0; i < 20; i++) {
			edge[i][0] = 0;
			edge[i][1] = edge[i][1];
			edge[i][2] = edge[i][2];
		}
		draw_cube(edge);
		break;
	case 2:
		for (i = 0; i < 20; i++) {
			edge[i][0] = edge[i][0];
			edge[i][1] = 0;
			edge[i][2] = edge[i][2];
		}
		draw_cube(edge);
		break;
	case 3:
		for (i = 0; i < 20; i++) {
			edge[i][0] = edge[i][0];
			edge[i][1] = edge[i][1];
			edge[i][2] = 0;
		}
		draw_cube(edge);
		break;
	}
	closegraph();
}

void main() {
	int choice;
	double edge[20][3] = { 100, 0, 0, 100, 100, 0, 0, 100, 0, 0, 100, 100, 0, 0,
			100, 0, 0, 0, 100, 0, 0, 100, 0, 100, 100, 75, 100, 75, 100, 100,
			100, 100, 75, 100, 100, 0, 100, 100, 75, 100, 75, 100, 75, 100, 100,
			0, 100, 100, 0, 100, 0, 0, 0, 0, 0, 0, 100, 100, 0, 100 };
	while (1) {
		clrscr();

		cout << "1.Draw Cube\n";
		cout << "2:Scaling\n";
		cout << "3:Rotation\n";
		cout << "4:Reflection\n";
		cout << "5:Translation\n";
		cout << "6:Perspective Projection\n";
		cout << "7.Parallel Projection\n";
		cout << "8:Exit\n";
		cout << "Enter Your Choice ";
		cin >> choice;
		switch (choice) {
		case 1:
			draw_cube(edge);
			break;
		case 2:
			scale(edge);
			break;
		case 3:
			rotate(edge);
			break;
		case 4:
			reflect(edge);
			break;
		case 5:
			translate(edge);
			break;
		case 6:
			perspect(edge);
			break;
		case 7:
			parallel(edge);
			break;
		case 8:
			exit(0);
		default:
			cout << "\aPress A Valid Key...!!! ";
			getch();
			break;
		}
		closegraph();
	}
}
