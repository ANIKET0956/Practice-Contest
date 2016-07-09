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
 
int arr[102]={0};

int main()
{
	int n,d;
	cin>>d>>n;

	string friends[101];
	for(int i=0;i<n;i++)
	{
		cin>>friends[i];
	}

	FOR(i,0,n)
	{
		bool add =  1;
		FOR(j,0,friends[i].size())
		{
			add = add & int(friends[i][j]);
		}
		//cout<<add<<endl;
		arr[i] = add;
	}
	int start=0;
	int ans = 0;

	FOR(i,0,n)
	{
		if(arr[i])
		{
			start = 0;
		}
		else
		{
			start++;
		}

		ans = max(ans,start);
	}

	cout<<ans<<endl;
}