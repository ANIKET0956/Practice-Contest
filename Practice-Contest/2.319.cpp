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

vpi edge;
int marked[maxs]={0};


int solved()
{
	printf("YES\n");
	FOR(i,0,edge.size())
	{
		printf("%d %d\n",edge[i].fi,edge[i].se);
	}

	return 1;

}


int main()
{
	int n;
	scanf("%d",&n);

	int p[n];
	FOR(i,1,n+1)scanf("%d",&p[i]);

	int o_c = -1;
	int t_c = -1;

	FOR(i,1,n+1)
	{
		if(p[i]==i)o_c = i;

		if(p[p[i]]==i)t_c = i;

	}


	int valid=0;


	if(o_c != -1)
	{
		FOR(i,1,n+1)
		{	if(i!=o_c)
			{
				edge.pb(make_pair(i,o_c));
			}
		}

		valid = solved();

	}


	if(t_c != -1 and valid == 0)
	{	int u,v;
		u = t_c;
		v = p[t_c];
		marked[u]=1;
		marked[v]=1;


		edge.pb(make_pair(u,v));

		int oddlen = 0;

		FOR(i,1,n+1)
		{
			if(!marked[i])
			{	
				marked[i]=1;
				edge.pb(make_pair(i,u));

				int vertice = p[i];
				int count=1;

				while(vertice != i)
				{
					marked[vertice] = 1;
					count++;
					if(count%2)edge.pb(make_pair(vertice,u));
					else edge.pb(make_pair(vertice,v));
					vertice = p[vertice];

				}

				if(count%2!=0)
				{
					oddlen = 1;
					break;
				}

			}

			if(oddlen)break;
		}

		if(oddlen)valid = 0;
		else valid = solved();

	}
	
	if(!valid)printf("NO\n");

}
