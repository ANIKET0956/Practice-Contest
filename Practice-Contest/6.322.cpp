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

vvi graph(maxs);
int leaf[maxs]={0};
int c[maxs][maxs];
int cat[maxs][maxs];

int dfs(int index,int p)
{
	FOR(i,0,maxs){c[index][i]=1e9;
		cat[index][i]=1e9;
	}

	leaf[index] = (graph[index].size()==1);

	c[index][0] = 0;
	cat[index][0] = 0;

	FOR(i,0,graph[index].size())
	{	
		int ch = graph[index][i];
		if(ch!=p){

			dfs(ch,index);

			for(int j=0;j<=leaf[index];j++)
			{
				for(int k=0;k<=leaf[ch];k++)
				{
					cat[index][j+k] = min(cat[index][j+k],c[index][j]+c[ch][k]);
				}

				for(int k=0;k<=leaf[ch];k++)
				{
					cat[index][j+k] = min(cat[index][j+k],c[index][j]+1+c[ch][leaf[ch]-k]);

				}
			}

			leaf[index] += leaf[ch];

			FOR(j,0,leaf[index])c[index][j] = cat[index][j];
		}
	}

	return 0;

}


int main()
{
	int n;
	scanf("%d",&n);

	FOR(i,0,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		graph[x].pb(y);
		graph[y].pb(x);
	}

	dfs(1,-1);


	cout<<c[1][leaf[1]/2]<<endl;
}