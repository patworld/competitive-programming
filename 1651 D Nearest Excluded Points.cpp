#include<bits/stdc++.h>
using namespace std;
#define ll int
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

const long long inf=1e18;
vector<pll> v;
vl dx;
vl dy;
void directions()
{
	dx.pb(0);dy.pb(1);
	dx.pb(1);dy.pb(0);
	dx.pb(0);dy.pb(-1);
	dx.pb(-1);dy.pb(0);
}

map<pll,pll> ans;
map<pll,bool> vis;
void bfs(vector<pll>& outer, map<pll,bool>& m)
{
    queue<pll> q;
    for(ll i=0;i<outer.size();i++)
    {
        q.push(outer[i]);
        vis[outer[i]]=true;
    }
    while(!q.empty())
    {
        pll temp=q.front();
        q.pop();
        pll p1={temp.ff+1,temp.ss};
        pll p2={temp.ff-1,temp.ss};
        pll p3={temp.ff,temp.ss+1};
        pll p4={temp.ff,temp.ss-1};

        if(vis.find(p1)==vis.end() && m.find(p1)!=m.end())
        {
            ans[p1]=ans[temp];
            q.push(p1);
            vis[p1]=true;
        }
        if(vis.find(p2)==vis.end() && m.find(p2)!=m.end())
        {
            ans[p2]=ans[temp];
            q.push(p2);
            vis[p2]=true;
        }
        if(vis.find(p3)==vis.end() && m.find(p3)!=m.end())
        {
            ans[p3]=ans[temp];
            q.push(p3);
            vis[p3]=true;
        }
        if(vis.find(p4)==vis.end() && m.find(p4)!=m.end())
        {
            ans[p4]=ans[temp];
            q.push(p4);
            vis[p4]=true;
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // directions();
    // cout<<"a";
    ll n;cin>>n;
    vector<pll> p(n);
    map<pll,bool> m;
    for(ll i=0;i<n;i++)
    {
        ll x,y;cin>>x>>y;
        p[i]={x,y};
        m[{x,y}]=true;
    }
    // cout<<"b";
    vector<pll> outer;
    for(ll i=0;i<n;i++)
    {
        
        if(m.find({p[i].ff+1,p[i].ss})==m.end())
        {
            outer.pb(p[i]);
            ans[p[i]]={p[i].ff+1,p[i].ss};
            continue;
        }
        pll p2={p[i].ff-1,p[i].ss};pll p3={p[i].ff,p[i].ss+1};pll p4={p[i].ff,p[i].ss-1};
        if(m.find(p2)==m.end())
        {
             outer.pb(p[i]);
            ans[p[i]]=p2;
            continue;
        }
        else if(m.find(p3)==m.end())
        {
             outer.pb(p[i]);
            ans[p[i]]=p3;
            continue;
        }
        else if(m.find(p4)==m.end())
        {
             outer.pb(p[i]);
            ans[p[i]]=p4;
            continue;
        }
    }
    // for(ll i=0;i<outer.size();i++)
    //     cout<<outer[i].ff<<" "<<outer[i].ss<<el;
    // cout<<"c";
    bfs(outer,m);
    for(ll i=0;i<n;i++)
    {
        // cout<<"fuck";
        cout<<ans[p[i]].ff<<" "<<ans[p[i]].ss<<el;
    }
}
