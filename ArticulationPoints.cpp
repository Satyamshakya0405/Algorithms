#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
// int n; // number of nodes
vector<int> adj[10000]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p ) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
			// backedge
			
            low[v] = min(low[v], tin[to]);
        } else {
			// forward edge

            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cout<<v<<" is an articulation point"<<endl;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cout<<v<<"is an articulation point"<<endl;
}
void addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{ 
	int n,e,u,v;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		addEdge(u,v);
	}
	timer = 0;
   visited.assign(n, false);
    tin.assign(n,-1);
    low.assign(n, -1);
   
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i,-1);
    }
  
return 0;
}