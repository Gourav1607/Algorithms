//			Program for implementing Dijkstra's Algorithm
//			Author: Gaurav Saxena
// 			Dated: 16th November 2014

#include<iostream>
using namespace std ; 

struct vertex 
{
	int distance;								//gives distance from source vertex
	int reachable_by;							//gives immediately preceding vertex
	int visited ; 								//whether visited or not i.e. whether it is in priority queue or not
};

class ShortestPath
{
private:
	int no_of_vertices ;						//Number of vertices in the Graph
	int source; 								//source vertex
	vertex *v;									//will create an array of vertex structures 
	int **adj; 									//Adjacency matrix for input of Graph G(V,E)
	int *p_queue;								//priority queue
	int size_of_q; 								//length of priority queue
public: 
	void allocate();							//allocates adjacency matrix
	void input();								//accepts input into adjacency matrix
	void set();									//sets values in 'vertex' structure
	void sort_q();								//sorts priority queue according to 'distance', minimum element remains at last position 
	void find_shortest();  						//procedure for finding shortest path
	void print();
};

void ShortestPath::allocate()
{
	 																			
	cout << "Enter the number of vertices in the subnet/Graph : " ; 
	
	cin >> no_of_vertices ;						//vertex is a structure having fields : distance, reachable_by, visited 
	v = new vertex[no_of_vertices]; 			//allocating space to the vertex array
	
	adj = new int*[no_of_vertices];				//creating a matrix adj[no_of_vertices][no_of_vertices]
	for(int i = 0 ; i<= no_of_vertices-1; i++)
		adj[i] = new int[no_of_vertices]; 
	
	p_queue = new int[no_of_vertices]; 			//creating queue of length no_of_vertices
}

void ShortestPath::input()
{
	cout << "The vertices are numbered like \n " ;							//the way vertices are numbered
	for(int i = 0 ; i <= no_of_vertices -1 ; i++)
		cout << i << "\t" ; 
		
	cout << endl; 
	
	cout << " Distance of vertex i to vertex i is entered as 0 " << endl ;
	for(int i = 0 ; i <= no_of_vertices - 1 ; i++)  						//input adjacency matrix, actual distance or -1. 
		for(int j = 0 ; j <= no_of_vertices -1 ; j++)
			{				 
				cout << " Enter distance from vertex " << i << " to vertex "  << j << " if not connected please enter -1 "  << endl;
				cin >> adj[i][j];  
			}	
	
	cout << endl; 
	cout << "Please enter the source vertex - Source: " ; 
	cin >> source ; 
	cout << endl ; 
}

void ShortestPath::set()
{
	for(int i = 0 ; i<= no_of_vertices -1 ; i++)
	{
		v[i].distance = 32767;						//this defines infinity 
		v[i].reachable_by = -1; 					//gives immediate previous vertex 
		v[i].visited = 0;							//no vertex visited initially
		p_queue[i] = i;								//put vertices in queue also
	}
	
	v[source].distance = 0 ;						//source vertex - distance is 0
	v[source].reachable_by = source ; 				//reachable from source directly
	
	size_of_q = no_of_vertices ; 					//we'll change this size_of_queue hence 
}

void ShortestPath::sort_q()
{

for(int i = 0 ; i <= size_of_q - 2; i++)								//Extremely simple bubble sort/use any sort you like
	{
	 for(int j = 0 , k = j + 1 ; k <= size_of_q - 1 - i ; j++, k++)		//vertex having least distance is the last element in array
		if( v[p_queue[j]].distance < v[p_queue[k]].distance )
			{
				int temp = p_queue[j];
				p_queue[j] = p_queue[k];
				p_queue[k] = temp;
			}
	}	
			
cout << endl << "The sorted queue is as follows : " << endl ; 


for(int i = 0 ; i <= size_of_q -1 ; i++)
	cout << p_queue[i] << "\t"; 

cout << endl ; 
				

}

