/*
 *  main.cpp / Breadth First Traversal
 *
 *  Created on: 29-Mar-2015
 *      Author: Gourav Siddhad
 */

#include "bfs.h"
using namespace std;

int main()
{
	mygraph graph;
	graph.create();
	char ch;
	do{
		graph.bfs();
		cout<<"\n Do You Want To Continue (Y/N) : ";
		cin>>ch;
	}while(ch=='Y' || ch=='y');
}
