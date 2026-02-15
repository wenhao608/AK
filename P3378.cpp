#include <bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> > q;
	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		if(t==1){
			int x;
			cin >> x;
			q.push(x);
		}
		else if(t==2){
			cout << q.top() << '\n';
		}
		else{
			q.pop();
		}
	}
	return 0;
}
