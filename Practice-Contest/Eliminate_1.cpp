// Aniket
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
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
#define fill(ar,val) memset((ar),(val),sizeof (ar))
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

int n;
int arr[SIZE];

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{	scanf("%d",&n);
		for(int i=0;i<n;i++)
		{	scanf("%d",&arr[i]);
		}
		bool ans = 0;
		for(int i=0;i<=n-3;i++)
		{	if(arr[i]==arr[i+1] and arr[i+2]==arr[i+1])	ans |=  1;
		}
		if(ans==1)printf("Yes\n");
		else printf("No\n");
	}


}