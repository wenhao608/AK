#include <bits/stdc++.h>
using namespace std;
int h[1000010],len=0;
void add(int x){
	h[++len]=x;
	int l=len;
	while(l!=1){
		if(h[l/2]>x){
			swap(h[l/2],h[l]);
			l/=2;
		}
		else{
			break;
		}
	}
}
void del(int x){
	int val=h[len--];
	int t=1,ch=2;
	while(ch<=len){
		if(ch<len&&h[ch]>h[ch+1]){
			ch++;
		}
		if(h[ch]>=val){
			break;
		}
		h[t]=h[ch];
		t=ch;
		ch=t*2;
	}
	while(x>1&&val<h[x/2]){
		h[x]=h[x/2];
		x/=2;
	}
	h[t]=val;
} 
int main(){
	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		if(t==1){
			int x;
			cin >> x;
			add(x);
		}
		if(t==2){
			cout << h[1] << '\n';
		}
		if(t==3){
			del(1);
		}
	}
	return 0;
}
