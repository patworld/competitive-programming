#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
#define pb push_back
#define endl "\n"
#define vl vector<long long int>
#define ff first
#define ss second
#define el "\n"
#define pi 3.14159265358979323846
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define dbg(x)     cout<<#x <<": "<<x<<" ";
#define Dbg(x)    cout<<#x<<":"<<endl<<x;

const long long inf=1e18;
ll f[2002][2002],g[2002][2002];
int main()
{
    // cout<<"helo";
    ll n,k;cin>>n>>k;
    string temp;cin>>temp;
    string s;
    s="*";
    s=s+temp;
    
    f[0][0]=g[0][0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=k;j++)
        {
            f[i][j]=(g[i-1][j]*(s[i]-'a'))%mod;
            ll t=(n-i+1);
            for(ll k=0;k<i && t<=j;k++)
            {
                f[i][j]=(f[i][j]+f[i-k-1][j-t]*(122-s[i]))%mod;
                t=(k+2)*(n-i+1);
            }
            g[i][j]=(f[i][j]+g[i-1][j])%mod;

        }
    }
    cout<<g[n][k]<<endl;
}


 
