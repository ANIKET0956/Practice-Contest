// Aniket
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
#define gc getchar
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define SIZE 100005
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}


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

ll ch1(ll a,ll b)
{
	if(a>=b)
	{	ll div=a/b;
		return a-b*(a/b);
	}
	else
	{
		return (b/a+1)*a - b;

	}
}

ll ch2(ll a,ll b)
{	if(a>=b)
	{
		return (a) - (a/b + 1)*b;
	}
	else
	{
		return b - (b/a)*a;
	}
}

int main()
{
	int t;
	while(t-->0)
	{
		ll a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);

		if(a>=b)
		{
			ll left,right,prevleft;
			left = ch1(c,d);
			right = ch2(c,d);
			while(1)
			{	

			}

		}

	}


}