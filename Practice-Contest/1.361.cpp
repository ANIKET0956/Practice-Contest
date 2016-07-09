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


pi pos(int i)
{
	if(i==0)return make_pair(2,4);

	int rowi = i%3;
	if(i%3==0)rowi=3;

	int coli = i/3+1;
	if(i%3==0)coli--;

	return make_pair(rowi,coli);

}

pi space(int i,int j)
{
 	pi posi = pos(i);
 	pi posj = pos(j);

 	return make_pair(posi.fi-posj.fi,posi.se-posj.se);
}

int main()
{
	int n;
	cin>>n;

	long long phone,rem;
	cin>>phone;

	int dig[10];
	int cop[10];

	rem = phone;

	for(int i=n;i>=1;i--)
	{
		dig[i] = rem%10;
		rem = rem/10;
		
		if(dig[i]==0)dig[i]=11;
	}
	int ans=1;

	for(int i=1;i<=11;i++)
	{	
		int valid = 1;

		for(int j=1;j<=n;j++)
		{
			int org = dig[j];
			int newn = (dig[j]+i)%12;
			if(newn==0)newn=12;
			cop[j]=newn;

			if(cop[j]==10||cop[j]==12)valid=0;
		}

		//FOR(j,1,n+1)cout<<cop[j]<<endl;

		int con = 1;
		for(int j=1;j<n and valid;j++)
		{
			pi v,h;
			v  = space(dig[j],dig[j+1]);
			h  = space(cop[j],cop[j+1]);

			if(v.fi == h.fi and v.se == h.se ){ }
			else { con  = 0; }



			if(con==0)break;

		}
		if(con==1 and valid){ans=0;break;}

	}

	if(!ans)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}