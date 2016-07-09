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
int mark[maxs]={0};
int cat[maxs]={0};
int ans;
int n,k;

int dfs(int index,int len,int commit)
{
	mark[index] = 1;
	if(cat[index])len++;
	else len = 0;

	if(len==k) commit = 1;


	//cout<<index<<" "<<len<<" "<<commit<<endl;
	int traver  = 0;

	FOR(i,0,graph[index].size())
	{	int child = graph[index][i];

		if(!mark[child])
		{
			dfs(child,len,commit);
			traver = 1;
		}
	}

	if(!traver and !commit)ans++; 



}

int main()
{
	scanf("%d%d",&n,&k);

	k++;

	FOR(i,1,n+1)scanf("%d",&cat[i]);

	FOR(i,0,n-1)
	{
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		graph[k1].pb(k2);
		graph[k2].pb(k1);

	}

	dfs(1,0,0);

	cout<<ans<<endl;

}
