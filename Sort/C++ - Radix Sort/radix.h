/*
 * radix.h / Radix Sort
 *
 *  Created on: 26-Mar-2015
 *      Author: Gourav Siddhad
 */

#ifndef RADIX_H_
#define RADIX_H_

#include "iostream"
#include "iomanip"
#include "ctime"
using namespace std;

class radixsort{
	int n, *data, max, nc;
public:
	radixsort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void display();
	~radixsort();
};

radixsort :: radixsort()
{
	n=nc=0;
	max=-30000;
	data=NULL;
}

void radixsort :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	data=new int[n];
	cout<<" Enter Elements : ";
	for(int i=0; i<n; i++)
	{
		cin>>data[i];
		if(max<data[i])
			max=data[i];
	}
	cout<<" Data Entered Successfully";
}

void radixsort :: getdata(int total, int lower, int upper)
{
	n=total;
	data=new int[n];
	for(int i=0; i<n; i++)
	{
		data[i]=lower + rand()%(upper-lower);
		if(max<data[i])
					max=data[i];
	}
	cout<<" Data Entered Successfully";
}

void radixsort :: sort()
{
	int *d = new int[n];
	for(int i=0;i <n; i++)
		d[i]=0;

	int div=1, ptr=0;
	while(max >0)
	{
		for(int j=0; j<10; j++)
			for(int i=0; i<n; i++)
				if((data[i]/div)%10 == j)
				{
					d[ptr++]=data[i];
					nc++;
				}
		ptr=0;
		div*=10;
		max/=10;
		for(int i=0; i<n; i++)
			data[i]=d[i];
	}
}

void radixsort :: display()
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

radixsort :: ~radixsort()
{
	delete[] data;
}

#endif /* RADIX_H_ */
