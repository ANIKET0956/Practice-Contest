#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

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

bool myfunc(const pair< pair<int,int> ,int > &a , const pair< pair<int,int>, int > &b)
{
	return  ( a.fi.fi < b.fi.fi || ((a.fi.fi == b.fi.fi) and (a.fi.fi % 2 == 0) ? (a.fi.se < b.fi.se) : (a.fi.se > b.fi.se) ) );
}




int main()
{

	int n;
	scanf("%d",&n);


	vector < pair < pair<int,int> ,int > > point(n);

	FOR(i,0,n)
	{	scanf("%d%d",&point[i].fi.fi,&point[i].fi.se);
		point[i].se=i+1;
		point[i].fi.fi /= 1000;
	}

	 sort(all(point),myfunc);

	FOR(i,0,n)printf("%d ",point[i].se);
	printf("\n");


}
