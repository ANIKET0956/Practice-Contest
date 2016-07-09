#include <iostream>
#include <fstream>
#include <sstream>
 
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>
 
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
#define maxs 100005
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


int n,d;

pi arr[maxs];
ll prefix[maxs]={0};

int binary(int target)
{	
	int low = 0;
	int high = n-1;
	while(low < high)
	{	
		int mid = (low+high)/2;

		if(mid==low)mid++;
	
		if(arr[mid].fi>target)
			high = mid-1;
		else if(arr[mid].fi <= target)
			low = mid;

	}

	if(target < arr[0].fi) return -1;	
	return low;

}

int binarylow(int target)
{	
	int low = 0;
	int high = n-1;
	while(low < high)
	{	
		int mid = (low+high)/2;

		if(mid==low)mid++;
	
		if(arr[mid].fi>=target)
			high = mid-1;
		else if(arr[mid].fi < target)
			low = mid;

	}

	if(target < arr[0].fi) return -1;	
	return low;

}


bool func(pi &a , pi& b)
{
	return a.fi < b.fi || ((a.fi == b.fi) and a.se < b.se ) ;

}

ll max(ll a, ll b){ return a>b ? a:b ;}

int main()
{	
	scanf("%d%d",&n,&d);

	FOR(i,0,n)scanf("%d%d",&arr[i].fi,&arr[i].se);

	sort(arr,arr+n,func);


	prefix[0] = arr[0].se;
	FOR(i,1,n)
	{	prefix[i] = prefix[i-1] + arr[i].se;
	}

	ll maxfactor = -1;

	d--;

	FOR(i,0,n)
	{	int cost = arr[i].fi;
		int upcost = cost+d;

		ll add = 0;
		int ind1 = binary(upcost);

		if(ind1 != -1)
		{
			add = prefix[ind1];
		}
		else
			add = 0;
		
		if(i>=1)
		{
			add -= prefix[i-1];
		}


		maxfactor = max(maxfactor,add);


	}

	cout<<maxfactor<<endl;


}
