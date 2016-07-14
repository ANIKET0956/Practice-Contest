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
#define MaxVal 20000005
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


int n,m;
int l,k;


int tree[MaxVal+5];
int arr[1005][1005];


void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}


int hob (int num)
{
    if (!num)
    	return 0;
    int ret = 1;
    while (num >>= 1)
    	ret <<= 1;
    return ret;
}

int find(int cumFre){
    int idx = 0; // this var is result of function
    
    cout<<cumFre<<endl;

    int bitMask =  hob(MaxVal);

    while ((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
        int tIdx = idx + bitMask; // we make midpoint of interval
        cout<<tIdx<<" "<<cumFre<<endl;
        if (cumFre == tree[tIdx]) // if it is equal, we just return idx
            return tIdx;
        else if (cumFre > tree[tIdx]){ 
                // if tree frequency "can fit" into cumFre,
                // then include it
            idx = tIdx; // update index 
            cumFre -= tree[tIdx]; // set frequency for next loop 
        }
        bitMask >>= 1; // half current interval
    }
    
    cout<<"mid"<<tree[idx]<<" "<<idx<<" "<<read(idx)<<endl;

    if (cumFre != 0) // maybe given cumulative frequency doesn't exist
        return -1;
    else
        return idx;



}



int solve()
{	int posx = 0;
	int posy = 0;

	int middle = (k*l)/2+1;

	vi ans;

	FOR(i,0,k)
	{	FOR(j,0,l)
		{
			update(arr[posx+i][posy+j],1);
		}
	}

	int findind = find(middle);

	//ans.pb(findind);

	//ans.pb(find(8));


	posy++;

	int count=0,left,right;

	left=0;
	right=1;

/*	while(posx+k<=n)
	{	
		cout<<posx<<" "<<posy<<endl;

		while(posy+l<=m and posy >=0)
		{
			FOR(i,0,k)
			{
				if(right){
					update(arr[posx+i][posy-1],-1);
					update(arr[posx+i][posy+l-1],1);
				}
				else if(left)
				{	update(arr[posx+i][posy],1);
					update(arr[posx+i][posy+l],-1);
				}
			}

			ans.pb(find(middle));


			if(left)posy--;
			if(right)posy++;
		}

		if(posy+l>m)posy--;
		if(posy<0)posy++;

		posx++;
		count++;

		left=count%2;
		right=1-left;

		FOR(i,0,l)
		{
			update(arr[posx-1][posy+i],-1);
			update(arr[posx][posy+i],1);
		}

		ans.pb(find(middle));

		if(left)posy--;
		if(right)posy++;

	}

*/
}


int main()
{
	int q;
	scanf("%d%d%d",&n,&m,&q);

	FOR(i,0,n)
	{
		FOR(j,0,m)scanf("%d",&arr[i][j]);
	}

	while(q-->0)
	{

		FOR(i,0,MaxVal)tree[i]=0;

		scanf("%d%d",&k,&l);

		solve();


	}



}