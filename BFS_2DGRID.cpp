#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
#define pi          pair<int,int>
int n,m;
bool visited[1001][1001];
int dist[1001][1001];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool isvalid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    if(visited[x][y]) return false;
    return true;
}
void bfs(int srcX,int srcY)
{
    queue<pi> q;
    q.push({srcX,srcY});
    dist[srcX][srcY]=0;
    visited[srcX][srcY]=true;
    while(!q.empty())
    {
        int currX=q.front().first;
        int currY=q.front().second;
        q.pop();
        f(i,4)
        {
            if(isvalid(currX+dx[i],currY+dy[i]))
            {
                int newX=currX+dx[i];
                int newY=currY+dy[i];
                q.push({newX,newY});
                visited[newX][newY]=true;
                dist[newX][newY]=1+dist[currX][currY];
            }

        }

    }
    f(i,n){
    f(j,m){
    cout<<dist[i][j]<<" ";
    }
    cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  w(t)
  {
   int x,y;
   cin>>n>>m;
   cin>>x>>y;
   bfs(x,y);
    
  } 
return 0;
}