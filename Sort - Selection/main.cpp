/*
 *  main.cpp / Selection Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#include "selection.h"
using namespace std;

int main()
{
	selectionsort array;
	srand(time(NULL));
	array.getdata(1000, 30, 1000);
	array.display();
	array.sort();
	array.display();
	return 0;
}
