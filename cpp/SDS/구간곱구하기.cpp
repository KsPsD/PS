#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<int ,int> 
using namespace std;

#define MAX 10000001
#define MOD 1000000007

 vector<ll>arr;
 vector<ll> tree;


ll update(int node ,int s,int e, int idx, int val){
	if(idx<s|| idx>e) return tree[node];
	if(s==e) return tree[node] =val;
	
	int mid  = (s+e)/2;
	ll lt = update(2*node, s, mid, idx, val) %MOD;
	ll rt =update(2*node+1, mid+1, e, idx,val) %MOD;
	
	return tree[node] = (lt * rt) %MOD;
	
}

ll query(int node, int s,int e, int lt,int rt){
	if( rt<s || e< lt) return 1;
	if(lt<=s && e<=rt) return tree[node];
	int mid = (s+e)/2;
	
	
	return ( query(2*node, s,mid,lt,rt) *query(2*node+1, mid+1, e, lt,rt) ) %MOD;
}

ll init(int n, int s, int e){
	if(s==e) return tree[n] = arr[s] %MOD;
	int mid =(s+e)/2;
	return tree[n] = (init(n*2, s,mid) * init(n*2+1, mid+1, e)) %MOD;
}



int main(){
	fastio;
	int n,m,k;cin>>n>>m>>k;
	arr.resize(n+1,0);
	int h= (int)ceil(log2(n));
	int tree_size= (1<<h+1);
	tree.resize(tree_size, 0);
	
	for(int i=1; i<=n ;i++){
		cin>>arr[i];
	}
	

	
	init(1, 1, n);
	
	for(int i=0; i< m+k; i++){
		int cmd ,b,c;cin>>cmd>>b>>c;
		if(cmd==1){
			update(1,1,n,b,c);
		}
		else{
			cout<<query(1, 1,n, b,c) % MOD <<endl;
		}
	}
	
	
	
	return 0;
}
