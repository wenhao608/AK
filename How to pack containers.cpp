#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,d=0,ans=0;
		bool chk=true;
		cin >> n;
		priority_queue<int,vector<int>,greater<int> > q[10010];
		for(int i=1;i<=n;++i){
			int x,y;
			cin >> x >> y;
			d=max(d,x);
			q[x].push(y);
		}
		cin >> m;
		for(int i=1;i<=m;i++){
			int x;
            cin >> x;
            d=max(d,x);
            cin >> a[x];
        }
        for(int i=0;i<=d;++i){
        	while(a[i]--){
        		if(q[i].size()==0){
        			chk=false;
        			cout << "No" << '\n';
        			break;
				}
				ans+=q[i].top();
				q[i].pop();
			}
			while(q[i].size()){
            	int u=q[i].top();
            	q[i].pop();
            	if(q[i].empty())break;
        		int e=q[i].top();
        		q[i].pop();
            	q[i+1].push(e+u);
            }
		}
		if(chk) cout << ans<< '\n';
	}
	return 0;
}
