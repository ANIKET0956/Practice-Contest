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
#include <cmath>


using namespace std;
#define gc getchar
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define maxs 1200005
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
#define max_s 300000

bool comp(pi& a,int b)
{	if(a.fi<=b)return 1;
	else return 0; 
}


vector < vpi > tree(maxs);
int timest=0;
pi node[maxs];
int mark[maxs];
int size[maxs];
vector< vpi > tim(maxs);
vvi graph(maxs);

int dfs(int index)
{
	timest++;
	node[index].fi = timest;
	mark[index]=1;
	int number=1;

	FOR(i,0,graph[index].size())
	{	
		int ch = graph[index][i];
		if(!mark[ch])
		{
			number += dfs(ch);
		}
	}

	node[index].se = timest;

	tim[node[index].fi].pb(make_pair(number,index));

	//cout<<timest<<" "<<index<<" "<<number<<endl;
	size[index] = number;

	return number;

}

int buildseg(int ind,int start,int end)
{


	if(start==end)
	{
		tree[ind]=tim[start];
		return 0;
	}

	if(start > end)
	{
		return 0;
	}


	int mid =start + (end-start)/2;
	buildseg(2*ind,start,mid);
	buildseg(2*ind+1,mid+1,end);

	tree[ind].resize(tree[2*ind].size()+tree[2*ind+1].size());

	merge(tree[2*ind].begin(),tree[2*ind].end(),tree[2*ind+1].begin(),tree[2*ind+1].end(),tree[ind].begin());



	return 0;
}

pi min(pi &a,pi &b)
{
	return ((a.fi<b.fi || (a.fi==b.fi and a.se<b.se) ) ? a : b ) ; 
}

std::vector< pi >::iterator it;

pi read(int ind , int l ,int r, int rl, int rr,pi val)
{
	if(r < rl || rr < l)
	{
		return make_pair(INT_MAX,INT_MAX);
	}
	if(l >= rl and r <= rr)
	{
	    it = std::lower_bound(tree[ind].begin(),tree[ind].end(),val);
		if(it==tree[ind].end())
		{
			return make_pair(INT_MAX,INT_MAX);
		}
		else
		{
			//cout<<(*it).fi<<" "<<(*it).se<<endl;
			return *it;
		}
	}

	int mid= l + (r-l)/2;
	return min(read(2*ind,l,mid,rl,rr,val),read(2*ind+1,mid+1,r,rl,rr,val));

}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);

	FOR(i,2,n+1)
	{
		int k;
		scanf("%d",&k);
		graph[k].pb(i);
	}

	dfs(1);

	buildseg(1,1,n);

	while(q-->0)
	{	int nod;
		scanf("%d",&nod); 
		cout<<read(1,1,n,node[nod].fi,node[nod].se,make_pair((size[nod]+1)/2,0)).se<<endl;

	}



}