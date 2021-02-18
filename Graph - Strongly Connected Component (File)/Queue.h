/*
 * Queue.h / Connected Components
 * 30-Aug-2018
 * Gourav Siddhad
 */

#ifndef QUEUE_H
#define	QUEUE_H

#define SIZE 20
#include "iostream"
using namespace std;

class Queue {
	int arr[SIZE];
	int f,r;
public:
	Queue(){
		f=r=-1;
	}
	
	bool isEmpty(){
		return f==-1;
	}

	void enqueue(int el) {
		if((r==f-1) || (f==0 && r==SIZE-1)) {
			cout<<" Queue Full .. Cannot Enter Further Elements ..\n";
			return;
		}
		if(f==-1 && r==-1)	
			f=r=0;
		else if(r==SIZE-1)	
			r=0;
		else				
			r++;
		arr[r]=el;
	}

	int dequeue() {
		int el=arr[f];
		if(f==-1) {
			cout<<" Queue Empty .. Cannot Dequeue \n";
			throw 1;
		} else if(f==r)		
			f=r=-1;
		else if(f==SIZE-1)	
			f=0;
		else				
			f++;
		return el;
	}

	void display() {
		if(f==-1) {
			cout<<" Queue Empty \n";
			return;
		}

		if(f<=r)
			for(int i=f;i<=r;i++)
				cout<<" "<<arr[i];
		else {
			for(int i=r;i<SIZE;i++)
				cout<<" "<<arr[i];
			for(int i=0;i<=f;i++)
				cout<<" "<<arr[i];
		}
		cout<<endl;
	}
};

#endif	/* QUEUE_H */

