// Aniket
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define gc getchar
#define MAX_INT 2147483647
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define maxs 5005
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
 
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

int n,m;
int dis[maxs][maxs];
vi  graph[maxs];
vi  edge[maxs];
int dp[maxs];
int prevdp[maxs];
int previous[maxs];

void dijkstra(int source)
{	
	FOR(i,1,n+1)dis[source][i]=MAX_INT;

	std::set<pi> myset;
  	std::set<pi>::iterator it;

  	dis[source][source]=0;

  	myset.insert(make_pair(dis[source][source],source));

  	int u,v,wt;

  	while(myset.size()!=0)
  	{
  		it  = myset.begin();
  		u = it->second;

  		myset.erase(it);

  		for(int i=0;i<graph[u].size();i++)
  		{
  			v  = graph[u][i];

  			if(dis[source][v]>dis[source][u]+1)
  			{	
  				if(dis[source][v]!=MAX_INT)
  				{	myset.erase(myset.find(make_pair(dis[source][v],v)));	
  				}

  				dis[source][v] = dis[source][u] + 1;
  				myset.insert(make_pair(dis[source][v],v));

  			}
  		}

  	}

}

void pr(vi k)
{
	FOR(i,0,k.size())printf("%d ",k[i]);

}

int find(int u,int v)
{
	FOR(j,1,n+1)
	{	if(dis[j][v]!= -1*MAX_INT && dis[u][j]!= -1*MAX_INT)
		{
			if(j!= v and j!=u)
				return j;
		}
	}
	return -1;
}

void add(vi k)
{
	vi newpath;

	if(k.size()==2)
	{
		int num = find(k[0],k[1]);
		if(num!=-1)
		{
			int ch1 = find(k[0],num);
			if(ch1==-1)
			{
				ch1 = find(num,k[1]);
				
				if(ch1!=-1)
				{	newpath.pb(k[0]);newpath.pb(num);newpath.pb(ch1);newpath.pb(k[1]);
					pr(newpath);
					return;
				}

			}
			else 
			{
				newpath.pb(k[0]);newpath.pb(ch1);newpath.pb(num);newpath.pb(k[1]);
				pr(newpath);
				return ;
			}
		}
	}
	else if(k.size()==3)
	{	
		int num = find(k[0],k[1]);
		if(num!=-1)
		{
			newpath.pb(k[0]);newpath.pb(num);newpath.pb(k[1]);newpath.pb(k[2]);
			pr(newpath);
			return;
		}
		else
		{
			num = find(k[1],k[2]);

			if(num!=-1)
			{
				newpath.pb(k[0]);newpath.pb(k[1]);newpath.pb(num);newpath.pb(k[2]);
				pr(newpath);
				return;	
			}

		}

	}

	return ;
}

int main()
{	
	scanf("%d%d",&n,&m);
	while(m-->0)
	{	int u,v;
		readint(u);
		readint(v);
		graph[u].pb(v);
	
	}
	for(int i=1;i<=n;i++)dijkstra(i);

	vi path[maxs];
	vi prev_path[maxs];

	FOR(i,1,n+1)
		FOR(j,1,n+1)if(dis[i][j] == MAX_INT)dis[i][j] = -1 * MAX_INT;

	FOR(j,1,n+1)prevdp[j]=0;
	FOR(j,1,n+1)
	{
		path[j].resize(0);
		prev_path[j].resize(0);
	}

	FOR(i,1,4)
	{	FOR(j,1,n+1)dp[j]=0;
		
		FOR(j,1,n+1)previous[j]=-1;
		//cout<<" I "<<i<<endl;

		FOR(j,1,n+1)
		{
			FOR(k,1,n+1)
			{	int obs = 0;
				FOR(l,0,path[j].size())
				{	
					if(path[j][l] == k)obs = 1;
				}
				if(j==k)obs = 1;
				if(!obs)
				{	
					if(dp[k] < prevdp[j] + dis[j][k])
					{
						dp[k] = prevdp[j] + dis[j][k];
						previous[k] = j;
					}
				}

			}
		}


		FOR(j,1,n+1)
		{
			path[j].resize(0);
			if(previous[j] != -1)
			{
				FOR(k,0,prev_path[previous[j]].size())path[j].pb(prev_path[previous[j]][k]);
				path[j].pb(previous[j]);
			}
/*
			cout<<" ind  :"<<j<<" prev :"<<previous[j]<<" cost :"<<dp[j]<<endl; 
			pr(path[j]);
			cout<<" end"<<endl;
*/
		}


		FOR(j,1,n+1)
		{
			prevdp[j] = dp[j];
			prev_path[j].resize(0);
			FOR(k,0,path[j].size())prev_path[j].push_back(path[j][k]);
			
		}

	}

	FOR(j,1,n+1)path[j].pb(j);

	int ma = 0;
	int index = -1;
	FOR(j,1,n+1)
	{
		if(dp[j]>ma)
		{	ma = dp[j];
			index = j;
		}
	}
 	if(index != -1)
 	{
 	
 		if(path[index].size()!=4)
 		{
 			add(path[index]);
 		}
 		else
 		{
 			pr(path[index]);
 		}
 	}

}