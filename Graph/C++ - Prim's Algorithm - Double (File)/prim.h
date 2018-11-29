/*
 *	prim.h / Prim's MST
 *
 *	Created on: 23-Aug-2018
 *		Author: Gourav Siddhad
 */

#ifndef PRIM_H_
#define PRIM_H_

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include "cstdio"
#include "climits"
#include "fstream"
#include "cmath"
using namespace std;

class mygraph {
	int V;
	int cordindex;
	float **mat;
	int **cord;
	float *parent;
	float *key;
	bool *mstset;
	int **cords;
public:
	mygraph();
	void create();
	int minkey();
	void prim();
	void display();
	void printmat();
	void remove();
	void displaysecond();
};

mygraph::mygraph() {
	V = 0;
	mat = NULL;
	parent = NULL;
	key = NULL;
	mstset = NULL;
	cord = NULL;
	cords = NULL;
	cordindex = 0;
}

void mygraph::create() {

	int n = 0, x = 0, y = 0;
	cout << "\n Enter the number of Co-ordinates to input : ";
	cin >> n;

	cord = new int *[n];
	for (int i = 0; i < n; i++)
		cord[i] = new int[2];

	ifstream fin("input.txt");
	for (int i = 0; i < n; i++) {
		if (fin >> x >> y) {
			V++;
			cord[i][0] = x;
			cord[i][1] = y;
		} else
			break;
	}
	fin.close();

	cords = new int*[2 * V];
	for (int i = 0; i < 2 * V; i++)
		cords[i] = new int[2];

	mat = new float *[V];
	for (int i = 0; i < V; i++)
		mat[i] = new float[V];

	parent = new float[V];
	key = new float[V];
	mstset = new bool[V];

	for (int i = 0; i < V; i++) {
		for (int j = i; j < V; j++)
			if (i == j)
				mat[i][j] = 0;
			else {
				mat[i][j] = sqrt(
						pow(cord[j][1] - cord[i][1], 2)
								+ pow(cord[j][0] - cord[i][0], 2));
				mat[j][i] = mat[i][j];
			}
		parent[i] = key[i] = 0;
		mstset[i] = false;
	}
}

int mygraph::minkey() {
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstset[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void mygraph::prim() {
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstset[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		int u = minkey();
		mstset[u] = true;
		for (int v = 0; v < V; v++)
			if (mat[u][v] && mstset[v] == false && mat[u][v] < key[v])
				parent[v] = u, key[v] = mat[u][v];
	}
}

void mygraph::display() {
	float sum = 0;
	cout << "\n Edge \t Weight\n";
	for (int i = 1; i < V; i++) {
		cout << " " << parent[i] << " - " << i << " \t " << setprecision(2)
				<< mat[i][(int) parent[i]] << endl;
		sum += mat[i][(int) parent[i]];
	}
	cout << " Sum is : " << sum << endl;
}

void mygraph::remove() {
	for (int i = 1; i < V; i++) {
		cords[cordindex][0] = i;
		cords[cordindex][1] = parent[i];
		cordindex++;
		mat[i][(int) parent[i]] = mat[(int) parent[i]][i] = INT_MAX;
	}
}

void mygraph::printmat() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (mat[i][j] == INT_MAX)
				cout << " " << setw(4) << "INF";
			else
				cout << " " << setw(4) << setprecision(2) << mat[i][j];
		}
		cout << endl;
	}
}

void mygraph::displaysecond() {
	ofstream fout("G_MST.txt");

	cout << "\n Edges \t\t Co-ordinates\n";
	for (int i = 0; i < cordindex / 2; i++) {
		cout << " " << cords[i][0] << " - " << cords[i][1] << " : ";
		cout << "\t(" << cord[cords[i][0]][0] << "," << cord[cords[i][0]][1];
		cout << ") - (" << cord[cords[i][1]][0] << "," << cord[cords[i][1]][1]
				<< ")" << endl;
		fout << cord[cords[i][0]][0] << " " << cord[cords[i][0]][1] << " "
				<< cord[cords[i][1]][0] << " " << cord[cords[i][1]][1] << endl;
	}
	cout << endl;
	for (int i = cordindex / 2; i < cordindex; i++) {
		cout << " " << cords[i][0] << " - " << cords[i][1] << " : ";
		cout << "\t(" << cord[cords[i][0]][0] << "," << cord[cords[i][0]][1];
		cout << ") - (" << cord[cords[i][1]][0] << "," << cord[cords[i][1]][1]
				<< ")" << endl;
		fout << cord[cords[i][0]][0] << " " << cord[cords[i][0]][1] << " "
				<< cord[cords[i][1]][0] << " " << cord[cords[i][1]][1] << endl;
	}
}

#endif /* PRIM_H_ */
