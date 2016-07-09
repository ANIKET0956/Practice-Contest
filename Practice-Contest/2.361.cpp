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
 
 
vvi  graph(maxs);
int mark[maxs]={0};
int dist[maxs];

int bfs()
{	
	queue<int> mset;
	mset.push(1);
	dist[1]=0;
	mark[1]=1;
	int height=0;
	height++;

	while(mset.size()!=0)
	{	int vertex=mset.front();
		mset.pop();
		FOR(i,0,graph[vertex].size())
		{	int ch = graph[vertex][i];
			if(!mark[ch])
			{
				mark[ch]=1;
				mset.push(ch);
			}
			dist[ch] = min(dist[ch],dist[vertex]+1);
		}

	}

}

 int main()
 {
 	int n;
 	scanf("%d",&n);


 	FOR(i,1,n+1){int k;scanf("%d",&k);graph[i].pb(k);}

 	FOR(i,1,n){graph[i].pb(i+1);graph[i+1].pb(i);}

 	FOR(i,1,n+1)dist[i]=INT_MAX;

 	bfs();
 	 
 	FOR(i,1,n+1)cout<<dist[i]<<" ";


 	

 }