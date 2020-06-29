#include<bits/stdc++.h>
using namespace std;
#define prime       119
#define ll          long long 
#define vi          vector<int>
#define vll         vector<long long int>
#define vii         vector<int,int>
#define w(t)        int t;cin>>t;while(t--)
#define f(i,n)      for(int i=0;i<n;i++)
ll createHash(string s,int n)
{

    ll result=0;
    f(i,n)
    result+=(ll)s[i]*(ll)pow(prime,i);
    return result;

}
ll recalculate_Hash(string s,ll oldindex,ll newindex,ll hashvalue,ll patlength)
{

ll newHash=hashvalue-s[oldindex];
newHash/=prime;
newHash+=(ll)s[newindex]*(ll)pow(prime,patlength-1);
return newHash;

}
bool check(string s,string pat,ll start1,ll end1,ll start2,ll end2)
{
    if(end1-start1!=end2-start2)
    return false;
    while(start1<=end1)
    {
        if(s[start1]!=pat[start2])
        return false;
        start1++;
        start2++;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    w(t)
    {
        string s,pat;
        cin>>s>>pat;
        ll sHash=createHash(s,pat.length());
        ll patHash=createHash(pat,pat.length());
        for(int i=0;i<=s.length()-pat.length();i++)
        {
            if(sHash==patHash&&check(s,pat,i,i+pat.length()-1,0,pat.length()-1))
            {
                cout<<i<<endl;
            }
            if(i<s.length()-pat.length())
            {
                sHash=recalculate_Hash(s,i,i+pat.length(),sHash,pat.length());
            }

        }

        


    }
    
return 0;


}