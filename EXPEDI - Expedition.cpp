#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,sum,use;
}a[1000010];
bool cmp(node a,node b){
	return a.l<b.l;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		bool chk=true;
		int n;
		cin >> n;
		for(int i=1;i<=n;++i){
			cin >> a[i].l >> a[i].sum;
			a[i].use=0;
		}
		int l,p;
		cin >> l >> p;
		for(int i=1;i<=n;++i){
			a[i].l=l-a[i].l;
		}
		
		int ans=0,sum=0,sh=p;
		a[++n].l=l;
		a[n].sum=0;
		sort(a+1,a+1+n,cmp);
		priority_queue<int> q;
		for(int i=1;i<=n;++i){
			
			int b=a[i].l-sum;
			while(sh<b){
            	if(q.empty()){
                	ans=-1;
                	chk=false;
                	break;
            	}
            	ans++;
            	sh+=q.top();
            	q.pop();
        	}
        	if(!chk){
        		break;
			} 
			sh-=b;
        	q.push(a[i].sum);
        	sum=a[i].l;
		}
		cout << ans << '\n';
	}
	return 0;
} 
