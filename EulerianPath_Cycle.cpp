#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
void dfs(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;
    for(int x:adj[s])
    if(visited[x]==false)
    dfs(adj,x,visited);
}
bool isConnected(vector<int> adj[],int n)
{
    bool visited[n];
    memset(visited,false,sizeof(visited));
    int i=0;
    for(i=0;i<n;i++)
    {
        if(adj[i].size()!=0)
        break;
    }

        if(i==n) return true;

    dfs(adj,i,visited);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false&&adj[i].size()>0)
        return false;
    }
     return true;
}
void Eulerian(vector<int> adj[],int n)
{
    if(isConnected(adj,n)==false) {
        cout<<"No Eulerian"<<endl;
        return ;
    }

    int odd=0;
    for(int i=0;i<n;i++)
    {
        if(adj[i].size()%2)
            odd++;
    }

    if(odd==0) cout<<"Eulerian Cycle Exist"<<endl;
    else if(odd==2) cout<<"Eulerian Path Exists"<<endl;
    else cout<<"No Eulerian"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  w(t)
  {
   int n,e;
   cin>>n>>e;
   vector<int> adj[n];
   int u,v;
   for(int i=0;i<e;i++)
   {
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   Eulerian(adj,n);

  } 
return 0;
}