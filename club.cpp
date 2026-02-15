#include <bits/stdc++.h>
using namespace std;
int a[5];
void solve(){
	int n;
	long long ans=0;
	cin >> n;
	priority_queue<int> q[4];
	for(int i=1;i<=n;++i){
		cin >> a[1] >> a[2] >> a[3];
		
		int id=1,maxn=a[1];
		if(maxn<a[2]){
			maxn=a[2];
			id=2;
		}
		if(maxn<a[3]){
			maxn=a[3];
			id=3;
		}
		int mid = 0;
        if(id==1) {
            mid=max(a[2],a[3]);
        }
		else if(id==2){
            mid=max(a[1],a[3]);
        }
		else{
            mid=max(a[1],a[2]);
        }
		q[id].push(maxn-mid);
		ans+=maxn;
	}     
	while(1){
		for(int i=1;i<=3;++i){
			if((int)q[i].size()>n/2){
				while((int)q[i].size()>n/2){
					ans-=q[i].top();
					q[i].pop();
				}
			}
		}
		bool ck=false;
		for(int i=1;i<=3;++i){
			if((int)q[i].size()>n/2){
				ck=true;
				break;
			}
		}
		if(!ck){
			break;
		}
	}
	
	cout << ans << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
