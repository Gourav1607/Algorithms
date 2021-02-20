/* 
 *	mystack.h / Depth First Traversal
 *
 *	Created on: 29-Mar-2015
 *	Author: Gourav Siddhad
 */

#ifndef MYSTACK_H
#define MYSTACK_H

#include "iostream"
#include "iomanip"
#include "cstdio"
using namespace std;

template <class T>
class mystack
{
	class node
	{
	public:
		T info;
		node *next;
		node()
		{
			info = 0;
			next = NULL;
		}
	} * top;

public:
	mystack()
	{
		top = NULL;
	}
	void push(T);
	T pop();
	bool clear();
	bool isempty()
	{
		return (top == NULL);
	}
	void display();
};

template <class T>
void mystack<T>::push(T el)
{
	node *temp = new node;
	temp->info = el;
	if (isempty())
		top = temp;
	else
	{
		temp->next = top;
		top = temp;
	}
}

template <class T>
T mystack<T>::pop()
{
	if (isempty())
		throw 1;
	else
	{
		T info = top->info;
		node *de = top;
		top = top->next;
		de->next = NULL;
		delete de;
		return info;
	}
}

template <class T>
void mystack<T>::display()
{
	cout << endl;
	node *tra;
	tra = top;
	if (isempty())
		throw 1;
	while (tra != NULL)
	{
		cout << " " << tra->info;
		tra = tra->next;
	}
}

template <class T>
bool mystack<T>::clear()
{
	node *de;
	while (top != NULL)
	{
		de = top;
		de->next = NULL;
		top = top->next;
		delete de;
	}
	return true;
}

#endif /* MYSTACK_H */
