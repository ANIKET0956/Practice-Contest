#include <iostream>
#include <fstream>
#include <sstream>
 
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>
#include <queue>
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
 
long long count(long long n)
{
	long long sum = 0;

	for(long long i=2;i*i*i<=n;i++)
	{
		sum += n/(i*i*i);
	}

	return sum;
} 


int main()
{
	long long m;
	cin>>m;

	long long low = 1, high = pow(10,16);

	while(low<high)
	{
		long long mid = low+(high-low)/2;
		
		long long number = count(mid);
		
		if(number<m)
			low=mid+1;
		else if(number>=m)
			high=mid;	

	}

	long long check = count(low);

	if(check!=m)cout<<-1<<endl;
	else cout<<low<<endl;
}