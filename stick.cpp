#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;
int a[110],ans,n,sum=0,b[110];
bool dfs(int id,int x,int y,int mu){
	if(id==sum/mu){
		return true; 
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]+y<mu&&b[i]==0){
			b[i]=1;
			if(dfs(id,i,a[i]+y,mu)) return true;
			
			b[i]=0;
			if(y==0){
				return false;
			}
			while(i+1<=n&&a[i]==a[i+1]){
				i++;
			}
		}
		if(a[i]+y==mu&&b[i]==0){
			b[i]=1;
			if(dfs(id+1,0,0,mu)) return true; 
			b[i]=0;
			return false;
		}
	}
	return false;
}
int read(){
	int x=0,f;
	char c;
	c=getchar();
	while('0'<c||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'>=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
} 
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	while(1){
		scanf("%d",&n);
		if(n==0){
//			break;
		}
		ans=0;
		sum=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			sum+=a[i];
			b[i]=0;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=a[1];i<=sum;++i){
			if(sum%i==0) {
				if(dfs(1,0,0,i)){
					cout << i << '\n';
					break;
				}
			}
		}
	
//	}
	return 0;
}
