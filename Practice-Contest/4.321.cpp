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
#define M 20


ll v[M][M];
ll dp[(1<<M)][M];
ll val[M];

ll max(ll a, ll b){return a>b ? a:b; }

int arg(int an,int k)
{
	int add=0;
	for(int i=0;(1<<i) <= an;i++)
	{	if((an >> i)& 1) add ++;
	}

	if(add==k)return 1;
	else return 0;

}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,0,n)scanf("%lld",&val[i]);


	while(k--)
	{	int k1,k2;
		ll k3;

		scanf("%d%d%lld",&k1,&k2,&k3);

		k1--;k2--;
		v[k1][k2] = k3;

	}
	ll ans=0;

	FOR(i,0,(1<<n))
	{
		int ch = arg(i,m);
		FOR(j,0,n)
		{
			if( (i>>j) & 1)
			{
				dp[i][j] = val[j];
				FOR(k,0,n)
				{

					if((i>>k) & 1)
					{
						dp[i][j] = max(dp[i][j],dp[i-(1<<j)][k] +  val[j] + v[k][j]);
					}
				}

				if(ch){ans = max(dp[i][j],ans); }

			}
		}

	}

	cout<<ans<<endl;




}




