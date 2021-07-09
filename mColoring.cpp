#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int x[100];
int graph[100][100];
int V;
int m;
int cnt=0;


void nextVal(int k)
{
	while(true)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0) return;
		int j;
		for(j=1 ; j<=k-1 ; ++j)
		{
			if(graph[k][j]==1 and x[j]==x[k]) break;

		}
		if(j==k) return;

	}
}


void mcoloring(int k)
{
	while(true)
	{
		nextVal(k);
		if(x[k]==0) return;
		if(k==V)
		{
			cnt++;
			for(int i=1 ; i<=V ; ++i)
			{
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
		else mcoloring(k+1);
	}
}
int main()
{
	fstream infile;
    infile.open("mcoloring.txt" , ios::in);
    if(!infile)
    {
        cout<<"Error on openning file"<<endl;
        return 0;
    }
      
    infile>>V;
    for(int i=1 ; i<=V ; ++i)
    {
        for(int j=1 ; j<=V ; ++j)
        {
            infile>>graph[i][j];
        }
    }
    
    cout<<"Input Graph is: "<<endl;
    for(int i=1 ; i<=V ; ++i)
    {
        for(int j=1 ; j<=V ; ++j)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    
	m=3;
    cout<<endl<<"For Number of color m="<<m<<endl;
    mcoloring(1);
    cout<<"Total no. of solutions are "<<cnt<<endl;
    cnt=0;

}
