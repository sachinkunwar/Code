#include <iostream>
#include<vector>
#include<climits>
#define MAX 10
using namespace std;

int a[MAX][MAX];
int start;
vector<int> tov(vector<int> v,int j)
{
	vector<int> b;
	for(int i=0;i<v.size();i++)
	{
		if(i!=j)b.push_back(v[i]);
	}
	return b;
}
int tsp(int s,vector<int> v)
{
	if(v.size()==0)
		return a[s-1][start-1];
	int next,mn=INT_MAX,tmp;
	for(int i=0;i<v.size();i++)
	{
		tmp=a[s-1][v[i]-1]+tsp(v[i],tov(v,i));
		if(tmp<mn)
		{
			next=i;
			mn=tmp;
		}
	}
	return mn;
	
}
int main() {
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>start;
	for(int i=1;i<=n;i++)
	{
		if(i!=start)
		v.push_back(i);
	}
	cout<<tsp(start,v);
	return 0;
}