/*
 * main.cpp / Connected Components
 * 30-Aug-2018
 * Gourav Siddhad
 */

#include "CONCOMP.h"
#include "iostream"
#include "fstream"
#include "cmath"
using namespace std;

int main() {
	
	int n=0;
	cout<<" Enter number of Nodes : ";
	cin>>n;
			
	Graph mygraph(n);
	mygraph.display();
	mygraph.sdisplay();
//	mygraph.components();
	mygraph.scomponents();
	mygraph.maxscon();

	cout<<endl;
	return 0;
}
