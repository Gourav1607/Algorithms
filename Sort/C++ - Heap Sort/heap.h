/*
 * heap.h / Heap Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#ifndef HEAP_H_
#define HEAP_H_

#define PARENT(i)		(i-1)/2
#define LEFT(i)			(2*i)+1
#define RIGHT(i)		(2*i)+2

#include "iostream"
#include "cstdlib"
#include "iomanip"
#include "ctime"

using namespace std;
class heapsort
{
	int n, *data, length, nc;
public:
	heapsort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void maxheapify(int);
	void buildmaxheap();
	void display();
	~heapsort();
};

heapsort :: heapsort()
{
	length=n=nc=0;
	data=NULL;
}

void heapsort :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	length=n-1;
	data=new int[n];
	cout<<" Enter Elements : ";
	for(int i=0; i<n; i++)
		cin>>data[i];
	cout<<" Data Entered Successfully";
}

void heapsort :: getdata(int total, int lower, int upper)
{
	n=total;
	length=n-1;
	data=new int[n];
	for(int i=0; i<n; i++)
		data[i]=lower + rand()%(upper-lower);
	cout<<" Data Entered Successfully";
}

void heapsort :: sort()
{
	buildmaxheap();
	for(int i=length; i>0; i--)
	{
		int temp=data[0];
		data[0]=data[i];
		data[i]=temp;

		length--;
		maxheapify(0);
	}
}

void heapsort :: maxheapify(int i)
{
	int l=LEFT(i);
	int r=RIGHT(i);
	int largest=i;
	if(LEFT(i)<=length && data[l]>data[largest])
	{
		largest=l;
		nc++;
	}
	if(RIGHT(i)<=length && data[r]>data[largest])
	{
		largest=r;
		nc++;
	}

	if(largest!=i)
	{
		int temp=data[i];
		data[i]=data[largest];
		data[largest]=temp;
		maxheapify(largest);
	}
}

void heapsort :: buildmaxheap()
{
	for(int i=PARENT(length); i>=0; i--)
		maxheapify(i);
}

void heapsort :: display()
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

heapsort :: ~heapsort()
{
	delete[] data;
}

#endif /* HEAP_H_ */
