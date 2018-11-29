/*
 * count.h / Count Sort
 *
 *  Created on: 28-Apr-2015
 *      Author: Gourav Siddhad
 */

#ifndef COUNT_H_
#define COUNT_H_

#include "iostream"
#include "iomanip"
using namespace std;

class countsort{
	int n, *data, *b, nc;
	int max=-32000;
public:
	countsort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void display();
	~countsort();
};

countsort :: countsort()
{
	n=nc=0;
	data=NULL;
	b=NULL;
}

void countsort :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	int max=-32000;
	data= new int[n+1];
	cout<<" Enter Elements : ";
	for(int i=1; i<=n; i++) {
		cin>>data[i];
		if (max < data[i])
			max= data[i];
	}
	b= new int[n+1];
	cout<<" Data Entered Successfully";
}

void countsort :: getdata(int total, int lower, int upper)
{
	n=total;
	data=new int[n+1];
	for(int i=1; i<=n; i++) {
		data[i]=lower + rand()%(upper-lower);
		if (max < data[i])
			max= data[i];
	}
	b= new int[n+1];
	cout<<" Data Entered Successfully";
}

void countsort :: sort()
{
	int *c= new int[max+1];
	for(int i=0; i<=max; i++)
		c[i]=0;
	for(int i=1; i<=n; i++)
		c[data[i]] = c[data[i]]+1;
	for(int i=1; i<=max; i++)
		c[i]=c[i]+c[i-1];
	for(int i=max; i>0; i++) {
		b[c[data[i]]] = data[i];
		c[data[i]]=c[data[i]]-1;
	}
}

void countsort :: display()
{
	cout<<"\n Elements Are : ";
	for(int i=1;i<n;i++)
	{
		if(i%25==0)
			cout<<endl;
		cout<<setw(5)<<data[i];
	}
	cout<<"\n Number Of Comparisons : "<<nc;
}

countsort :: ~countsort()
{
	delete[] data;
}

#endif /* COUNT_H_ */
