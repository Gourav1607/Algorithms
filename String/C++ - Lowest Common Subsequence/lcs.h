/*
 * lcs.h / LCS
 *
 *  Created on: 26-Mar-2015
 *      Author: Gourav Siddhad
 */

#ifndef LCS_H_
#define LCS_H_

#define	MAX	21

#include "iostream"
#include "iomanip"
#include "cstdio"
#include "cstring"
#include "ctime"
using namespace std;

class lcs{
	char str1[MAX], str2[MAX];
	int m[MAX][MAX];
	char b[MAX][MAX];
public:
	void getdata();
	void gentable();
	void display();
	void printlcs(int, int);
};

void lcs :: getdata()
{
	cout<<"\n Enter First String : ";
	fflush(stdin);
	cin.getline(str1, MAX);
	for(int i=strlen(str1)+1; i>=0; i--)
		str1[i+1]=str1[i];
	str1[0]=' ';

	cout<<"\n Enter Second String : ";
	fflush(stdin);
	cin.getline(str2, MAX);
	for(int i=strlen(str2)+1; i>=0; i--)
		str2[i+1]=str2[i];
	str2[0]=' ';

	cout<<" Data Entered Successfully";
}

void lcs :: gentable()
{
	for(unsigned int i=0; i<strlen(str1); i++)
		for(unsigned int j=0; j<strlen(str2); j++)
			if(i==0 || j==0)
			{
				m[i][j]=0;
				b[i][j]=' ';
			}
			else
			{
				if(str1[i]==str2[j])
				{
					m[i][j]=m[i-1][j-1]+1;
					b[i][j]='\\';
				}
				else if(m[i-1][j]>=m[i][j-1])
				{
					m[i][j]=m[i-1][j];
					b[i][j]='|';
				}
				else
				{
					m[i][j]=m[i][j-1];
					b[i][j]='-';
				}
			}
}

void lcs :: display()
{
	cout<<"\n Strings Are : ";
	cout<<str1<<" ";
	cout<<str2<<"\n\n";

	cout<<setw(2)<<"";
	for(int i=0; str2[i]; i++)
		cout<<setw(4)<<str2[i];
	cout<<endl;

	for(unsigned int i=0; i<strlen(str1); i++)
	{
		cout<<setw(3)<<str1[i];
		for(unsigned int j=0; j<strlen(str2); j++)
		{
			cout<<setw(3)<<m[i][j]<<b[i][j];
		}
		cout<<endl;
	}

	cout<<"\n LCS Is : ";
	printlcs(strlen(str1)-1,strlen(str2)-1);
}

void lcs :: printlcs(int i, int j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j]=='\\')
	{
		cout<<str1[i];
		printlcs(i-1,j-1);
	}
	else if(b[i][j]=='|')
		printlcs(i-1,j);
	else if(b[i][j]=='-')
		printlcs(i,j-1);
}

#endif /* COUNT_H_ */
