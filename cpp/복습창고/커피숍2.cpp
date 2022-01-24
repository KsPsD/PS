#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"

using namespace std;

const int MAX  = 100001;

ll sarr[MAX];
ll tree[MAX];
int n,q;


ll query(ll idx){
	ll ret= 0;	
	while(idx){
		ret += tree[idx];
		idx -=(idx & -idx);
	}
	
	return ret;
}

void update(ll idx ,ll val){
	while(idx<=n){
		tree[idx] +=val;
		idx +=(idx & -idx);
	}
}



int main(){
	
	
	cin>>n>>q;
	
	for(int i=1; i<=n; i++){
		ll num;
		cin >> num;
		sarr[i] = num;
		update(i,num);
	}
	
	
	
	for(int i=0 ; i<q; i++){
		ll x,y,a,b;
		cin>>x>>y>>a>>b;
		if(y<x) swap(x,y);
		cout<<query(y) - query(x-1)<<endl;
		ll diff= b-sarr[a]; 
		update(a,diff);
		sarr[a] =b;
	}
	
	
	return 0;
} 
