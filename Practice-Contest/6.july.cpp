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
#include <sys/types.h>

using namespace std;
#define gc getchar
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define maxs 270005
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
#define MOD 786433



ll horner_fma(ll x, ll coeffs[], ll count)
{
    ll result = 0;
    for (ll idx = 0; idx < count; idx++)
    {   result = ll(fma(result%MOD, x, coeffs[idx]))%MOD;
    }
    return (result)%MOD;
}

ll coeffs[maxs];

int main()
{
	int n,k;
	scanf("%d",&n);

	n=250000;
	FOR(i,0,n+1){k=i;coeffs[n-i]=k%MOD;}

	int q;
	scanf("%d",&q);
	q=250000;
	while(q-->=0)
	{
		int num;
		//scanf("%d",&num);
		num=q;
		horner_fma(num,coeffs,n+1);
		//cout<<q<<endl;
		
	}

}
