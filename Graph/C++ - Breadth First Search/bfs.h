/*
 * 	bfs.h / Breadth First Traversal
 *
 *	Created on: 29-Mar-2015
 *	Author: Gourav Siddhad
 */

#ifndef BFS_H_
#define BFS_H_

#define	MAX			20
#define READY		1
#define WAIT		2
#define PROCESSED	3

#include "myqueue.h"
#include "iostream"
#include "iomanip"
using namespace std;

class node
{
public:
	int vertex;
	node *next;
}	*adj[MAX];

class mygraph
{
	int total;
public:
	mygraph();
	void create();
	void bfs();
	void sort(node*);
	~mygraph();
};

mygraph :: mygraph()
{
	total=0;
}

void mygraph :: create()
{
	node *newl,*last;
	int neighbor,neighbor_value;
	cout<<" Enter Total Nodes In Graph : ";
	cin>>total;
	if(total>MAX)
	{
		cout<<"\n Error : Total Nodes Exceeding MAX Nodes. Exiting... ";
		exit(0);
	}

	for(int i=0; i<total; i++)
	{
		last=NULL;
		cout<<"\n Total Neighbors Of Node "<<i<<" : ";
		cin>>neighbor;
		for(int j=0; j<neighbor; j++)
		{
			cout<<" Enter neighbor #"<<j<<" : ";
			cin>>neighbor_value;
			newl=new node;
			newl->vertex=neighbor_value;
			newl->next=NULL;
			if(adj[i]==NULL)
				adj[i]=last=newl;
			else
			{
				last->next = newl;
				last = newl;
			}
		}
	}
}

void mygraph :: bfs()
{
	myqueue<int> queue;
	node *tmp;
	int N,v,source;
	int *status=new int[MAX];

	cout<<"\n Enter Source Node : ";
	cin>>source;

	for(int i=0; i<total; i++)
		status[i]=READY;

	queue.enqueue(source);
	status[source]=WAIT;
	while(!queue.isempty())
	{
		N = queue.dequeue();
		status[N]=PROCESSED;
		cout<<setw(4)<<N;
		tmp = adj[N];
		while(tmp!=NULL)
		{
			v = tmp->vertex;
			if(status[v]==READY)
			{
				queue.enqueue(v);
				status[v]=WAIT;
			}
		tmp=tmp->next;
		}
	}
	delete[] status;
}

mygraph :: ~mygraph(){
}

#endif /* BFS_H_ */