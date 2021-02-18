/*
 *  employee.h / Radix Sort
 *  Created on: 16-Aug-2018
 *  Author: Gourav Siddhad
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "iostream"
#include "cstring"
#include "vector"
using namespace std;

class Employee {
	string name;
	int id, age;
	float salary;
public:
	Employee() {
		name = "";
		id = age = salary = 0;
	}
	Employee(string name, int id, int age, float salary) {
		this->name = name;
		this->id = id;
		this->age = age;
		this->salary = salary;
	}
	float getSalary() {
		return salary;
	}
	int getIntSalary() {
		return (int)salary;
	}
	void putData(string name, int id, int age, float salary) {
		this->name = name;
		this->id = id;
		this->age = age;
		this->salary = salary;
	}
	void print() {
		cout<<"\n Name   : "<<name;
		cout<<"\n Id     : "<<id;
		cout<<"\n Age    : "<<age;
		cout<<"\n Salary : "<<salary<<endl;
	}
};

#endif /* EMPLOYEE_H_ */
