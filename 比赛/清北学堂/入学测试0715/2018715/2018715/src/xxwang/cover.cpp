#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct str
{
    long long l; long long r;
}st[1000001];

long long i,rr,k,ll,maxn,n,m,len;

bool cmp(str x,str y)
{
    return x.l<y.l;
}

int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
    cin>>n>>k;
    for (i=1; i<=n; i++)
	{
        cin>>st[i].l>>st[i].r;
		len=max(st[i].r-st[i].l,len);//k=1����� 
	}
	if(k==1)
	{
		printf("%lld",len);
		return 0;
	}
    sort(st+1,st+n+1,cmp);
    ll=st[1].l; rr=st[1].r;//a��ʾ������˵㣬s��ʾ�Ҷ˵�
    while(k>0)//m�����䳤�ȣ�������Ͽ�ʱ���¶˵㲢���㳤��
	{
        for (i=2; i<=n; i++)
    	{
            if (st[i].l>rr)
	        {  
		       m+=rr-ll+1; 
	           ll=st[i].l; 
	           rr=st[i].r; 
	           continue;
	        }
        else 
          if (st[i].r>rr) rr=st[i].r;//��������Ҷ˵�
        }
        k--;
	}
    cout<<m+rr-ll;
    return 0;
}
