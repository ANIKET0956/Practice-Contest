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


vvi graph(maxs);
vvi edge(maxs);
int ans;
int marked[maxs]={0};
int value[maxs];
int happy[maxs];
int cut[maxs]={0};
int n;


void dfs_value(int index)
{
	marked[index] = 1;

	FOR(i,0,graph[index].size())
	{
		int child = graph[index][i];

		if(marked[child]==0)
		{
			value[child] = max(edge[index][i],edge[index][i]+value[index]);

			dfs_value(child);
		}
	}

}

void dfs_cut(int index, int cutval)
{
	marked[index]  = 1;

	cutval = cutval or cut[index];

	if(cutval) ans ++;

	FOR(i,0,graph[index].size())
	{
		int child = graph[index][i];
		if(marked[child]==0)
		{
			dfs_cut(child,cutval);

		}
	}


}

void solve()
{

	FOR(i,1,n+1)
	{
		marked[i] = 0 ;
	}

	value[1] = 0;

	dfs_value(1);

	ans = 0;

	FOR(i,1,n+1)
	{	if(happy[i]<value[i])
		{	cut[i]=1;
		}
	}


	cut[1] = 0;

	FOR(i,1,n+1)
	{
		marked[i] = 0;
	}




	dfs_cut(1,0);

	printf("%d\n",ans);

}


int main()
{
	scanf("%d",&n);

	FOR(i,1,n+1)scanf("%d",&happy[i]);

	FOR(i,1,n)
	{	int k1,k2;
		scanf("%d%d",&k1,&k2);

		graph[i+1].pb(k1);
		graph[k1].pb(i+1);
		edge[i+1].pb(k2);
		edge[k1].pb(k2);

	}

	solve();


}