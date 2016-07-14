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
#include <cmath>


using namespace std;
#define gc getchar
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define maxs 5005
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

map<ll,pair<ll,ll> > mymap;

ll power(ll x)
{
	return x*x*x;
}

pair<ll,ll> sets;

int iter=0;


pair<ll,ll> divide(ll m)
{
/*
	if(mymap[m]!=sets)
	{
		return mymap[m]; 
	}

*/
	if(m==0)
	{
	
		return sets;
	}

	int x = 1;

	while(power(x+1)<=m)
	{
		x++;
	}

	pair<ll,ll> get = divide(m-power(x));

	get.fi = 1+get.fi;
	get.se = power(x)+get.se;

	pair<ll,ll> an = sets;

	if(x>=1)
	{	an = divide(power(x)-1-power(x-1));
		an.fi =  1+an.fi;
		an.se =  power(x-1)+an.se;
	}


	mymap[m] = max(an,get);

	return max(an,get);

}


int main()
{

	ll m;
	cin>>m;
	sets.se=0;sets.fi=0;
	pair<ll,ll> best = divide(m);

	cout<<best.fi<<" "<<best.se<<endl;


}
