#include <iostream>
#include <fstream>
#include <sstream>
 
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>
#include <queue>
#include <algorithm>
#include <numeric>
 
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>


using namespace std;
#define gc getchar
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define maxs 200005
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fs first
#define sc second
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define FOR(i,a,b) for(int (i) =(a); (i) < (b) ; i++ )

map<pair<ll,ll> , ll > mymap;

ll height(ll k)
{	
	ll st = 1;

	while(k!=1)
	{
		k=k/2;
		st++;
	}

	return st;
}

void update(ll k,ll l,ll cost)
{
	ll hei1 = height(k);
	ll hei2 = height(l);

	ll pk = k;
	ll pl = l;

	if(hei1>hei2)
	{
		while(hei1>hei2)
		{	ll left=1;
			if(pk%2)left=0;
		 	pk = pk/2;
		 	mymap[make_pair(pk,left)] += cost;
			hei1--;
		}
	}
	else if(hei2>hei1)
	{
		while(hei2>hei1)
		{	ll left=1;
			if(pl%2)left=0;
			pl = pl/2;
			mymap[make_pair(pl,left)] += cost;
			hei2--;
		}
	}

	while(pk!=pl)
	{	int left=1;
		if(pk%2)left = 0;
		pk = pk/2;
		mymap[make_pair(pk,left)] += cost;
		hei1--;

		left=1;
		if(pl%2)left=0;
		pl=pl/2;
		mymap[make_pair(pl,left)] += cost;
		hei2--;
	}

}

ll read(ll k, ll l)
{
	ll hei1 = height(k);
	ll hei2 = height(l);

	ll pk = k;
	ll pl = l;

	ll sum = 0;

	if(hei1>hei2)
	{
		while(hei1>hei2)
		{	ll left=1;
			if(pk%2)left=0;
		 	pk = pk/2;
		 	sum += mymap[make_pair(pk,left)];
			hei1--;
		}
	}
	else if(hei2>hei1)
	{
		while(hei2>hei1)
		{	ll left=1;
			if(pl%2)left=0;
			pl = pl/2;
			sum += mymap[make_pair(pl,left)];
			hei2--;
		}
	}

	while(pk!=pl)
	{	int left=1;
		if(pk%2)left = 0;
		pk = pk/2;
		sum += mymap[make_pair(pk,left)];
		hei1--;

		left=1;
		if(pl%2)left=0;
		pl=pl/2;
		sum += mymap[make_pair(pl,left)];
		hei2--;
	}

	return sum;

}


int main()
{

	int q;
	scanf("%d",&q);

	while(q-->0)
	{
		int k1;

		scanf("%d",&k1);
		if(k1==1)
		{
			ll k2,k3,k4;
			scanf("%lld%lld%lld",&k2,&k3,&k4);
			update(k2,k3,k4);
		}
		else if(k1==2)
		{
			ll k2,k3;
			scanf("%lld%lld",&k2,&k3);
			printf("%lld\n",read(k2,k3));

		}
	}
}