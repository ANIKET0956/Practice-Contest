#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;
typedef long long ll;
#define MAX 100005

char buf[MAX];
int ch[26];
int n,k;
int ind[MAX]={0};

ll abs(ll a)
{
	if(a<0)return -a;

	return a;
}

ll min(ll a,ll b)
{
	return a>b?b:a;
}

int func()
{
	for(int i=0;i<26;i++)ch[i]=0;

	for(int i=0;i<n;i++){
		ch[buf[i]-'a']++;
		ind[i]=0;
	}

	ll ans=100*MAX;
	for(int i=0;i<26;i++)
	{	
		if(ch[i]!=0)
		{	ll diff=0;
			int mini = ch[i];
			int maxi = ch[i]+k;
			for(int j=0;j<26;j++)
			{	if(ch[j]!=0)
				{	if(ch[j]<mini)
					{	diff+=abs(ch[j]);
					}
					if(ch[j]>maxi)
					{	diff+=abs(ch[j]-maxi);
					}
				}
			}
			ans = min(ans,diff);
		}
	}
	


	printf("%lld\n",ans);

	return 0;

}


int main(){
	int t;
	scanf("%d",&t);
	while(t-->0)
	{	
		scanf("%s",buf);
		scanf("%d",&k);
		n=strlen(buf);
		func();
	}


}
