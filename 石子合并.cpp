#include<bits/stdc++.h>
using namespace std;
int sum[100010];
int a[110];
int f[110][110],f1[110][110];
int n;
int add(int s,int len){
	int e=(s+len-1)%n;;
	if(e>s){
		return sum[e]-(s==0?0:sum[s-1]);
	}
	return sum[n-1]-(s==0?0:sum[s-1])+sum[e];
}
int main(){
	memset(f,0x3f,sizeof(f));
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> a[i];
		if(i==0){
			sum[i]=a[i];
		}
		else sum[i]=a[i]+sum[i-1];
		f[i][1]=0;
		f1[i][1]=0;
	}
	for(int j=2;j<=n;++j){//长度
		for(int i=0;i<n;++i){//起始点
			for(int k=1;k<j;++k){
				f[i][j]=min(f[i][j],f[i][k]+f[(i+k)%n][j-k]+add(i,j));
				f1[i][j]=max(f1[i][j],f1[i][k]+f1[(i+k)%n][j-k]+add(i,j));
			}
		}
	}
	int minn=1e9,maxn=-1e9;
	for(int i=0;i<n;++i){
		minn=min(minn,f[i][n]);
		maxn=max(maxn,f1[i][n]);
	}
	cout << minn << '\n' << maxn;
	return 0;
}
