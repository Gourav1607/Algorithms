/*
 * dj.h / Dijkstra
 *  Created on: 17-Oct-2014
 *      Author: Gourav Siddhad
 */

#ifndef DJ_H_
#define DJ_H_

#include "iostream"
#include "cstring"

using namespace std;
void inttostr(int,char[]);

#define max 12
#define inf 9999

void findpath(int s,int t,int weight[][max+1],int distance[],char path[][20])
{
	distance[s]=0;
	int current=s,newdist=0,dc=0;
	bool dead[max+1];
	char pc[20]="",str[3]="",newpath[20]="";

	for(int i=0;i<=max;i++)
		dead[i]=false;

	while(current!=t)
	{
		dc=distance[current];
		strcpy(pc,path[current]);
		for(int i=1;i<=max;i++)
		{
			newdist=dc+weight[current][i];

			inttostr(i,str);
			strcat(pc,str);
			strcat(pc," ");
			strcpy(newpath,pc);

			if(newdist<distance[i])
			{
				distance[i]=newdist;
				strcpy(path[i],newpath);
			}
			strcpy(pc,path[current]);
		}
		dead[current]=true;
		for(int i=1;i<=max;i++)
		{
			if(dead[i]==false)
			{
				current=i;
				break;
			}
			else
				current=-1;
		}
		inttostr(s,str);
		char p[30];
		strcpy(p,str);
		strcat(p," ");
		strcat(p,path[t]);
		strcpy(path[t],p);
	}
}

void path()
{
	int s,t,distance[max+1],weight[max+1][max+1];
	char path[max+1][20];

	for(int i=0;i<=max;i++)
	{
		distance[i]=inf;
		strcpy(path[i],"");
		for(int j=0;j<=max;j++)
			weight[i][j]=inf;
	}

	weight[1][2]=1;
	weight[1][4]=1;
	weight[1][5]=1;
	weight[2][7]=3;
	weight[2][3]=1;
	weight[3][4]=2;
	weight[4][6]=2;
	weight[5][11]=4;
	weight[6][7]=3;
	weight[6][8]=3;
	weight[6][10]=1;
	weight[7][9]=5;
	weight[8][9]=1;
	weight[9][12]=2;
	weight[10][11]=2;
	weight[10][12]=1;
	weight[11][12]=3;

	for(int i=0;i<=max;i++)
		for(int j=0;j<=max;j++)
			if(weight[i][j]!=inf)
				weight[j][i]=weight[i][j];

	cout<<"\n Enter starting point : ";
	cin>>s;
	cout<<" Enter Destination : ";
	cin>>t;

	if(t<s)
	{
		int temp=t;
		t=s;
		s=temp;
	}

	findpath(s,t,weight,distance,path);
	cout<<"\n Distance : "<<distance[t];
	cout<<"\n Path : "<<path[t];
}

void inttostr(int i,char str[])
{
	int ptr=0;
	char ch;
	str[ptr]='\0';
	while(i!=0)
	{
		switch(i%10)
		{
			case 0:
				ch='0';
				break;
			case 1:
				ch='1';
				break;
			case 2:
				ch='2';
				break;
			case 3:
				ch='3';
				break;
			case 4:
				ch='4';
				break;
			case 5:
				ch='5';
				break;
			case 6:
				ch='6';
				break;
			case 7:
				ch='7';
				break;
			case 8:
				ch='8';
				break;
			case 9:
				ch='9';
				break;
			default:
				ch=' ';
				break;
		}
		i/=10;
		str[ptr]=ch;
		str[++ptr]='\0';
	}
	strrev(str);
}

#endif /* DJ_H_ */
