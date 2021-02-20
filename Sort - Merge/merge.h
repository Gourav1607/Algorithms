/*
 * merge.h / Merge Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#ifndef MERGE_H_
#define MERGE_H_

#include "iostream"
#include "iomanip"
#include "ctime"

using namespace std;

class mergesort
{
	int n, *data, *c, nc;

public:
	mergesort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void merge(int, int, int);
	void M_S(int, int);
	void display();
	~mergesort();
};

mergesort ::mergesort()
{
	n = nc = 0;
	data = NULL;
	c = NULL;
}

void mergesort ::getdata()
{
	cout << "\n Enter Number Of Elements : ";
	cin >> n;
	data = new int[n];
	c = new int[n];
	cout << " Enter Elements : ";
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		c[i] = 0;
	}
	cout << " Data Entered Successfully";
}

void mergesort ::getdata(int total, int lower, int upper)
{
	n = total;
	data = new int[n];
	for (int i = 0; i < n; i++)
		data[i] = lower + rand() % (upper - lower);
	cout << " Data Entered Successfully";
}

void mergesort ::sort()
{
	M_S(0, n - 1);
}

void mergesort ::merge(int i, int m, int j)
{
	int r = 0;
	int p = i;
	int q = m + 1;
	while (p <= m && q <= j)
	{
		nc++;
		if (data[p] <= data[q])
		{
			c[r] = data[p];
			p++;
		}
		else
		{
			c[r] = data[q];
			q++;
		}
		r++;
		nc++;
	}
	while (p <= m)
	{
		nc++;
		c[r] = data[p];
		p++;
		r++;
	}
	while (q <= j)
	{
		nc++;
		c[r] = data[q];
		q++;
		r++;
	}
}

void mergesort ::M_S(int i, int j)
{
	if (i < j)
	{
		nc++;
		int mid = (i + j) / 2;
		M_S(i, mid);
		M_S(mid + 1, j);
		merge(i, mid, j);
	}
}

void mergesort ::display()
{
	cout << "\n Elements Are (Entered) : ";
	for (int i = 0; i < n; i++)
	{
		if (i % 25 == 0)
			cout << endl;
		cout << setw(5) << data[i];
	}
	cout << "\n Elements Are (Sorted)  : ";
	for (int i = 0; i < n; i++)
	{
		if (i % 25 == 0)
			cout << endl;
		cout << setw(5) << c[i];
	}
	cout << "\n Number Of Comparisons : " << nc;
}

mergesort ::~mergesort()
{
	delete[] data;
	delete[] c;
}

#endif /* MERGE_H_ */
