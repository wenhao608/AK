#include <bits/stdc++.h>
using namespace std;
int n,a[1000010];
int m;
struct split{//分块
	int siz;//长度 
	int num; //个数
	int gt[10010];//可以获取i所对应的分块的编号(get)
	int st[100010];//第i块开始 
	int ed[100010];//第i块结束 
	int dt[10010];//dt[i]表示第i块的最大公因数
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
			st[i]=(i-1)*siz+1;
			ed[i]=min(siz*i,n);
			for(int j=st[i];j<=ed[i];++j){
				gt[j]=i;
				dt[i]+=a[j];
			}
		} 
	} 
	void modify(int l,int r){
		if(r-l+1<=siz){
			for(int i=l;i<=r;++i){
				if(dt[gt[i]]==0){
					break;
				}
				if(a[i]==1){
					a[i]=0;
					dt[gt[i]]-=1;
				}
			}
			return ;
		}
		for(int i=l;gt[i]==gt[l];++i){
			if(dt[gt[i]]==0){
				break;
			}
			if(a[i]==1){
				a[i]=0;
				dt[gt[i]]-=1;
			}
		}
		for(int i=r;gt[i]==gt[r];--i){
			if(dt[gt[i]]==0){
				continue;;
			}
			if(a[i]==1){
				a[i]=0;
				dt[gt[i]]-=1;
			}
		}
		for(int i=gt[l]+1;i<=gt[r]-1;++i){
			dt[i]=0;
		}
	} 
	int query(int l,int r){
		int res=0;
		if(r-l+1<=siz){
			for(int i=l;i<=r;++i){
				if(dt[gt[i]]==0){
					break;
				}
				res+=a[i];
			}
			return res;
		}
		for(int i=l;gt[i]==gt[l];++i){
			if(dt[gt[i]]==0){
				break;
			}
			res+=a[i];
		}
		for(int i=r;gt[i]==gt[r];--i){
			if(dt[gt[i]]==0){
				break;
			}
			res+=a[i];
		}
		for(int i=gt[l]+1;i<=gt[r]-1;++i){
			if(dt[i]==0){
				continue;;
			}
			res+=dt[i]; 
		}
		return res;
	}
};
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		a[i]=1;
	}
	split node;
	node.init();
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		node.modify(l,r);
		printf("%d\n",node.query(1,n));
	}
	return 0;
} 
