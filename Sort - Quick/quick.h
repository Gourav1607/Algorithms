/*
 * quick.h / Quick Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav
 */

#ifndef QUICK_H_
#define QUICK_H_

#include "iostream"
#include "cstdlib"
#include "iomanip"
#include "ctime"

using namespace std;

class quicksort{
	int n, *data, nc;
public:
	quicksort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void rsort();
	void Q_S(int,int);
	int partition(int,int);
	void display();
	~quicksort();
};

quicksort :: quicksort()
{
	n=nc=0;
	data=NULL;
}

void quicksort :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	data=new int[n];
	cout<<" Enter Elements : ";
	for(int i=0; i<n; i++)
		cin>>data[i];
	cout<<" Data Entered Successfully";
}

void quicksort :: getdata(int total, int lower, int upper)
{
	n=total;
	data=new int[n];
	for(int i=0; i<n; i++)
		data[i]=lower + rand()%(upper-lower);
	cout<<" Data Entered Successfully";
}

void quicksort :: sort()
{
	Q_S(0,n-1);
}

void quicksort :: rsort()
{
	int r=n-1;
	int i=rand()%r;
	int temp=data[r];
	data[r]=data[i];
	data[i]=temp;
	sort();
}

void quicksort :: Q_S(int p,int r)
{
	if(p<r)
	{
		nc++;
		int q=partition(p,r);
		Q_S(p,q-1);
		Q_S(q+1,r);
	}
}

int quicksort :: partition(int p,int r)
{
	int x=data[r];
	int i=p-1;
	for(int j=p; j<r; j++)
		if(data[j]<=x)
		{
			nc++;
			i++;
			int temp=data[i];
			data[i]=data[j];
			data[j]=temp;
		}
	int temp=data[i+1];
	data[i+1]=data[r];
	data[r]=temp;
	return i+1;
}

void quicksort :: display()
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

quicksort :: ~quicksort()
{
	delete[] data;
}

#endif /* QUICK_H_ */
