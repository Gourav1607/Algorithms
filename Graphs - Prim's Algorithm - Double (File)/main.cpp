/*
 *	main.cpp / Prim's MST
 *
 *	Created on: 23-Aug-2018
 *		Author: Gourav Siddhad
 */

#include "prim.h"
using namespace std;

int main() {
	int choice = 1;
	mygraph graph;
	graph.create();

	while (choice) {
		cout << "\n Minimum Spanning Tree";
		cout << "\n 01. Re-Enter Graph";
		cout << "\n 02. Prim's Algorithm";
		cout << "\n 03. Display";
		cout << "\n 04. Double Round";
		cout << "\n 00. Exit";
		cout << "\n Enter Choice ... ";
		cin >> choice;
		switch (choice) {
		case 0:
			break;
		case 1:
			graph.create();
			break;
		case 2:
			graph.prim();
			break;
		case 3:
			graph.printmat();
			graph.display();
			break;
		case 4:
			cout << "\n Round 1 : \n";
			graph.printmat();
			graph.prim();
			graph.display();
			graph.remove();

			cout << "\n Round 2 : \n";
			graph.printmat();
			graph.prim();
			graph.display();
			graph.remove();

			cout << "\n Removed Vertices : ";
			graph.displaysecond();
			break;
		default:
			cout << " Enter Valid Option";
		}
	}
	return 0;
}
