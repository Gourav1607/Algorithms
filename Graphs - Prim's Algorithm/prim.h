/*
 *	prim.h / Prim's Algorithm
 *
 *	Created on: 31-Mar-2015
 *		Author: Gourav Siddhad
 */

#ifndef PRIM_H_
#define PRIM_H_

#define MAX 20

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include "cstdio"
using namespace std;

class mygraph
{
	int V;
	int **mat;
	int *parent;
	int *key;
	bool *mstset;

public:
	mygraph();
	void create();
	int minkey();
	void prim();
	void display();
	~mygraph();
};

mygraph ::mygraph()
{
	V = 0;
	mat = NULL;
	parent = NULL;
	key = NULL;
	mstset = NULL;
}

void mygraph ::create()
{
	cout << "\n Enter Number Of Vertices In Graph : ";
	cin >> V;

	mat = new int *[V];
	for (int i = 0; i < V; i++)
		mat[i] = new int[V];
	parent = new int[V];
	key = new int[V];
	mstset = new bool[V];

	for (int i = 0; i < V; i++)
	{
		for (int j = i; j < V; j++)
			if (i == j)
				mat[i][j] = 0;
			else
			{
				cout << " Enter Weight From Node " << i << " To " << j << " : ";
				cin >> mat[i][j];
				mat[j][i] = mat[i][j];
			}
		parent[i] = key[i] = 0;
		mstset[i] = false;
	}
}

int mygraph ::minkey()
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstset[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void mygraph ::prim()
{
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstset[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minkey();
		mstset[u] = true;
		for (int v = 0; v < V; v++)
			if (mat[u][v] && mstset[v] == false && mat[u][v] < key[v])
				parent[v] = u, key[v] = mat[u][v];
	}
}

void mygraph ::display()
{
	cout << "\n Edge	Weight\n";
	for (int i = 0; i < V; i++)
		cout << parent[i] << " - " << i << " " << mat[i][parent[i]] << endl;
}

mygraph ::~mygraph()
{
	for (int i = 0; i < V; i++)
		delete[] mat[i];
	delete[] parent;
	delete[] key;
	delete[] mstset;
}

#endif /* PRIM_H_ */
