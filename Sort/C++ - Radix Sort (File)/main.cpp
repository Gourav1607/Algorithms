/*
 *  main.cpp / Radix Sort
 *  Created on: 16-Aug-2018
 *  Author: Gourav Siddhad
 */

#include "radix.h"
#include "fstream"
using namespace std;

int main() {
	string name;
	int id, age;
	float salary;
	vector<Employee> data;

	ifstream fin("input.txt", ios::in);
	if(fin.is_open()) {
		while(fin>>name>>id>>age>>salary) {
			data.push_back(Employee(name, id, age, salary));
		}
	} else {
		cout<<"\n Error opening the input file. Exiting.";
	}
	fin.close();

	Radix radix(data);
	radix.print();
	cout<<"\n Sorting ";
	radix.sort();
	cout<<"\n Sorted ";
	radix.print();

	return 0;
}
