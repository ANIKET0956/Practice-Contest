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


vvi graph(maxs);
int mark[maxs];
double tim[maxs]={0};
int num[maxs]={0};

int dfs(int index)
{
	mark[index]=1;
	int child = 1;

	FOR(i,0,graph[index].size())
	{	int ch = graph[index][i];
		if(!mark[ch])
		{
			child += dfs(ch);
		}	
	}

	num[index] = child;
	return child;
}

int evaluate(double par,int index)
{
	mark[index]=1;

	tim[index] = par+1.0;

	par++;

	double total = 0.0;
	FOR(i,0,graph[index].size())total += num[graph[index][i]];

	FOR(i,0,graph[index].size())
	{
		int ch = graph[index][i];
		if(!mark[ch])
		{
			evaluate((total-num[ch])/2.0+par,ch);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);

	FOR(i,2,n+1)
	{
		int k;scanf("%d",&k);
		graph[k].pb(i);
	}

	FOR(i,0,maxs)mark[i]=0;
	dfs(1);

	FOR(i,0,maxs)mark[i]=0;
	evaluate(0.0,1);

	FOR(i,1,n+1)cout<<tim[i]<<" ";


}