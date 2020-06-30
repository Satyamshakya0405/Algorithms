#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
void bellmanFord(vector<int> edges[],int n,int e,int s)
{
    int dist[n];
    for(int i=0;i<n;i++)
    dist[n]=INT_MAX;
    dist[s]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(dist[edges[j][0]]+edges[j][2]<dist[edges[0][1]])
            dist[edges[0][1]]=dist[edges[j][0]]+edges[j][2];

        }
    }
    // CHECKING NEGATIVE WEIGHT CYCLE
     for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(dist[edges[j][0]]+edges[j][2]<dist[edges[0][1]])
                cout<<"Negative weight cycle exist"<<endl;

        }
    }
    // Printing shortest distances of every vertex from source
    for(int i=0;i<n;i++)
    cout<<i<<" "<<dist[i]<<endl;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> edges[e];
    
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(w);
    }
    bellmanFord(edges,n,e,0);
    return 0;
}