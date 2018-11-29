/*
 *  main.cpp / Radix Sort
 *
 *  Created on: 26-Mar-2015
 *      Author: Gourav Siddhad
 */

#include "radix.h"
using namespace std;

int main()
{
	radixsort array;
	srand(time(NULL));
	array.getdata(1000, 30, 1000);
	array.display();
	array.sort();
	array.display();
	return 0;
}
