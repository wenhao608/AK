#include <bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010],c[1000010],w[1000010],v[1000010],f[1000010];
int x,y,x2,y2,n,cnt=0;
void init(){
	for(int i=1;i<=n;++i){
		int x=1;
		while(c[i]!=0){
			w[++cnt]=a[i]*x;
			v[cnt]=b[i]*x;
			x*=2;
			c[i]-=x/2;
			if(c[i]<x){
				w[++cnt]=a[i]*c[i];
				v[cnt]=b[i]*c[i];
				break;
			}
		}
	}
}
int main(){
	
	scanf("%d:%d %d:%d",&x,&y,&x2,&y2);
	cin >> n;
	if(y>y2){
        y2+=60;
        x2--;
    }
    int m=(x2-x)*60+y2-y;
    for(int i=1;i<=n;i++){
    	cin >> a[i] >> b[i] >> c[i];
    	if(c[i]==0){
    		c[i]=m;
		}
    }
    init();
    for(int i=1;i<=cnt;++i){
    	for(int j=m;j>=w[i];--j){
    		f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout << f[m];
	return 0;
}
