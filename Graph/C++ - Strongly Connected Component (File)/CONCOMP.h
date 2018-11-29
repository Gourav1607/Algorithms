/*
 * bfs.h / Connected Components
 * 30-Aug-2018
 * Gourav Siddhad
 */

#ifndef CONCOMP_H_
#define CONCOMP_H_

#include "Queue.h"
#include "iostream"
#include "fstream"
#include "cmath"
using namespace std;

class Graph {
	int size;
	int **mat, **rmat;
	bool *con, *scon, *component, **mscon;
	bool *done;
public:
	Graph(int n) {
		int temp=0, *data;
		bool flag = true;
		data = new int[n*n];
	
		ifstream fin("input.txt");
		int i=0;
		while(fin>>data[i]) {
			temp++;
			i++;
		}
		fin.close();
		this->size = sqrt(temp);	
	
		mscon = new bool*[size];
		mat = new int*[size];
		rmat = new int*[size];
		done = new bool[size];
		component = new bool[size];
		for(int i=0; i<size; i++) {
			mat[i] = new int[size];
			rmat[i] = new int[size];
			mscon[i] = new bool[size];
		}

		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++) {
				mat[i][j] = data[i*size+j];
				mscon[i][j] = false;
				rmat[i][j] = mat[j][i];
		}
				
		con = new bool[size];
		scon = new bool[size];
		for(int i=0; i<size; i++)
			con[i] = scon[i] = false;
	}
	
	void connected(int n) {
		for(int i=0; i<size; i++)
			con[i] = false;
		cout<<"\n Connected Component : ";
		bool *visited;
		visited = new bool[size];
		for(int i=0; i<size; i++)
			visited[i] = false;
		Queue mque;
		mque.enqueue(n);
		while(!mque.isEmpty()) {
			int node = mque.dequeue();
			if(!visited[node]) {
				visited[node] = true;
				cout<<node<<" ";
				con[node] = true;
				component[node] = true;
			}
			
			for(int i=0; i<size; i++) {
				if(mat[node][i]>0 && visited[i]==false)
					mque.enqueue(i);
			}
		}
	}
	
	void sconnected(int n) {
		for(int i=0; i<size; i++)
			scon[i] = false;
		cout<<"\n Connected Component : ";
		
		bool *visited;
		visited = new bool[size];
		for(int i=0; i<size; i++)
			visited[i] = false;
		Queue mque;
		mque.enqueue(n);
		while(!mque.isEmpty()) {
			int node = mque.dequeue();
			if(!visited[node]) {
				visited[node] = true;
				cout<<node<<" ";
				scon[node] = true;
			}
			
			for(int i=0; i<size; i++) {
				if(rmat[node][i]>0 && visited[i]==false)
					mque.enqueue(i);
			}
		}
	}
	
	void components() {
		for(int i=0; i<size; i++) {
			if(!component[i]) {
				connected(i);
			}
		}
	}
	
	void scomponents() {
		for(int i=0; i<size; i++) {
			if(!done[i]) {
				connected(i);
				sconnected(i);
				scheck(i);
			}
		}
	}
	
	void scheck(int node) {	
		bool flag = true;
		for(int i=0; i<size; i++)
			if(con[i] != scon[i]) {
				flag = false;
				break;
			}
		if(flag) {
			cout<<"\n Strongly Connected Component\n";
			for(int i=0; i<size; i++) {
				if(con[i]) {
					cout<<" "<<i;
					done[i] = true;
					mscon[node][i] = true;
				}
			}
		} else
			cout<<"\n Not Strongly Connected Component\n";
		cout<<endl;
	}
	
	void maxscon() {
		for(int i=0; i<size; i++) {
			connected(i);
			sconnected(i);
			scheck(i);
		}
		
		int *max, maxn=0, maxi=0;
		max = new int[size];
		for(int i=0; i<size; i++)
			max[i]= 0;
		for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++) {
				if(mscon[i][j])
					max[i]++;
			}
			if(max[i] > maxn) {
				maxn = max[i];
				maxi = i;
			}
		}
		cout<<" Maximum Strongly Connected Component : ";
		for(int i=0; i<size; i++) {
			if(mscon[maxi][i])
				cout<<" "<<i;
		}
		cout<<endl;
	}
	
	void display() {
		cout<<"\n The Adjacency Matrix is : \n";
		for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++)
				cout<<" "<<mat[i][j];
			cout<<endl;
		}
	}
	
	void sdisplay() {
		cout<<"\n The Adjacency Matrix is : \n";
		for(int i=0; i<size; i++) {
			for(int j=0; j<size; j++)
				cout<<" "<<mat[j][i];
			cout<<endl;
		}
	}
};

#endif /* CONCOMP_H_ */

