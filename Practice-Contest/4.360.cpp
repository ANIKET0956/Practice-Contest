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
#define maxs 1000005
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
 
int c[maxs];

vector< vector<pi> > cfact(maxs);
vi p;

void prime()
{
	FOR(i,2,maxs)
	{	
		int fail = 0;
		FOR(j,2,int(sqrt(i))+1)
		{
			if(i%j==0)fail=1;
			if(fail)break;
		}
		if(!fail)p.pb(i);
		//if(!fail and i< 10)cout<<i<<endl;
	}

	cout<<p.size()<<endl;
}


int maxprime[maxs];

int factor(int k,int n)
{
	FOR(i,0,n)
	{
		int copy = c[i];
		for(int j=0;j<p.size() and copy > 1;j++)
		{
			int times = 0;
			while(copy%p[j]==0)
			{
				copy=copy/p[j];
				times++;
			}
			
			if(times>0)cfact[i].pb(make_pair(p[j],times));

			if(copy<=1)break;
			//if(times>0)cout<<" "<<p[j]<<" "<<times<<endl;

		}
	}

	FOR(i,0,maxs)maxprime[i]=0;

	FOR(i,0,n)
	{
		FOR(j,0,cfact[i].size())
		{
			maxprime[cfact[i][j].fi] = max(maxprime[cfact[i][j].fi],cfact[i][j].se);
		}
	}

    int fail = 0;

	for(int i=0;i<p.size();i++)
	{
		int times = 0;
		while(k%p[i]==0)
		{
			k=k/p[i];
			times++;
		}
		if(times>maxprime[p[i]])fail=1;
		if(fail)break;

		if(k<=1)break;

	}

	return fail;
}

int gcd(int a,int b)
{
	if(b==0)return a;

	return gcd(b,a%b);

}

int main()
{

	int n,k;
	scanf("%d%d",&n,&k);

	ll mul = 1;
	int ret=0;
	FOR(i,0,n)
	{
		scanf("%d",&c[i]);

		mul = ( mul * (c[i]) ) / (gcd(c[i],mul));
		if(mul%k==0)ret=1;
		if(ret)break;
		mul=mul%k;

	}

	//prime();
	//int ret = factor(k,n);
	if(ret==0)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;


}