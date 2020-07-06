#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
bool Isbipartite(vi adj[],int s,int c,bool visited[],int color[])
{
    visited[s]=true;
    color[s]=c;
    for(int x:adj[s])
    {
        if(visited[x]==false)
        {
            if(Isbipartite(adj,x,c^1,visited,color)==false)
            return false;
        }
        else if(color[s]==color[x])
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  w(t)
  {
      int n,e,u,v;
      cin>>n>>e;
      vi adj[n+1];
      for(int i=1;i<=e;i++)
      {
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
    bool visited[n+1];
    int color[n+1];
    memset(visited,false,sizeof(visited));
    memset(color,0,sizeof(color));
    bool ans=true;
   for(int i=1;i<=n;i++)
   {
       if(visited[i]==false){
       bool res=Isbipartite(adj,i,0,visited,color);
       if(res==false)
       ans=res;
       }
   }

        if(ans) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        
  } 
return 0;
}