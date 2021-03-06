/* 
	Practice for Segment Tree
*/

#include <iostream>
#include <string.h>

#define MAX 400005
typedef long long ll;
using namespace std;

int n,q;
ll count1[MAX][3]={0};
ll count2[MAX][3]={0};
ll sumt[MAX]={0};
ll arr[MAX]={0};
ll seg[MAX][3]={0};

void merge(int index)
{
	//cout<<"Index "<<index<<endl;

	for(int i=0;i<3;i++)
	{	count1[index][i]=count1[2*index][i]+count1[2*index+1][(i-sumt[2*index]+3)%3];
		count2[index][i]=count2[2*index+1][i]+count2[2*index][(i-sumt[2*index+1]+3)%3];
		seg[index][i] = seg[2*index][i] + seg[2*index+1][i];
	}
	for(int i=0;i<3;i++)
	{	for(int k=0;k<3;k++)
		{	seg[index][i] += count2[2*index][k]*count1[2*index+1][(i-k+3)%3];
		}
		//cout<<seg[index][i]<<" "<<i<<endl;
	}


	sumt[index]=(sumt[2*index]+sumt[2*index+1])%3;
}
void nodeupdate(int index,int val)
{	for(int i=0;i<3;i++)
	{	count1[index][i]=0;count2[index][i]=0;seg[index][i]=0;
	}
	sumt[index]=0;
	count1[index][val%3]++;
	count2[index][val%3]++;
	sumt[index]=val%3;
	seg[index][val%3]++;
}

int construct(int ss, int se, int index)
{	if(ss==se)
	{	count1[index][arr[ss]%3]++;
		count2[index][arr[ss]%3]++;
		sumt[index]=arr[ss]%3;
		seg[index][arr[ss]%3]++;
		return 0;
	}
	//cout<<ss<<" SS "<<" SE "<<se<<endl; 

	int mid = (ss+se)/2;
	construct(ss,mid,2*index);
	construct(mid+1,se,2*index+1);
	merge(index);
	return 0;
}
void update(int ss,int se,int index,int val,int loc)
{	if(loc < ss || loc > se || ss > se)return ;

	if(ss==se)
	{	nodeupdate(index,val);
		return;
	}
	int mid=(ss+se)/2;
	update(ss,mid,2*index,val,loc);
	update(mid+1,se,2*index+1,val,loc);
	merge(index);
}
struct Node{
	ll seg;
	ll cou1[3];
	ll cou2[3];
	ll sumt;
	Node()
	{	sumt=0;seg=0;
		for(int i=0;i<3;i++)
		{	cou1[i]=0;cou2[i]=0;
		}
	}
};

Node query(int ss,int se,int index,int qs,int qe)
{	
	//cout<<"Index "<<index<<qs<<qe<<endl;
	Node ans;
	if(ss > se || ss > qe || qs > se )
	{	ans.seg=0;
		for(int i=0;i<3;i++)
		{	ans.cou1[i]=0;ans.cou2[i]=0;
		}
		ans.sumt=0;
		return ans;

	}
	if( ss >= qs && se <= qe)
	{	ans.seg = seg[index][0];
		for(int i=0;i<3;i++)
		{	ans.cou1[i]=count1[index][i];
			ans.cou2[i]=count2[index][i];
		}
		ans.sumt = sumt[index];
		return ans;
	}
	Node ans1,ans2;

	int mid=(ss+se)/2;
	ans1 =query(ss,mid,2*index,qs,qe);
	ans2 =query(mid+1,se,2*index+1,qs,qe);
	
	ans.seg = ans1.seg+ans2.seg;
	ans.sumt = (ans1.sumt+ans2.sumt)%3;
	for(int i=0;i<3;i++)ans.seg += ans1.cou2[i]*ans2.cou1[(3-i)%3];

	for(int i=0;i<3;i++)
	{	ans.cou1[i]=ans1.cou1[i]+(ans2.cou1[(i-ans1.sumt+3)%3]);
		ans.cou2[i]=ans2.cou2[i]+(ans1.cou2[(i-ans2.sumt+3)%3]);
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&q);
	char buf[MAX];
	scanf("%s",buf);
	for(int i=0;i<n;i++)
	{
		arr[i]=buf[i]-'0';
	}
	construct(0,n-1,1);
	
	while(q-->0)
	{
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		k2--;
		if(k1==1)
		{
			arr[k2]=k3;
			update(0,n-1,1,k3,k2);
		}
		else if(k1==2)
		{
			k3--;
			printf("%lld\n",query(0,n-1,1,k2,k3).seg);
		}
	}
	
}





