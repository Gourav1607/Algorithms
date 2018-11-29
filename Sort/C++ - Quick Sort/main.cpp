/*
 *  main.cpp / Quick Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#include "quick.h"
using namespace std;

int main()
{
	quicksort array;
	srand(time(NULL));
	array.getdata(1000, 30, 1000);
	array.display();
	array.sort();
	array.display();
	return 0;
}
