#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
 void floodfill(vector<vector<int>> &a,int x,int y,int prevcolor,int newcolor,int n,int m)
 {
     if(x<0||x>=n||y<0||y>=m)
     return ;
     if(a[x][y]!=prevcolor)
     return ;
     if(a[x][y]==newcolor)
     return ;

     floodfill(a,x-1,y,prevcolor,newcolor,n,m);
     floodfill(a,x+1,y,prevcolor,newcolor,n,m);
     floodfill(a,x,y-1,prevcolor,newcolor,n,m);
     floodfill(a,x,y+1,prevcolor,newcolor,n,m);

 }
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  w(t)
  {
      int n,m;
      cin>>n>>m;
        vector<vector<int>> a(n,vector<int> (m,0));
   for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
   {
       cin>>a[i][j];
   }

    int x,y,newcolor,prevcolor;
    cin>>x>>y>>newcolor;
    prevcolor=a[x][y];
    floodfill(a,x,y,prevcolor,newcolor,n,m);
    
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    cout<<a[i][j]<<" ";
    cout<<endl;
    }
  } 
return 0;
}