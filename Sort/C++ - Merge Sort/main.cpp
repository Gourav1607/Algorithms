/*
 *  main.cpp / Merge Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#include "merge.h"
using namespace std;

int main()
{
	mergesort array;
	srand(time(NULL));
	array.getdata(1000, 30, 1000);
	//array.getdata();
	array.display();
	array.sort();
	array.display();
	return 0;
}
