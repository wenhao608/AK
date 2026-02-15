#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int n,m;
int gt[1000010];
int st[1000010],ed[1000010];
int dt[1000010];
struct node{
	int siz,num;
	void init(){
		memset(gt,0,sizeof(gt));
		memset(st,0,sizeof(st));
		memset(ed,0,sizeof(ed));
		memset(dt,0,sizeof(dt));
		siz=sqrt(n);
		num=ceil(1.0*n/siz);
		for(int i=1;i<=num;++i){
			dt[i]=0;
			st[i]=(i-1)*siz+1;
			ed[i]=min(siz*i,n);
			for(int j=st[i];j<=ed[i];++j){
				gt[j]=i;
				dt[i]++;
			}
		} 
	} 
	void modify(int x,int l){//点x的值改为l 
		int val=1;//修改的值
		if(l==0){
			val=-1;
		} 
		dt[gt[x]]+=val;
		a[x]=l;
	}
	int query(int x){
		int ans=1,l=x;
		if(a[x]==0){
			return 0;
		}
		int i=gt[x];
		for(int j=x-1;j>=st[i];--j) {
            if (a[j]==1) ans++;
            else break;
        }
        for(int j=x+1;j<=ed[i];++j) {
            if (a[j]==1) ans++;
            else break;
        }
        i++;
		for(;i<=num;++i){
			if(dt[i]==ed[i]-st[i]+1){
				ans+=(ed[i]-st[i]+1);
				l=ed[i];
			}
			else{
				break;
			}
		}
		l++;
		while(l<=n){
			if(a[l]==1){
				ans++;
				l++;
			}
			else{
				break;
			}
		}
		l=x;
		i=gt[x]-1;
		for(;i>=1;--i){
			if(dt[i]==ed[i]-st[i]+1){
				ans+=ed[i]-st[i]+1;
				l=st[i];
			}
			else{
				break;
			}
		}
		i=l-1;
		for(;i>=max(l-siz+1,1);--i){
			if(a[i]==0){
				break;
			}
			ans+=1;
		}
		return ans;
	}
};
int main(){
	stack<int> s;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		a[i]=1;
	} 
	node split;
	split.init();
	while(m--){
		char c;
		cin >> c;
		if(c=='Q'){
			int x;
			cin >> x;
			
			cout << split.query(x) << '\n';
		}
		else if(c=='R'){
			int x=s.top();
			s.pop();
			split.modify(x,1);
		}
		else{
			int x;
			cin >> x;
			s.push(x);
			split.modify(x,0);
		}
	}
	return 0;
}
