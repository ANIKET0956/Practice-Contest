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
#include <stack>
 
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
int incoming[maxs]={0};
int mark[maxs]={0};
int ance[maxs]={0};
int real[maxs]={0};
int gift[maxs]={0};

int dfs(int index,int cestor)
{
	if(ance[index]!=0) return 0;

	ance[index] = cestor;
	mark[index] = 1;

	FOR(i,0,graph[index].size())
	{
		int ch = graph[index][i];

		if(!mark[ch])
		{
			dfs(ch,cestor);
		}

	}

	return 0;

}

int topological(int n,int m)
{
	stack<int> sorted;
	queue<int> set;

	vi ans;

	FOR(i,1,n+1)
	{	if(!incoming[i])
		{	set.push(i);
		}
	}

	while(set.size()!=0)
	{	int vertex = set.front();
		set.pop();

		if(real[vertex])sorted.push(vertex);

		FOR(i,0,graph[vertex].size())
		{	int ch = graph[vertex][i];
			incoming[ch]--;
			if(!incoming[ch])
				set.push(ch);
		}

	}

	int len = sorted.size();

	FOR(i,0,len)
	{
		int vertex = sorted.top();
		sorted.pop();
		dfs(vertex,vertex);
		ans.pb(vertex);

	}

	int fail = 0;

	FOR(i,1,n+1)
	{
		if(ance[i]!=gift[i])fail = 1;
	}


	if(fail)cout<<-1<<endl;
	else
	{	cout<<ans.size()<<endl;
		FOR(i,0,ans.size())cout<<ans[i]<<endl;
	}

	return 0;

}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);

	FOR(i,0,m)
	{
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		graph[k1].pb(k2);
		incoming[k2]++;
	}

	FOR(i,1,n+1)
	{	int k1;
		scanf("%d",&k1);
		gift[i]=k1;
		real[k1]++;

	}

	topological(n,m);
}