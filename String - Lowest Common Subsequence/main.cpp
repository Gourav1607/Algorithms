/*
 *  main.cpp / LCS
 *
 *  Created on: 26-Mar-2015
 *      Author: Gourav Siddhad
 */

#include "lcs.h"
using namespace std;

int main()
{
	lcs seq;
	seq.getdata();
	seq.gentable();
	seq.display();
	return 0;
}
