#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
int n,m;
bool visited[1001][1001];
int a[1001][1001];
bool isvalid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    if(visited[x][y]||a[x][y]==0) return false;
    return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y)
{
    visited[x][y]=true;
    
    for(int i=0;i<4;i++)
    {
        if(isvalid(x+dx[i],y+dy[i]))
        dfs(x+dx[i],y+dy[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  w(t)
  {
   cin>>n>>m;
   f(i,n)
   f(j,m)
   cin>>a[i][j];

   memset(visited,false,sizeof(visited));
   int count=0;
   f(i,n)
   f(j,m)
   {
    if(visited[i][j]==false&&a[i][j]==1){
       dfs(i,j);
       count++;
    }
   }
   cout<<count<<endl;
    
  } 
return 0;
}