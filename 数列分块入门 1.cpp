#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010];
struct split{//分块
	int siz;//长度 
	int num; //个数
	int gt[10010];//可以获取i所对应的分块的编号(get)
	int st[100010];//第i块开始 
	int ed[100010];//第i块结束 
	int dt[10010];//dt[i]表示第i块的最大公因数
	int sum[10010];
	/*
	1->1,size
	2->size+1,2*size
	3->size*2,size*3+1
	...
	num->size**(num-1),n
	*/ 
	void init(){
		siz=sqrt(n);
		num=ceil(1.0*n/siz);
		for(int i=1;i<=num;++i){
			sum[i]=0;
			st[i]=(i-1)*siz+1;
			ed[i]=min(siz*i,n);
			for(int j=st[i];j<=ed[i];++j){
				gt[j]=i;
				sum[i]+=a[j];
			}
		} 
	} 
	void modify(int l,int r,int c){
		if(r-l+1<=siz){
			for(int i=l;i<=r;++i){
				a[i]+=c;
				sum[gt[i]]+=c;
			}
			return ;
		}
		for(int i=l;gt[i]==gt[l];++i){
			a[i]+=c;
			sum[gt[i]]+=c;
		}
		for(int i=r;gt[i]==gt[r];--i){
			a[i]+=c;
			sum[gt[i]]+=c;
		}
		for(int i=gt[l]+1;i<=gt[r]-1;++i){
			dt[i]+=c;
			sum[i]+=c*(ed[i]-st[i]+1);
		}
	} 
	int query(int l,int r){
		int res=0;
		if(r-l+1<=siz){
			for(int i=l;i<=r;++i){
				res+=a[i]+dt[gt[i]];
			}
			return res;
		}
		for(int i=l;gt[i]==gt[l];++i){
			res+=a[i]+dt[gt[i]];
		}
		for(int i=r;gt[i]==gt[r];--i){
			res+=a[i]+dt[gt[i]];
		}
		for(int i=gt[l]+1;i<=gt[r]-1;++i){
			res+=sum[i];
		}
		return res;
	}
};
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	split node;
	node.init();
	for(int i=1;i<=n;++i){
		int opt,l,r,c;
		scanf("%lld%lld%lld%lld",&opt,&l,&r,&c);
		if(opt==0){
			node.modify(l,r,c);
		}
		
		else{
			cout << node.query(r,r) << '\n';
		}
	}
	return 0;
} 
