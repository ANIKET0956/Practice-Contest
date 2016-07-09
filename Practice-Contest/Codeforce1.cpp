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
#define maxs 100005
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

pi position[maxs];
pair<double,int> arr[maxs];
double dist(pi a,pi b){	return sqrt(pow(a.fi-b.fi,2) + pow(a.se-b.se,2)); }
pi a,b,r;
int n;
pi origin;

double min(double a,double b){ return a>b ? b:a; }

long double cal(int i1,int j1)
{
	long double ans = 0;
	if(i1!=-1 && j1 !=-1)
	{	for(int i=0;i<n;i++)
		{	if(i==i1||i==j1)
			{
				if(i==i1)ans += dist(position[i],a)+dist(position[i],origin);
				if(i==j1)ans+=  dist(position[i],b)+dist(position[i],origin);
			}
			else
				ans +=2.0*(dist(position[i],origin));

		}
	}
	else if(n==1)
	{
		if(i1==-1)ans+=  dist(position[j1],b)+dist(position[j1],origin);
		if(j1==-1)ans += dist(position[i1],a)+dist(position[i1],origin);

	}
	else	
	{	
		for(int i=0;i<n;i++)
		{	if(i==i1||i==j1)
			{
				if(i==i1)ans += dist(position[i],a)+dist(position[i],origin);
				if(i==j1)ans+=  dist(position[i],b)+dist(position[i],origin);
			}
			else
				ans +=2.0*(dist(position[i],origin));

		}

	}
	return ans;	

}

int main()
{
	
	scanf("%d%d%d%d%d%d",&a.fi,&a.se,&b.fi,&b.se,&r.fi,&r.se);
	readint(n);
	origin.fi=r.fi;origin.se=r.se;

	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&position[i].fi,&position[i].se);
	}

	for(int i=0;i<n;i++)
	{
		arr[i].first=dist(position[i],a)-dist(position[i],origin);
		arr[i].second=i;
	}
	sort(arr,arr+n);
	int aone,atwo;
	if(n>=2)
	{	aone =  arr[0].second;
		atwo = arr[1].second;
	}
	if(n==1)
	{	aone = arr[0].second;
	}
	for(int i=0;i<n;i++)
	{	arr[i].first=dist(position[i],b)-dist(position[i],origin);
		arr[i].second=i;
	}
	sort(arr,arr+n);
	int bone,btwo;
	if(n>=2)
	{	bone=arr[0].second;
		btwo=arr[1].second;
	}
	else if(n==1)
	{	bone=arr[0].second;
	}
	float ans =0;
	if(n>=2)
	{	if(aone!=bone)
		{
			ans  = cal(aone,bone);
		}
		if(aone==bone)
		{
			ans = min(cal(aone,btwo),cal(atwo,bone));
		}
		ans =  min(ans,cal(aone,-1));
		ans =  min(ans,cal(-1,bone));

	}
	if(n==1)
	{
		ans = min(cal(aone,-1),cal(-1,bone));
	}

	//cout<<aone<<" "<<atwo<<" "<<bone<<" "<<btwo<<endl;
	printf("%.12f\n",ans);
}