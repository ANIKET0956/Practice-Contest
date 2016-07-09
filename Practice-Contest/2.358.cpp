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



int main()
{
	int n;
	scanf("%d",&n);

	int number[n];

	FOR(i,0,n)scanf("%d",&number[i]);


	sort(number,number+n);

	int ans = 0;

	FOR(i,0,n)
	{
		if(number[i]>ans)
		{
			ans++;
		}
	}

	printf("%d\n",ans+1);

}