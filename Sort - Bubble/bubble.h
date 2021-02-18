/*
 * bubble.h / Bubble Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#ifndef BUBBLE_H_
#define BUBBLE_H_

#include "iostream"
#include "iomanip"
#include "ctime"

using namespace std;

class bubblesort{
	int n, *data, nc;
public:
	bubblesort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void display();
	~bubblesort();
};

bubblesort :: bubblesort()
{
	n=nc=0;
	data=NULL;
}

void bubblesort :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	data=new int[n];
	cout<<" Enter Elements : ";
	for(int i=0; i<n; i++)
		cin>>data[i];
	cout<<" Data Entered Successfully";
}

void bubblesort :: getdata(int total, int lower, int upper)
{
	n=total;
	data=new int[n];
	for(int i=0; i<n; i++)
		data[i]=lower + rand()%(upper-lower);
	cout<<" Data Entered Successfully";
}

void bubblesort :: sort()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n-i-1; j++)
			if(data[j]>data[j+1])
			{
				int temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
				nc++;
			}
}

void bubblesort :: display()
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

bubblesort :: ~bubblesort()
{
	delete[] data;
}

#endif /* BUBBLE_H_ */
