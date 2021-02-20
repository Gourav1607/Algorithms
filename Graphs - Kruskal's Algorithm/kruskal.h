/*
 *	kruskal.h / Kruskal's Algorithm
 *
 *	Created on: 31-Mar-2015
 *		Author: Gourav Siddhad
 */

#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#define MAX 20

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include "cstdio"
using namespace std;

int myComp(const void *, const void *);

class Edge
{
public:
	int src, dest, weight;
};

class subset
{
public:
	int parent;
	int rank;
};

class mygraph
{
	int V, E;
	Edge *edge;

public:
	mygraph();
	void create();
	int find(subset[], int);
	void Union(subset[], int, int);
	void kruskal();
	void display();
	~mygraph();
};

mygraph ::mygraph()
{
	V = E = 0;
	edge = NULL;
}

void mygraph ::create()
{
	cout << "\n Enter Number Of Vertices In Graph : ";
	cin >> V;
	cout << " Enter Number Of Edges in Graph : ";
	cin >> E;
	delete[] edge;
	edge = new Edge[E];

	for (int i = 0; i < E;)
	{
		cout << "\n For Edge " << i + 1 << " : ";
		cout << "\n Enter Source : ";
		cin >> edge[i].src;
		cout << " Enter Destination : ";
		cin >> edge[i].dest;
		cout << " Enter Weight : ";
		cin >> edge[i].weight;
		if (edge[i].src < V && edge[i].dest < V)
			i++;
		else
		{
			cout << " Error : Exceeding Maximum Number Of Vertices.. Please Re-Enter";
			continue;
		}
	}
}

int mygraph ::find(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void mygraph ::Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void *a, const void *b)
{
	Edge *a1 = (Edge *)a;
	Edge *b1 = (Edge *)b;
	return (a1->weight > b1->weight);
}

void mygraph ::kruskal()
{
	Edge result[V];
	qsort(edge, E, sizeof(Edge), myComp);

	subset *subsets = new subset[V];
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	int e = 0, i = 0;
	while (e < V - 1)
	{
		Edge next_edge = edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}
	cout << "\n Following Are The Edged And Weight Of MST \n";
	cout << " Src -- Dest"
		 << " == "
		 << " Weight";
	for (int i = 0; i < e; i++)
		cout << setw(4) << result[i].src << " -- " << setw(4) << result[i].dest
			 << " == " << setw(6) << result[i].weight << endl;
}

mygraph ::~mygraph()
{
	delete[] edge;
}

#endif /* KRUSKAL_H_ */
