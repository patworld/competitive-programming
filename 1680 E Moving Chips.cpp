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
#define input(x) for(ll i=0;i<x.size();i++)cin>>x[i];

ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}// omly for prime m

const long long inf=1e9;
int main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        // cout<<"fuck";
        int n;
    cin>>n;
    vector<vector<char>>g(n,vector<char>(2));
    for(int i=0;i<2;i++) {
        for(int j=0;j<n;j++) {
            cin>>g[j][i];
        }
    }
 
    vector<vector<int>>dp(n,vector<int>(2,INT_MAX));
    //dp[i][j] represents minimum number of moves required to finalise chip from 1...i at i and jth row
    int mn = INT_MAX,mx = -1;
    for(int i=0;i<n;i++) {
        if(g[i][0]=='*' or g[i][1]=='*') {
            mn = min(mn,i);
            mx = i;
        }
    }
 
    if(g[mn][0]=='*' and g[mn][1]=='*') {
        dp[mn][0] = 1;
        dp[mn][1] = 1;
    }
    else if(g[mn][0]=='*') {
        dp[mn][0] = 0;
        dp[mn][1] = 1;
    }
    else {
        dp[mn][1] = 0;
        dp[mn][0] = 1;
    }
 
    for(int i=mn+1;i<=mx;i++) {
        if(g[i][0]=='*' and g[i][1]=='*') {
            dp[i][0] = min(dp[i-1][0]+2,dp[i-1][1]+2);
            dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+2);
        }
        else if(g[i][0]=='*') {
            dp[i][0] = min(dp[i-1][0]+1,dp[i-1][1]+2);
            dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+2);
        }
        else if(g[i][1]=='*') {
            dp[i][0] = min(dp[i-1][0]+2,dp[i-1][1]+2);
            dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+1);
        }
        else {
            dp[i][0] = min(dp[i-1][0]+1,dp[i-1][1]+2);
            dp[i][1] = min(dp[i-1][0]+2,dp[i-1][1]+1);
        }
    }
        ll ans=min(dp[mx][0],dp[mx][1]);
        cout<<ans<<el;
    }

}


 
