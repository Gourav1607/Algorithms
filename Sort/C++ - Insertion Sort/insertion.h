/*
 * insertion.h / Insertion Sort
 *
 *  Created on: 08-Feb-2015
 *      Author: Gourav Siddhad
 */

#ifndef INSERTION_H_
#define INSERTION_H_

#include "iostream"
#include "iomanip"
#include "ctime"
using namespace std;

class insertionsort
{
	int n, *data, nc;
public:
	insertionsort();
	void getdata();
	void getdata(int, int, int);
	void sort();
	void display();
	~insertionsort();
};

insertionsort :: insertionsort()
{
	n=nc=0;
	data=NULL;
}

void insertionsort :: getdata()
{
	cout<<"\n Enter Number Of Elements : ";
	cin>>n;
	data=new int[n];
	cout<<" Enter Elements : ";
	for(int i=0; i<n; i++)
		cin>>data[i];
	cout<<" Data Entered Successfully";
}

void insertionsort :: getdata(int total, int lower, int upper)
{
	n=total;
	data=new int[n];
	for(int i=0; i<n; i++)
		data[i]=lower + rand()%(upper-lower);
	cout<<" Data Entered Successfully";
}

void insertionsort :: sort()
{
	int key=0;
	for(int i=1; i<n; i++)
	{
		key = data[i];
		int j=i-1;
		while(j>=0 && key<data[j])
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=key;
	}
//	for(int i=0; i<n; i++)
//	{
//		for(int j=i+1; j>0; j--)
//		{
//			if(data[j]<data[j-1])
//			{
//				nc++;
//				int temp=data[j];
//				data[j]=data[j-1];
//				data[j-1]=temp;
//			}
//		}
//	}
}

void insertionsort :: display()
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

insertionsort :: ~insertionsort()
{
	delete[] data;
}

#endif /* INSERTION_H_ */
