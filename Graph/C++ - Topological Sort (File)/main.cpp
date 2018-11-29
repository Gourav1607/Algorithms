/*
 * main.cpp / Topological Sort
 * 06-Sep-2018
 * Gourav Siddhad
 */

#include "tsort.h"
using namespace std;

int main() {

	Tsort tsort;
	tsort.display();
	cout << "\n Topological Sequences : \n";
	tsort.sort();

    return 0;
}
