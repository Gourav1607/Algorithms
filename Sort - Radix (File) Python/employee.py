# Radix Sort / employee.py
# Created on: 16-Aug-2018
# Author: Gourav Siddhad

class Employee():
    def __init__(self, name='', id=0, age=0, salary=0):
        self.name = name
        self.id = id
        self.age = age
        self.salary = salary

    def getSalary(self):
        return int(self.salary)

    def putData(self, name='', id=0, age=0, salary=0):
        self.name = name
        self.id = id
        self.age = age
        self.salary = salary

    def display(self):
        print(" Name   : ", end='')
        print(self.name)
        print(" Id     : ", end='')
        print(self.id)
        print(" Age    : ", end='')
        print(self.age)
        print(" Salary : ", end='')
        print(self.salary)
