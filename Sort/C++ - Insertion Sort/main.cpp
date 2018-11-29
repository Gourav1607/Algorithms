/*
 *  main.cpp / Insertion Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#include "insertion.h"
using namespace std;

int main()
{
	insertionsort array;
	srand(time(NULL));
	array.getdata(1000, 30, 1000+1);
	array.display();
	array.sort();
	array.display();
	return 0;
}
