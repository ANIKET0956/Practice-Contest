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
#define maxs 600005
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

int tree[maxs][2];
int av[maxs];
int bv[maxs];

int max(int a,int b){return a>b?a:b;}

int min(int a,int b){return a>b?b:a;}


void buildtree(int index,int start,int end)
{
	if(start==end)
	{
		tree[index][0] = av[start];
		tree[index][1] = bv[start];
		return;
	}

	if(start > end )return;

	int mid = start + (end-start)/2;

	buildtree(2*index,start,mid);
	buildtree(2*index+1,mid+1,end);

	tree[index][0] = max(tree[2*index][0],tree[2*index+1][0]);
	tree[index][1] = min(tree[2*index][1],tree[2*index+1][1]);

}


pi read(int index,int st, int en,int qs, int qe)
{

	if(en < qs || qe < st)return make_pair(-1*INT_MAX,INT_MAX);


	if(st >= qs and en <= qe)
	{
		return make_pair(tree[index][0],tree[index][1]);
	}
	int mid =  st + (en-st)/2;

	pi fir = read(2*index,st,mid,qs,qe);

	pi sec = read(2*index+1,mid+1,en,qs,qe);

	
	return make_pair(fir.fi>sec.fi?fir.fi:sec.fi,fir.se<sec.se?fir.se:sec.se);

}


int main()
{
	int n;
	scanf("%d",&n);

	FOR(i,1,n+1)scanf("%d",&av[i]);
	FOR(i,1,n+1)scanf("%d",&bv[i]);

	buildtree(1,1,n);

	ll ans = 0;

	for(int i=1;i<n+1;i++)
	{
		int high=n,low=1;
		int highindex,lowindex;
		pi val;

		while(low<high)
		{
			int mid = low + (high-low)/2;

			val =  read(1,1,n,i,mid);

			if(val.fi<=val.se)
				low=mid+1;
			else if(val.fi>val.se)
				high=mid;

		}

		val = read(1,1,n,i,low);

		highindex = low;

		if(val.fi==val.se)highindex++;


		high=n;low=1;

		while(low<high)
		{
			int mid = low + (high-low)/2;
			if(mid==low)mid++;

			pi val =  read(1,1,n,i,mid);

			if(val.fi<val.se)
				low=mid;
			else if(val.fi>=val.se)
				high=mid-1;

		}

		val = read(1,1,n,i,low);

		lowindex = low;

		if(val.fi==val.se)lowindex--;

		if(highindex-lowindex-1>=0)
			ans += highindex-lowindex-1;

	}

	cout<<ans<<endl;


}

