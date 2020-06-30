#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
int findparent(int v,int parent[])
{
	if(parent[v]==v)
	return v;
	else return findparent(parent[v],parent);
}
void kruskal(pair<int,pair<int,int>> input[],int n, int e)
{
	pair<int,pair<int,int>> output[n-1];
	int parent[n];
	for(int i=0;i<n;i++) parent[i]=i;
	int count=0,i=0;
	while(count<n-1)
	{
		int source,dest,weight;
		source=input[i].second.first;
		dest=input[i].second.second;
		weight=input[i].first;
		int sourceparent=findparent(source,parent);
		int destparent=findparent(dest,parent);
		if(sourceparent!=destparent)
		{
			output[count]=make_pair(weight,make_pair(source,dest));
			parent[sourceparent]=parent[destparent]
			;
			count++;
		}
		i++;
	}
	for(int i=0;i<n-1;i++)
	{
		if(output[i].second.first<output[i].second.second)
		cout<<output[i].second.first<<" "<<output[i].second.second<<" "<<output[i].first<<endl;
		else 
		cout<<output[i].second.second<<" "<<output[i].second.first<<" "<<output[i].first<<endl;
	}

}
int main()
{
    int n,e;
	cin>>n>>e;
pair<int,pair<int,int>> input[e];
for(int i=0;i<e;i++)
{
	int source,dest,weight;
	cin>>source>>dest>>weight;
	input[i]=make_pair(weight,make_pair(source,dest));
}
sort(input,input+e);
kruskal(input,n,e);


return 0;


}