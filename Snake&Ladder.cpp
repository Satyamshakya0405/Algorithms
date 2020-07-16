#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
#define pi           pair<int,int>
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  w(t)
  {
    int n;
    cin>>n;
    int arr[31];
    memset(arr,-1,sizeof(arr));
    int a,b;
    while(n--)
    {
        cin>>a>>b;
        arr[a]=b;
    }
    queue<pi> q;
    q.push({1,0});
    bool visited[31];
    memset(visited,false,sizeof(visited));
    while(!q.empty())
    {
      pair<int,int> p=q.front();
      int vertex=p.first;
      int dist=p.second;
        if(vertex==30)
          break;

          q.pop();

          for(int j=vertex+1;j<=vertex+6&&j<=30;j++)
          {

            if(!visited[j])
            {
              int d=dist+1;
              visited[j]=true;
              int v;
              if(arr[j]!=-1)
                v=arr[j];
                else
                {
                  v=j;
                }
                q.push({v,d});


            }


          }
    }
    cout<<q.front().second;
  }
return 0;
}