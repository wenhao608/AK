#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node* nxt;
}
node* head=new node{0, nullptr};
int n;
void init(node* h,int val){
	if(val==n+1){
		h->nxt=head->nxt;
		return ;
	}
	h->nxt=new node{val,nullptr};
	init(h->nxt,val+1);
}
int main(){
	int m;
	cin >> n >> m;;
	init(head,1);
	node* t=head->nxt;
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j){
			t=t->nxt;
		}
		node* k=t->nxt;
		node* u=k->nxt;
		t->nxt=u;
		cout << k->val << ' ';
		delete k;
	}
	return 0;
}
