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


vvi graph(maxs);
int mark[maxs]={0};
int newarr[maxs]={0};
int arr[maxs];



int dfs(int index,vi& add)
{	add.pb(index);
	mark[index] = 1;
	FOR(i,0,graph[index].size())
	{	int ch = graph[index][i];
		if(!mark[ch])
		{
			dfs(ch,add);
		}
	}
}


int main()
{

	int n,m;
	scanf("%d%d",&n,&m);

	FOR(i,1,n+1)
	{
		scanf("%d",&arr[i]);
	}

	FOR(i,0,m)
	{	int k1,k2;
		scanf("%d%d",&k1,&k2);
		graph[k1].pb(k2);
		graph[k2].pb(k1);
	}



	FOR(i,1,n+1)
	{	if(!mark[i])
		{	
			vi newadd,collect;
			dfs(i,newadd);
			FOR(j,0,newadd.size())
			{
				collect.pb(arr[newadd[j]]);
			}
			sort(newadd.begin(),newadd.end());
			sort(collect.begin(),collect.end());
			for(int j=collect.size()-1;j>=0;j--)
			{
				newarr[newadd[collect.size()-1-j]]=collect[j];
			}
		}
	}
	FOR(i,1,n+1)
	{
		cout<<newarr[i]<<" ";
	}
	cout<<endl;
}