/*
 *  main.cpp / Bubble Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#include "bubble.h"
using namespace std;

int main()
{
	bubblesort array;
	srand(time(NULL));
	array.getdata(1000, 30, 1000+1);
	array.display();
	array.sort();
	array.display();
	return 0;
}
