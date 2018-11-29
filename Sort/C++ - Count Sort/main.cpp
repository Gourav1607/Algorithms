/*
 * main.cpp / Count Sort
 *
 *  Created on: 28-Apr-2015
 *      Author: Gourav Siddhad
 */

#include "count.h"
using namespace std;

int main()
{
	countsort array;
	array.getdata(100, 30, 1000);
	array.display();
	array.sort();
	array.display();
	return 0;
}
