// Aniket
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define gc getchar
#define MAX_INT 2147483647
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define maxs 500006
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
 
void readint(ll &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
 
bool myfunc(pair<ll,int> a , pair<ll,int> b)
{	if( a.fi>b.fi ) return 1;
	else if(a.fi==b.fi) return 1;
	else return 0;
}

pair<ll,int> pres[maxs]; 
pair<ll,int> arr[maxs]; 
 
 
ll calneg(int n,int k)
{	
	int cnt=0;
	ll ans=1;
	for(int i=n-1;i>=0;i--)
	{	
		ans = (ans*arr[i].fi+MOD)%MOD;
		cnt++;
		if(cnt==k)break;
	}	
	ans = -1*ans;
	return (ans+MOD)%MOD;
}
 
ll solve(int n, int k)
{
	sort(arr,arr+n);
 	
 	for(int i=0;i<n;i++)
 	{	pres[i].fi = arr[i].fi;
 		pres[i].se = arr[i].se;
 	}
 	for(int i=0;i<n;i++)
 	{	arr[i].fi = pres[n-1-i].fi;
 		arr[i].se = pres[n-1-i].se;
 	}
 	
 	
	int sign = 1;
	for(int i=0;i<k;i++)
	{	sign = sign * arr[i].se;  
	}
	ll ans = 1;
	ll big = -1*(pow(MAX_INT,2));
	if(sign>0)
	{
		for(int i=0;i<k;i++)
		{
			ans  = (ans*arr[i].fi)%MOD;
		}
		return ans;
	}
	else
	{
		ll pp=0,pn=0,nn=0,np=0;
		ll re_neg = 1,nre_neg;
		int ind=k-1;
		int po=0,ne=0;

		while(ind>=0)
		{	if(po || arr[ind].se < 0)re_neg = (re_neg*arr[i].fi)%MOD;
			if(ne || arr[ind].se > 0)nre_neg = (nre_neg*arr[i].fi)%MOD;
			if(arr[ind].se>0){ po = 1; pp = arr[ind].fi; }
			if(arr[ind].se<0){ ne = 1; pn = arr[ind].fi; }
			ind--;
		}

		if(po==0)
		{
			return calneg(n,k);
		}
		else{
			ind = k;
			po= 0 ; ne = 0;
			while(ind<=n-1)
			{	if(arr[ind].se > 0 and po == 0)
				{
					np=(pp*arr[i].fi);
					po=1;
				}
				if(arr[ind].se < 0 and ne == 0)
				{
					nn = (pn*arr[i].fi)%MOD;
					ne = 1;
				}
			}
			if(po and ne)
			{
				if(np>nn) return ((np%MOD)*re_neg)%MOD;
				else return ((nn%MOD)*nre_neg)%MOD;
			}
			else if(po and ne==0)
			{
				return ((np%MOD)*re_neg)%MOD;
			}
			else if(po==0 and ne)
			{
				 return ((nn%MOD)*nre_neg)%MOD;
			}
			else
			{
				return (nre_neg*pn+MOD)%MOD;
			}
		}
 
	}
 
 
}
 
 
int main()
{	ll t;
	readint(t);
	while(t-->0)
	{
		ll n,k;
		readint(n);
		readint(k);
		for(int i=0;i<n;i++){readint(arr[i].fi);
			if(arr[i].fi<0)arr[i].se=-1;
			else arr[i].se=1;
			if(arr[i].fi<0)arr[i].fi=-1*arr[i].fi;
 
		}
		ll ans = solve(n,k);
		printf("%lld\n",(ans+MOD)%MOD);
 		
	}
 
 
} 