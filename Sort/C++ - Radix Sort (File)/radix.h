/*
 *  radix.h / Radix Sort
 *  Created on: 16-Aug-2018
 *  Author: Gourav Siddhad
 */

#ifndef RADIX_H_
#define RADIX_H_

#include "employee.h"

class Radix {
	Employee *data;
	int size;
public:
	Radix(vector<Employee> data1) { // @suppress("Class members should be properly initialized")
		size = data1.size();
		data = new Employee[size];
		for(int i=0; i<size; i++) {
			data[i] = data1[i];
		}
	}

	float getMax() {
		float max = data[0].getIntSalary();
		for(int i=1; i<size; i++) {
			if(max<data[i].getIntSalary())
				max = data[i].getIntSalary();
		}
		return max;
	}

	void sort() {
		int max = getMax();
		Employee *output = new Employee[size];

		for(int exp=1; max/exp>0; exp*=10) {
			int count[10] = {0};

			for(int i=0; i<size; i++) {
				count[(int)(data[i].getIntSalary()/exp)%10]++;
			}

			for(int i=1; i<10; i++) {
				count[i] += count[i-1];
			}

			for(int i=size-1; i>=0; i--) {
				output[count[(data[i].getIntSalary()/exp)%10 ]-1] = data[i];
				count[(data[i].getIntSalary()/exp)%10]--;
			}

			for(int i=0; i<size; i++) {
				data[i] = output[i];
			}
		}
	}

	void print() {
		for(int i=0; i<size; i++) {
			data[i].print();
		}
	}
};

#endif /* RADIX_H_ */
