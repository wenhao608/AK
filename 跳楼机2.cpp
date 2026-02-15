#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h, x, y, z;
ll vis[100010];
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    ll g=gcd(gcd(x,y),z);
    if(g==0){
        cout << 1 << endl;
        return;
    }
    x/=g;
	y/=g;
	z/=g;
    h=(h-1)/g;
    for(int i=0;i<=x;++i){
    	vis[i]=1e18;
	}
    vis[0]=0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0,0});
    while (!pq.empty()) {
        auto current=pq.top();
        pq.pop();
        ll dist=current.first;
        int u=current.second;
        if (dist>vis[u]) continue;
        int v=(u + y) % x;
        if (vis[v]>dist + y) {
            vis[v]=dist + y;
            pq.push({vis[v], v});
        }
        v=(u+z)%x;
        if(vis[v]>dist+z) {
            vis[v]=dist+z;
            pq.push({vis[v],v});
        }
    }
    ll ans=0;
    for (int i=0;i<x;++i) {
        if (vis[i]<=h) {
            ans+=(h-vis[i])/x+1;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> h >> x >> y >> z;
    solve();
    return 0;
}
