/*
 * lcs.h / LCS
 * Gourav Siddhad
 * 27-Sept-2018
 */

#ifndef LCS_H_
#define LCS_H_

#include "iostream"
#include "fstream"
#include "iomanip"
#include "cstring"

#define MAX 21
using namespace std;

class LCS {
private:
	char str1[MAX], str2[MAX];
	int m[MAX][MAX];
	char b[MAX][MAX];
		
public:
	LCS(int n) {
		char c;
		bool flag = false;
		str1[0] = ' ';
		str2[0] = ' ';
		
		ifstream fin("input1.txt");
		int i=1;
		while(fin>>c) {
			str1[i++] = c;
			str1[i] = '\0';
		}
		fin.close();	

		fin.open("input2.txt");
		i=1;
		while(fin>>c) {
			str2[i++] = c;
			str2[i] = '\0';
		}
		fin.close();
	}
	
	LCS() {
		cout<<" Enter First String : ";
		fflush(stdin);

		cin.getline(str1, MAX);
		for(int i=strlen(str1)+1; i>=0; i--)
			str1[i+1]=str1[i];
		str1[0]=' ';

		cout<<" Enter Second String : ";
		fflush(stdin);

		cin.getline(str2, MAX);
		for(int i=strlen(str2)+1; i>=0; i--)
			str2[i+1]=str2[i];
		str2[0]=' ';
	}
		
	void gentable() {
		for(unsigned int i=0; i<strlen(str1); i++)
			for(unsigned int j=0; j<strlen(str2); j++)
				if(i==0 || j==0) {
					m[i][j]=0;
					b[i][j]=' ';
				} else {
					if(str1[i]==str2[j]) {
						m[i][j]=m[i-1][j-1]+1;
						b[i][j]='\\';
					} else if(m[i-1][j]>=m[i][j-1]) {
						m[i][j]=m[i-1][j];
						b[i][j]='|';
					} else {
						m[i][j]=m[i][j-1];
						b[i][j]='-';
					}
				}
	}
		
	void display() {
		cout<<"\n String 1 : "<<str1;
		cout<<"\n String 2 : "<<str2;
		cout<<endl;
		
		cout<<setw(2)<<"";
		for(int i=0; str2[i]; i++)
			cout<<setw(4)<<str2[i];
		cout<<endl;

		for(unsigned int i=0; i<strlen(str1); i++) {
			cout<<setw(3)<<str1[i];
			for(unsigned int j=0; j<strlen(str2); j++) {
				cout<<setw(3)<<m[i][j]<<b[i][j];
			}
			cout<<endl;
		}
	}
	
	void printlcs() {
		int i = strlen(str1)-1, j=strlen(str2)-1;

		cout<<"\n LCS is : ";
		while(i>0 && j>0) {
			if(b[i][j]=='\\') {
				cout<<str1[i];
				i--;
				j--;
			} else if(b[i][j]=='|') {
				i--;
			} else if(b[i][j]=='-') {
				j--;
			}
		}
	}
};

#endif // LCS_H_
