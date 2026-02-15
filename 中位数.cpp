#include <bits/stdc++.h>
using namespace std;
int size=0,size1=0,heap[1000010],heap1[1000010];
void insert1(int x){
	heap1[++size1]=x;
	int i=size1;
	while(i!=1&&x<heap1[i/2]){
		heap1[i]=heap1[i/2];
		i/=2;
	}
	heap1[i]=x;
}
void insert(int x){
	heap[++size]=x;
	int i=size;
	while(i!=1&&x>heap[i/2]){
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=x;
}
void del(){
	int val=heap[size--];
	int t=1,ch=2;
	while(ch<=size){
		if(ch<size&&heap[ch]<heap[ch+1]){
			ch++;
		}
		if(heap[ch]<=val){
			break;
		}
		heap[t]=heap[ch];
		t=ch;
		ch=t*2;
	}
	heap[t]=val;
} 
void del1(){
	int val=heap1[size1--];
	int t=1,ch=2;
	while(ch<=size1){
		if(ch<size1&&heap1[ch]>heap1[ch+1]){
			ch++;
		}
		if(heap1[ch]>=val){
			break;
		}
		heap1[t]=heap1[ch];
		t=ch;
		ch=t*2;
	}
	heap1[t]=val;
} 
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		int x;
		cin >> x;
		if(x<=heap[1]){
			insert(x);
		}
		else{
			insert1(x);
		}
		if(size<size1){
			insert(heap1[1]);
			del1();
		}
		if(size>size1+1){
			insert1(heap[1]);
			del();
		}
		if(i%2==1){
			cout << heap[1] << '\n';
		}
	}
	return 0;
}
