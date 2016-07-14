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
#define maxs 500005
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

map<int,vi> mymap;
int arr[maxs];
int n;
std::set<int>::iterator low,up;
map<int,int> mark;
set<int> sorted;

ll oneline(int pos)
{
	mymap.clear();
	sorted.clear();
	mark.clear();

	FOR(i,pos+1,n)mymap[arr[i]].pb(i);

	int i=pos;
	ll count = ll((n-pos-1)*(n-pos));
	count /= 2;

	ll ans=0;
	

	sorted.insert(pos);
	sorted.insert(n);

	while(i>=0)
	{	

		if(!mark[arr[i]])
		{
//			cout<<mymap[arr[i]].size()<<endl;

			FOR(j,0,mymap[arr[i]].size())
			{
				int num = mymap[arr[i]][j];
				
				low = sorted.lower_bound(num);
				up  = sorted.upper_bound(num);

				low--;


				ll en = *up;
				ll st = *low;

				ll diff = en-st-1;
				ll sub = diff*(diff+1)/2;
				ll first =  num-st-1;
				ll add = first*(first+1)/2;
				ll second = en-num-1;
				add += second*(second+1)/2;

//				cout<<en<<" "<<st<<endl;
//				cout<<add<<" "<<sub<<" "<<count<<" "<<i<<endl;

				count += add - sub;

				sorted.insert(num);

			}

			mark[arr[i]]=1;
		}

		ans += count;
		i--;
	}

	return ans;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);

		FOR(i,0,n)scanf("%d",&arr[i]);

		ll add =0 ;
		FOR(i,0,n){add+=oneline(i);
		}
		printf("%lld\n",add);
		
	}

}