void ShortestPath::find_shortest()
{
	int dqd_vertex ; 									//dequeued vertex from queue i.e. last vertex
	
	while( size_of_q > 0)								//run till we have entries in queue
	{
		sort_q();										//use selection sort for priority queue
		dqd_vertex = p_queue[size_of_q-1];				//extract last element i.e. element with minimum distance
		size_of_q = size_of_q - 1;						//reduce queue size 
		
		v[dqd_vertex].visited = 1;						//mark this vertex as visited
		
		for(int i = 0 ; i <= no_of_vertices - 1 ; i++)
		{
			if( i != dqd_vertex )						//for this vertex find immediate neighbours which have visited = 0
			{
				if( adj[dqd_vertex][i] > 0 && v[i].visited == 0)		
				{
					if(v[i].distance > v[dqd_vertex].distance + adj[dqd_vertex][i] )
					{
						v[i].distance = v[dqd_vertex].distance + adj[dqd_vertex][i] ;
						v[i].reachable_by = dqd_vertex ;  
					}	
				}
			}
		}
			
	}
}

void ShortestPath::print()
{
	for(int i = 0 ; i <= no_of_vertices -1 ; i++)
	{
		cout << " vertex no. " << i << " Shortest distance is = " << v[i].distance << endl ; 
	}
}

int main()
{
	ShortestPath obj;
	obj.allocate();
	obj.input();
	obj.set();
	obj.find_shortest();
	obj.print();
}

/*
Sample input/output for the example done in class, program works for both directed and undirected graphs: 

GAURAV-SAXENAs-MacBook:C++ sepultrite7432$ ./a.out

Enter the number of vertices in the subnet/Graph : 5
The vertices are numbered like 
 0	1	2	3	4	
 Distance of vertex i to vertex i is entered as 0 
 Enter distance from vertex 0 to vertex 0 if not connected please enter -1 
0
 Enter distance from vertex 0 to vertex 1 if not connected please enter -1 
4
 Enter distance from vertex 0 to vertex 2 if not connected please enter -1 
2
 Enter distance from vertex 0 to vertex 3 if not connected please enter -1 
-1
 Enter distance from vertex 0 to vertex 4 if not connected please enter -1 
-1
 Enter distance from vertex 1 to vertex 0 if not connected please enter -1 
-1
 Enter distance from vertex 1 to vertex 1 if not connected please enter -1 
0
 Enter distance from vertex 1 to vertex 2 if not connected please enter -1 
3
 Enter distance from vertex 1 to vertex 3 if not connected please enter -1 
2
 Enter distance from vertex 1 to vertex 4 if not connected please enter -1 
3
 Enter distance from vertex 2 to vertex 0 if not connected please enter -1 
-1
 Enter distance from vertex 2 to vertex 1 if not connected please enter -1 
1
 Enter distance from vertex 2 to vertex 2 if not connected please enter -1 
0
 Enter distance from vertex 2 to vertex 3 if not connected please enter -1 
4
 Enter distance from vertex 2 to vertex 4 if not connected please enter -1 
5
 Enter distance from vertex 3 to vertex 0 if not connected please enter -1 
-1
 Enter distance from vertex 3 to vertex 1 if not connected please enter -1 
-1
 Enter distance from vertex 3 to vertex 2 if not connected please enter -1 
-1
 Enter distance from vertex 3 to vertex 3 if not connected please enter -1 
0
 Enter distance from vertex 3 to vertex 4 if not connected please enter -1 
-1
 Enter distance from vertex 4 to vertex 0 if not connected please enter -1 
-1
 Enter distance from vertex 4 to vertex 1 if not connected please enter -1 
-1
 Enter distance from vertex 4 to vertex 2 if not connected please enter -1 
-1
 Enter distance from vertex 4 to vertex 3 if not connected please enter -1 
1
 Enter distance from vertex 4 to vertex 4 if not connected please enter -1 
0

Please enter the source vertex - Source: 0


The sorted queue is as follows : 
1	2	3	4	0	

The sorted queue is as follows : 
3	4	1	2	

The sorted queue is as follows : 
4	3	1	

The sorted queue is as follows : 
4	3	

The sorted queue is as follows : 
4	
 vertex no. 0 Shortest distance is = 0
 vertex no. 1 Shortest distance is = 3
 vertex no. 2 Shortest distance is = 2
 vertex no. 3 Shortest distance is = 5
 vertex no. 4 Shortest distance is = 6
*/





