#include <bits/stdc++.h>
using namespace std;
int size=0,heap[1000010];
void insert(int x){
	heap[++size]=x;
	int i=size;
	while(i!=1&&x<heap[i/2]){
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=x;
}
void del(){
	int val=heap[size--];
	int t=1,ch=2;
	while(ch<=size){
		if(ch<size&&heap[ch]>heap[ch+1]){
			ch++;
		}
		if(heap[ch]>=val){
			break;
		}
		heap[t]=heap[ch];
		t=ch;
		ch=t*2;
	}
	heap[t]=val;
} 
void del2(int x){
	int val=heap[size--];
	int ch=x*2;
	while(ch<=size){
		if(ch<size&&heap[ch]>heap[ch+1]){
			ch++;
		}
		if(heap[ch]<=val){
			break;
		}
		heap[x]=heap[ch];
		x=ch;
		ch=x*2;
	}
	while(x>1&&val<heap[x/2]){
		heap[x]=heap[x/2];
		x/=2;
	}
	heap[x]=val;
} 
void dec(int i,int x){
	while(i!=1&&x<heap[i/2]){
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=x;
}
int main(){
	int m;
	cin >> m;
	while(m--){
		int x;
		cin >> x;
		if(x==1){
			int y;
			cin >> y;
			insert(y);
		}
		if(x==2){
			del();
		}
		if(x==3){
			int i;
			cin >> i; 
			del2(i);
		} 
		if(x==4){
			int i,y;
			cin >> i >> y;
			dec(i,y);
		}
	}
	sort(heap+1,heap+1+size);
	for(int i=1;i<=size;++i){
		cout << heap[i] << ' ';
	}
	return 0;
}
