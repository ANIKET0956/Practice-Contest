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
#define maxs 505
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
 
int dp[3][maxs][maxs]={0};
int arr[maxs];

 int main()
 {

 	int n,ki;
 	scanf("%d%d",&n,&ki);


 	for(int i=0;i<n;i++)scanf("%d",&arr[i]);


 	dp[0][arr[0]][0]=1;
 	dp[0][0][0]=1;
 	dp[0][arr[0]][arr[0]]=1;

 	int odd=0;

 	int even=  1-odd;


     FOR(i,1,n)
 	{
 		odd=i%2;
 		even = 1-odd;

 		FOR(j,0,ki+1)
 		{
 			FOR(k,0,j+1)
 			{
 				{
	 				dp[odd][j][k] = dp[even][j][k] ;
	 				if(arr[i]<=j) dp[odd][j][k] |= dp[even][j-arr[i]][k];
	 				if(arr[i]<=j and arr[i]<=k) dp[odd][j][k] |= dp[even][j-arr[i]][k-arr[i]];

	 		//		cout<<" "<<i<<" "<<j<<" "<<k<<" "<<dp[odd][j][k]<<endl;
	 			}
 			}
 		}
 	}
 	vi pos;

 	FOR(i,0,ki+1)
 	{	if(dp[(n-1)%2][ki][i]==1)pos.pb(i);
    }
    printf("%d\n",pos.size());
    FOR(i,0,pos.size())
    {
    	printf("%d ",pos[i]);
    }


 }