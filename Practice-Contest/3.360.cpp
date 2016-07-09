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
 
int color[maxs];
int mark[maxs];
vvi graph(maxs);
int dfs(int ind,int p)
{
	color[ind]= !color[p];
	mark[ind]=1;

	int fail = 0;
	FOR(i,0,graph[ind].size())
	{
		int ch = graph[ind][i];
		//cout<<ch<<endl;
		if(mark[ch]==0)
		{	
			int ret = dfs(ch,ind);
			if(ret==-1)return -1;
		}
		else
		{
			if(color[ind]==color[ch])
			{
				fail = 1;
			}
		}
		//cout<<" "<<ind<<" "<<ch<<" "<<fail<<endl;
		if(fail)break;
	}

	if(fail)return -1;

	return 0;
}

 int main()
 {
 	int n,m;
 	scanf("%d%d",&n,&m);

 	//cout<<m<<endl;
 	FOR(i,0,m)
 	{
 		int k1,k2; 
 		scanf("%d%d",&k1,&k2);

 		graph[k1].pb(k2);
 		graph[k2].pb(k1);


 	}

 	FOR(i,0,maxs)
 	{
 		color[i]=-1;
 		mark[i]=0;
 	}

 	mark[0]=1;
 	color[0]=0;
    
    int ret = 0;

    FOR(i,1,n+1)
   	{
   		if(mark[i]==0)
   		{
   			ret = dfs(i,0);
   			if(ret==-1)break;
   		}
   	}


    if(ret==-1)printf("%d\n",-1);
    else
    {
    	int c_zero=0,c_one=0;
    	FOR(i,1,n+1)
    	{
    		if(color[i]==0)c_zero++;
    		if(color[i]==1)c_one++;
    	//	if(color[i]==-1)cout<<"see"<<endl;
    	}
    	printf("%d\n",c_zero);
    	FOR(i,1,n+1)
    	{
    		if(color[i]==0)printf("%d ",i);
    	}
    	
    	printf("\n%d\n",c_one);
    	FOR(i,1,n+1)
    	{
    		if(color[i]==1)printf("%d ",i);
    	}
    	printf("\n");
    }

 }