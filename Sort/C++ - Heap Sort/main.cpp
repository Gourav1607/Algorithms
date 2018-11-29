/*
 *  main.cpp / Heap Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#include "heap.h"
using namespace std;

int main()
{
	heapsort array;
	srand(time(NULL));
	array.getdata(1000, 30, 1000);
	array.display();
	array.sort();
	array.display();
	return 0;
}
