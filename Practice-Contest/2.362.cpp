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


int int_str(string a)
{
	int num = 0;

	for(int i=0;i<a.size();i++)
	{
		num =  num*10 + int(a[i]) - 48;
	}

	return num;
}

int main()
{
	string str;
	cin >> str;

	string a,b,d,newd;
	int con =1;
	FOR(i,0,str.size())
	{	if(str[i]=='.')
		{	con = 2;
			continue;
		}
		if(str[i]=='e')
		{
			con = 3;
			continue;
		}

		if(con==1)
			a += str[i];
		if(con==2)
			d += str[i];
		if(con==3)
			b += str[i];
	}

	if(d=="0")d="";

	int bpow = int_str(b);


	int dsize = d.size();



	if(dsize  < bpow)
	{
		while(dsize<bpow)
		{
			d += '0';
			dsize++;
		}
	}

	if(bpow==dsize)
	{
		cout<<a<<d<<endl;
	}
	else
	{
		FOR(i,0,d.size())
		{	if(i==bpow)
			{
				newd += '.';
			}

			newd += d[i];

		}

		cout<<a<<newd<<endl;
	}

}