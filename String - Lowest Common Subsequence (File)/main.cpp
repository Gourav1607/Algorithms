/*
 * main.cpp / LCS
 * Gourav Siddhad
 * 27-Sept-2018
 */

#include "lcs.h"
using namespace std;

int main()
{
	LCS lcs(1);
	lcs.gentable();
	lcs.display();
	lcs.printlcs();

	cout << endl;
	return 0;
}
