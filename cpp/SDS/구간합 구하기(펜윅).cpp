#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long


using namespace std;

vector<ll> tree;
vector<ll> v;

ll sum(ll idx){
	ll res =0;
	while( idx > 0){
		res+= tree[idx];
		idx -= (idx &-idx);
	}
	return res;
} 

void update(ll idx ,ll val){
	while(idx<tree.size()){
		tree[idx] +=val;
		idx += (idx&-idx);
	}
	
	 
}

int main(){
	
	fastio; 
	
	int n,m,k;cin>>n>>m>>k;
	v.resize(n+1,0);
	tree.resize(n+1,0);
	for(int i=1; i<=n ;i++){
		cin>>v[i];
	}
	for(int i=1; i<=n; i++){
		update(i,v[i]);
	}
	
	for(int i=0; i<m+k; i++){
		ll cmd	,a,b;
		cin>>cmd>>a>>b;
		if(cmd==1){
			ll diff=b-v[a];		
			v[a]=b;
			update(a,diff);
			
		}
		else{
			cout<<sum(b) - sum(a-1) <<endl;
		}
	}
	
	return 0;	
}
