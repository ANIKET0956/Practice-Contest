// Aniket
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;
#define gc getchar
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define SIZE 100005
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof(ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}


void readint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

char buf[SIZE];

int main()
{	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		int n;
		scanf("%d",&n);
		int mid,ind;
		memset(buf,'\0',SIZE);
		if(n%2==1)
		{	mid=n/2;
			buf[mid]='a';
			ind=mid-1;
			if(ind>=0)
			{	buf[ind]='b';
				ind--;
				while(ind>=0)
				{	buf[ind]=char(((int(buf[ind+1])+2)-97)%26+97);
					ind--;
				}	
			}
			ind=mid+1;
			if(ind<=n-1)
			{	buf[ind]='c';
				ind++;
				while(ind<=n-1)
				{	buf[ind] = char((int(buf[ind-1]+2)-97)%26+97);
					ind++;
				}
			}
		}
		if(n%2==0)
		{	mid=n/2;
			buf[mid]='a';
			buf[mid-1]='b';
			ind=mid+1;
			if(ind<=n-1)
			{	buf[ind]='c';
				ind++;
				while(ind<=n-1)
				{	buf[ind] = char((int(buf[ind-1]+2)-97)%26+97);
					ind++;
				}
			}
			ind=mid-2;
			if(ind>=0)
			{	buf[ind]='d';
				ind--;
				while(ind>=0)
				{	buf[ind]=char(((int(buf[ind+1])+2)-97)%26+97);
					ind--;
				}	
			}
		}
		printf("%s\n",buf);
	}
	
}