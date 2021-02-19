/*
 *	main.cpp / Kruskal's Algorithm
 *
 *	Created on: 31-Mar-2015
 *		Author: Gourav Siddhad
 */

#include "kruskal.h"
using namespace std;

int main()
{
	int choice=1;
	mygraph graph;
	graph.create();
	graph.kruskal();
	while(choice)
	{
		cout<<"\n Minimum Spanning Tree";
		cout<<"\n 01. Re-Enter Graph";
		cout<<"\n 02. Kruskal Algorithm";
		cout<<"\n 00. Exit";
		cout<<"\n Enter Choice ... ";
		cin>>choice;
		switch(choice)
		{
		case 0:
			break;
		case 1:
			graph.create();
			break;
		case 2:
			graph.kruskal();
			break;
		default:
			cout<<" Enter Valid Option";
		}
	}
	return 0;
}
