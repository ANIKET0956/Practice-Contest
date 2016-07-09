// Aniket
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
#define gc getchar
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define maxs 500005
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define FOR(i,n) for(int i=0;i<n;i++)


ld abs(ld a)
{
	return a>0?a:-a;
} 
void readint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int n;
ll k;
ll arr[maxs];

ll max(ll a, ll b)
{	return a>b?a:b;
}

ll min(ll a,ll b)
{	return a>b?b:a;
}

ll binaryMin(ll mini,ll maxi)
{
//	cout<<mini<<" "<<maxi<<endl;
	if(mini<maxi)
	{	ll mid=(mini+maxi)/2;
		if(mid==mini)mid++;
		ll diff=0;
		FOR(i,n)
		{
			diff += max(0,mid-arr[i]);
		}
		if(diff>k)
			binaryMin(mini,mid-1);
		else if(diff<=k)
			binaryMin(mid,maxi);
	}
	else
	{
		ll t = k;
		ll mid=maxi;
		FOR(i,n)
		{	t -= max(0,mid-arr[i]);
			arr[i] = max(arr[i],mid);
		}
		FOR(i,n)
		{	if(arr[i]==mid and t)
			{	arr[i]++;t--;
			}
		}
		return 0;
	}
}

ll binaryMax(ll mini, ll maxi)
{
//	cout<<mini<<" "<<maxi<<endl;
	if(mini<maxi)
	{	ll mid=(mini+maxi)/2;
		ll diff=0;
		FOR(i,n)diff+= max(0,arr[i]-mid);
		if(diff>k)
			binaryMax(mid+1,maxi);
		else if(diff<=k)
			binaryMax(mini,mid);
	}
	else
	{	ll t = k;
		ll mid=maxi;
		FOR(i,n)
		{	t -= max(0,arr[i]-mid);
			arr[i] = min(arr[i],mid);
		}
		FOR(i,n)
		{	if(arr[i]==mid and t)
			{	arr[i]--;t--;
			}
		}
		return 0;
	}
	
	
}

int main()
{	scanf("%d%d",&n,&k);
	FOR(i,n)scanf("%lld",&arr[i]);
//	for(.int i=0;i<n;i++)cout<<arr[i]<<endl;
	ll maxlimit = 1.5*pow(10,9);
	binaryMax(0,maxlimit);
	binaryMin(0,maxlimit);
	ll min1=pow(10,15),max1=0;
	FOR(i,n)
	{	min1=min(min1,arr[i]);
		max1=max(max1,arr[i]);
	}
	cout<<max1-min1<<endl;
}












