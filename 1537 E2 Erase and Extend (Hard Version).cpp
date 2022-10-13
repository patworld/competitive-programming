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

const long long inf=1e18;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n;cin>>n;ll k;cin>>k;
	string s;cin>>s;
	char c=s[0];
	ll index=0;
	for(ll i=1;i<n;i++)
	{
		if(s[i]>c)
			break;
		else if(s[i]<c)
			index=i;
		else
		{
			ll l=1,r=i+1;
			bool f=false;
			while(r<n)
			{
				if(s[r]<s[l])
				{
					index=r;
					break;
				}
				else if(s[r]==s[l])
				{
					l++;r++;
				}
				else
				{
					f=true;
					break;
				}
			}
			if(f==true)
			{
				break;
			}
			else
			{
				i=r-1;
				
			}
		}
	}
	string ans=s.substr(0,index+1);
	if(ans.size()<k)
	{
		while(ans.size()<k)
		{
			ans+=ans;
		}
		
	}

	for(ll i=0;i<k;i++)
		cout<<ans[i];
	cout<<el;
}


 
