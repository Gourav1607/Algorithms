/*
 * tsort.h / Topological Sort
 * Gourav Siddhad
 * 06-Sep-2018
 */

#ifndef TSORT_H_
#define TSORT_H_

#include "iostream"
#include "fstream"
#include "cmath"
#include "vector"
using namespace std;

class Tsort
{
private:
	int **mat, size;
	int *indegree;

public:
	Tsort()
	{
		int n, *data;

		cout << " Enter Number of Nodes : ";
		cin >> n;
		data = new int[n * n];

		int i = 0;
		ifstream fin("input.txt");
		while (fin >> data[i] && i < n * n)
		{
			i++;
		}
		fin.close();

		size = sqrt(i);
		mat = new int *[size];
		indegree = new int[size];
		for (i = 0; i < size; i++)
		{
			mat[i] = new int[size];
			indegree[i] = 0;
		}

		for (i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				mat[i][j] = data[i * size + j];
				if (mat[i][j] > 0)
				{
					indegree[j]++;
				}
			}
		}
	}

	void display()
	{
		cout << " Adjacency Matrix : \n";
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << " " << mat[i][j];
			}
			cout << endl;
		}
		cout << "\n Indegree : \n";
		for (int i = 0; i < size; i++)
		{
			cout << " " << indegree[i];
		}
		cout << endl;
	}

	void sort()
	{
		bool *visited = new bool[size];
		for (int i = 0; i < size; i++)
			visited[i] = false;

		int *result = new int[size];
		sort(result, 0, visited);
	}

	void sort(int result[], int n, bool visited[])
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (indegree[i] == 0 && !visited[i])
			{
				for (int j = 0; j < size; j++)
				{
					if (mat[i][j] > 0)
						indegree[j]--;
				}

				result[n++] = i;
				visited[i] = true;
				sort(result, n, visited);

				visited[i] = false;
				n--;
				for (int j = 0; j < size; j++)
				{
					if (mat[i][j] > 0)
						indegree[j]++;
				}
				flag = true;
			}
		}

		if (!flag)
		{
			for (int i = 0; i < n; i++)
				cout << " " << result[i];
			cout << endl;
		}
	}
};

#endif
