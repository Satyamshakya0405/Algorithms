#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
vector<int> reverse_adj[10000];
stack<int> s;
void dfs(int src,bool visited[])
{
    visited[src]=true;
    for(int x:adj[src])
    {
        if(visited[x]==false)
        dfs(x,visited);
    }
    s.push(src);

}
void dfs_reverse(int src,bool visited[])
{
    cout<<src<<" ";
    visited[src]=true;
    for(int x:reverse_adj[src])
    {
        if(visited[x]==false)
        dfs_reverse(x,visited);
    }
}
void reverse_graph(int n,int e)
{
        for(int i=0;i<n;i++)
        {

                for(int x:adj[i])
                {
                    reverse_adj[x].push_back(i);
                }
        }
}
void kosaraju(int n,int e)
{
    bool visited[n];
    memset(visited,false,sizeof(visited));

    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs(i,visited);
        }
    }

    memset(visited,false,sizeof(visited));
    reverse_graph(n,e);
    while(!s.empty())
    {
        if(visited[s.top()]==false){
        dfs_reverse(s.top(),visited);
        cout<<endl;}
         s.pop();

    }

}
void addEdge(int u,int v)
{
        adj[u].push_back(v);
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

    kosaraju(n,e);

}