#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi; 
vector<pair<int,int>>  adj[1000];
void addEdge(int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void dijkstra(int s,int n)
{
priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
 vector<int> dist(n, INT_MAX); 
 dist[s]=0;
 pq.push(make_pair(dist[s],s));
while(!pq.empty())
{
    ppi p=pq.top();
    pq.pop();
    int u=p.second;
    int d=p.first;
    for(auto temp:adj[u])
    {
        int weight=temp.second;
        int v=temp.first;
        if(dist[v]>d+weight)
        {
            dist[v]=d+weight;
            pq.push(make_pair(dist[v],v));
        }
    }
}

for(int i=0;i<n;i++)
cout<<i<<" "<<dist[i]<<endl;

}
void add()
{
     addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7);
}
int main()
{
    int n;
    cin>>n;
    add();
    dijkstra(0,n);
    
}