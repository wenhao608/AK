#include <bits/stdc++.h>
using namespace std; 
long long h,x,y,z,ans=1,gcr;
int vis[1000010];
long long gcd(long long x,long long y){
	if(y==0){
		return x;
	}
	return gcd(y,x%y);
}
void bfs(){
	priority_queue<long long,vector<long long>,greater<long long> > q;
	q.push(y);
	q.push(z);
	if(vis[y%x]==0){
		vis[y%x]=1;
		ans+=(h-y-1)/x+1;
	}
	if(vis[z%x]==0){
		vis[z%x]=1;
		ans+=(h-z-1)/x+1;
	}
	while(q.size()){
		long long nd=q.top();
		q.pop();
		if(nd+y<=gcr&&vis[(nd+y)%x]==0&&nd+y<=h){
			vis[(nd+y)%x]=1;
			ans+=(h-nd-y-1)/x+1;
			q.push(nd+y);
		}
		if(nd+z<=gcr&&vis[(nd+z)%x]==0&&nd+z<=h){
			vis[(nd+z)%x]=1;
			ans+=(h-nd-z-1)/x+1;
			q.push(nd+z);
		}
	}
}
int main(){
	cin >> h >> x >> y >> z;
	h--;
	vis[0]=1;
	ans+=h/x;
	while(!(x<=y&&y<=z)){
		if(x>y){
			swap(x,y);
		}
		if(y>z){
			swap(y,z);
		}
	}
	
	gcr=x*y/gcd(x,y);
	gcr=gcr*z/gcd(gcr,z);
	bfs();
	cout << ans;
	return 0;
}
