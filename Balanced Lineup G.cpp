#include <bits/stdc++.h>
using namespace std;
int tr_max[1000010],a[1000010],n,tr_min[1000010];
int lowbit(int x){
	return x&-x;
} 
int sum_max(int l,int r){
	if(l>r){
		return 0;
	}
	if(l<=r-lowbit(r)+1){
		return max(tr_max[r],sum_max(l,r-lowbit(r)));
	}
	return max(a[r],sum_max(l,r-1));
}
int sum_min(int l,int r){
	if(l>r){
		return 0;
	}
	if(l<=r-lowbit(r)+1){
		return min(tr_min[r],sum_min(l,r-lowbit(r)));
	}
	return min(a[r],sum_min(l,r-1));
}
void add_max(int x,int y){
	if(x>n){
		return ;
	}
	tr_max[x]=max(tr_max[x],y);
	add_max(x+lowbit(x),y);
}
void add_min(int x,int y){
	if(x>n){
		return ;
	}
	tr_min[x]=min(tr_min[x],y);
	add_min(x+lowbit(x),y);
}
int main(){
	cin >> n;
	int q;
	cin >> q;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		tr_min[i]=a[i];
		tr_max[i]=a[i];
		add_min(i,a[i]);
		add_max(i,a[i]);
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << sum_max(l,r)-sum_min(l,r) << '\n';
	}
	return 0;
}
//
//#include <bits/stdc++.h>
//using namespace std;
//using ll = long long;
//
//ll n, q;
//ll a[1000100];
//
//struct Tree_Max {
//  ll n;
//  ll tr[1000100];
//
//  /**
//   * tr[i] 维护的是原数组 (i - lowbit(i), i] 这一部分的信息
//   */
//
//  Tree_Max(ll len, ll a[]) {
//    n = len;
//    for (ll i = 1; i <= n; i++) tr[i] = a[i];
//    for (ll i = 1; i <= n; i++) update(i, a[i]);
//  }
//
//  ll lowbit(ll x) { return x & -x; }
//
//  // 向上更新
//  void update(ll p, ll x) {
//    if (p > n) return;
//    tr[p] = max(tr[p], x);  // 更新最大值
//    update(p + lowbit(p), x);
//  }
//
//  // 如何查找区间 [l, r] 的最大值
//  ll query(ll l, ll r) {  // 时间复杂度：log^2
//    /**
//     * [l, r]
//     * tr[r] -> (r - lowbit(r), r]
//     *
//     * 如果 [l, r] 包含了 (r - lowbit(r), r]
//     * 那么 (r - lowbit(r), r]的最大值就不需要 for 循环枚举了，
//     * 已经积累到 tr[r] 这个位置中
//     */
//    if (r <= l) return a[l];
//    else if (l <= r - lowbit(r) + 1) return max(tr[r], query(l, r - lowbit(r)));
//    else return max(a[r], query(l, r - 1));
//  }
//};
//
//struct Tree_Min {
//  ll n;
//  ll tr[1000100];
//
//  /**
//   * tr[i] 维护的是原数组 (i - lowbit(i), i] 这一部分的信息
//   */
//
//  Tree_Min(ll len, ll a[]) {
//    n = len;
//    for (ll i = 1; i <= n; i++) tr[i] = a[i];
//    for (ll i = 1; i <= n; i++) update(i, a[i]);
//  }
//
//  ll lowbit(ll x) { return x & -x; }
//
//  // 向上更新
//  void update(ll p, ll x) {
//    if (p > n) return;
//    tr[p] = min(tr[p], x);  // 更新最大值
//    update(p + lowbit(p), x);
//  }
//
//  // 如何查找区间 [l, r] 的最大值
//  ll query(ll l, ll r) {  // 时间复杂度：log^2
//    /**
//     * [l, r]
//     * tr[r] -> (r - lowbit(r), r]
//     *
//     * 如果 [l, r] 包含了 (r - lowbit(r), r]
//     * 那么 (r - lowbit(r), r]的最大值就不需要 for 循环枚举了，
//     * 已经积累到 tr[r] 这个位置中
//     */
//    if (r <= l) return a[l];
//    else if (l <= r - lowbit(r) + 1) return min(tr[r], query(l, r - lowbit(r)));
//    else return min(a[r], query(l, r - 1));
//  }
//};
//
//int main() {
//  cin >> n >> q;
//  for (ll i = 1; i <= n; i++) cin >> a[i];
//
//  Tree_Max tmx(n, a);
//  Tree_Min tmi(n, a);
//
//  while (q--) {  // n * (log^2)
//    ll l, r;
//    cin >> l >> r;
//    // 找区间的最大值、最小值
//    cout << tmx.query(l, r) - tmi.query(l, r) << '\n';
//  }
//
//  return 0;
//}
