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


ll max(ll a, ll b){return a>b ?  a:b ; }

int bit64[100]={0};
int ch[100]={0};
ll prefix[maxs]={0};
ll suffix[maxs]={0};

ll power(ll x,ll k)
{
	if(k==0)return 1;
	else if(k%2==0) {
		ll keep = power(x,k/2);
		return keep*keep;
	}
	else if(k%2==1)
	{	ll keep = power(x,k/2);
		return keep*keep*x;
	}

}


int main()
{

	int n,k,x;
	scanf("%d%d%d",&n,&k,&x);


	ll a[n];
	FOR(i,0,n)scanf("%lld",&a[i]);

	ll prod = -1;




	ll keep = power(x,k);



	prefix[0] = a[0];
	suffix[n-1] = a[n-1];
	FOR(i,1,n)prefix[i] = prefix[i-1] | a[i];

	for(int i=n-2;i>=0;i--) suffix[i] = suffix[i+1] | a[i]; 

	FOR(i,0,n)
	{	ll orans = -1;
		if(i==0) orans = suffix[i+1] | (a[i]*keep);
		else if(i==n-1) orans = prefix[i-1] | (a[i]*keep);
		else orans = prefix[i-1] |  (a[i]*keep) | suffix[i+1];

		prod = max(prod,orans);
	}

	cout<<prod<<endl;


}