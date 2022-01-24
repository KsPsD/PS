#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
 
#define MOD 1000000007
#define INF 0x7fffffff
#define MAX_SIZE (int)1e5
 
using namespace std;

int arr[MAX_SIZE];
int n,m;
vll tree;
vll lazy;


void update_lazy(int node,int s,int e){
	if(lazy[node]!=0){
		tree[node] = e -s +1 - tree[node];
		if(s !=e){
			lazy[2*node] = !lazy[node*2];
			lazy[2*node+1] = !lazy[node*2+1];
		}
		lazy[node]=0;
	}
}

ll update(int node, int s,int e,int l,int r){
	update_lazy(node, s,e);
	if(r<s || l>e) return tree[node];
	else if(l<=s && e<=r){
		tree[node]  = e-s+1 -tree[node];
		if(s!=e){
			lazy[2*node] = !lazy[2*node];
			lazy[2*node+1] = !lazy[2*node+1];
		}
		
	
		return tree[node];
	}
	
	int mid =(s+e)/2;
	return tree[node] = update(2*node, s, mid, l,r) + update(2*node+1, mid+1, e, l,r);
}




ll query(int node, int s,int e, int l ,int r){
	update_lazy(node, s,e);
	
	if(r < s || e<l){
		return 0;
	}
	else if(l<=s && e<=r){
		return tree[node];
	}
	
	int mid = (s+e)/2;
	return query(2*node, s,mid , l,r) + query(2*node+1, mid+1, e, l,r);
}


int main(){
	
	
	fastio;
	
	cin>>n>>m;
	int height= (int)ceil(log2(n));
	tree.resize(1<<(height+1));
	lazy.resize(1<<(height+1));
	
	
	
	for(int i=0; i<m; i++){
		int cmd;cin>>cmd;
		if(cmd==0){
			int a,b;
			cin>>a>>b;
			a--;b--;
			update(1, 0, n-1 ,a,b);
		}
		else{
			int a, b;
			cin>>a>>b;
			a--;b--;
			cout<<query(1,0,n-1,a,b)<<endl;
		}
	}
	
	
	
	return 0;
} 
