#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int timer;
int d[10000],l[10000];
bool visited[10000];
void dfs(int s,int parent)
{
    visited[s]=true;
    d[s]=l[s]=timer++;

    for(int x:adj[s])
    {
        if(x==parent)
        continue;
        if(visited[x]==true)
        {
            // s to x is a back edge
            l[s]=min(l[s],d[x]);
        }
        else
        {
            //s to x is a forward edge
            dfs(x,s);
            if(l[x]>d[s])
            cout<<s<<"->"<<x<<"is a bridge"<<endl;
            l[s]=min(l[s],l[x]);
        }
        
    }
}
int main()
{
    int n,e,x,y;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    cin>>x>>y,adj[x].push_back(y),adj[y].push_back(x);
    memset(visited,false,sizeof(visited));
    for(int i=0;i<e;i++)
    if(visited[i]==false)
    dfs(i,-1);
}