#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
bool visited[1001][1001];
int dist[1001][1001];
int n;
bool isvalid(int x,int y)
{
    if(x<1||x>n||y<1||y>n) return false;
    if(visited[x][y]) return false;
    return true;
}
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
void bfs(int srcX,int srcY)
{
    queue<pair<int,int>> q;
    q.push({srcX,srcY});
    visited[srcX][srcY]=true;
    dist[srcX][srcY]=0;
    while(!q.empty())
    {
        int currX=q.front().first;
        int currY=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(isvalid(currX+dx[i],currY+dy[i]))
            {
                int newX=currX+dx[i];
                int newY=currY+dy[i];
                visited[newX][newY]=true;
                dist[newX][newY]=1+dist[currX][currY];
                q.push({newX,newY});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  w(t)
  {
	    cin>>n;
	    int srcX,srcY,endX,endY;
	    cin>>srcX>>srcY>>endX>>endY;
	    memset(visited,false,sizeof(visited));
	    memset(dist,-1,sizeof(dist));
	    bfs(srcX,srcY);
	    cout<<dist[endX][endY]<<endl;
  } 
return 0;
}