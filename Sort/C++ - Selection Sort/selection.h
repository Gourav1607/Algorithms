/*
 * selection.h / Selection Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#ifndef SELECTION_H_
#define SELECTION_H_

#include "iostream"
#include "iomanip"
#include "ctime"

using namespace std;

class selectionsort{
	int n, *data, nc;
public:
	selectionsort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void display();
	~selectionsort();
};

selectionsort :: selectionsort()
{
	n=nc=0;
	data=NULL;
}

void selectionsort :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	data=new int[n];
	cout<<" Enter Elements : ";
	for(int i=0;i<n;i++)
		cin>>data[i];
	cout<<" Data Entered Successfully";
}

void selectionsort :: getdata(int total, int lower, int upper)
{
	n=total;
	data=new int[n];
	for(int i=0; i<n; i++)
		data[i]=lower + rand()%(upper-lower);
	cout<<" Data Entered Successfully";
}

void selectionsort :: sort()
{
	int min=0;
	for(int i=0; i<n; i++)
	{
		min=i;
		for(int j=i+1; j<n; j++)
			if(data[j]<data[i])
			{
				min=j;
				nc++;
			}
		if(i!=min)
		{
			nc++;
			int temp=data[i];
			data[i]=data[min];
			data[min]=temp;
		}
	}
}

void selectionsort :: display()
{
	cout<<"\n Elements Are : ";
	for(int i=0;i<n;i++)
	{
		if(i%25==0)
			cout<<endl;
		cout<<setw(5)<<data[i];
	}
	cout<<"\n Number Of Comparisons : "<<nc;
}

selectionsort :: ~selectionsort()
{
	delete[] data;
}

#endif /* SELECTION_H_ */
