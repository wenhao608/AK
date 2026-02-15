#include <bits/stdc++.h>
using namespace std;
int ans=1,ans_sum=1e9;
int n;
struct Node {
    vector<int>c;
    int f=-1;
    int size=1;
    int sum=0;
}a[1000010];

void dfs1(int id,int f) {
    a[id].f=f;
	a[id].size=1;
    a[id].sum=0;
    for (int i=0;i<a[id].c.size();++i) {
        int child=a[id].c[i];
		if(a[id].c[i]==f) continue;
        dfs1(a[id].c[i],id);
        a[id].size+=a[child].size;
        a[id].sum+=a[child].sum+a[child].size;
    }
}
void dfs2(int id,int f,int fsum) {
    int total=(f==-1) ? a[id].sum:fsum+a[id].sum;
    if (total<ans_sum||(total==ans_sum&&id<ans)) {
        ans_sum=total;
        ans=id;
    }
    for (int i=0;i<a[id].c.size();++i) {
        int child=a[id].c[i];
		if(a[id].c[i]==f) continue;
        dfs2(a[id].c[i],id,total-a[child].sum-a[child].size+n-a[child].size);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        a[x].c.push_back(y);
        a[y].c.push_back(x);
	}
    dfs1(1,-1);
    a[1].sum=0;
    for (int i=0; i<a[1].c.size();++i){
    	a[1].sum+=a[a[1].c[i]].sum+a[a[1].c[i]].size;
	}
    dfs2(1,-1,0);
    cout << ans << " " << ans_sum;
    return 0;
}
