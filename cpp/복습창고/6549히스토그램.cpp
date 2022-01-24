#include<bits/stdc++.h>

#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int INF = 1000000001;
const int MAX =100001;
int tree[4*MAX];
int arr[MAX];
ll ans =0;
int n;


int init(int node, int s,int e){
	if(s==e) return tree[node] =s;
	int mid =(s+e)/2;
	int lt = init(2*node, s, mid);
	int rt = init(2*node+1, mid+1, e);

	return tree[node]  = arr[lt] < arr[rt] ? lt : rt;	
}

int query(int node, int s, int e, int l, int r){
	if(r<s || l>e) return INF;
	if(l<=s && e<=r ) return tree[node];
	int mid = (s+e)/2;
	int lt = query(node *2 ,s,mid, l,r);
	int rt =  query(node*2+1, mid+1, e ,l,r);

	if(lt == INF) return rt;
	else if(rt == INF) return lt;
	else return arr[lt] < arr[rt] ? lt :rt;
	
}

void solve(ll l, ll r){
	if(l>r) return;
	int idx= query(1,0,n-1,l ,r);
	ans = max(ans, (ll)arr[idx] *(r-l+1));
	
	solve(l,idx-1);
	solve(idx+1,r);
}




int main(){
	fastio;
	while(1){
		ans =0;
		cin>>n;
		if(n==0) break;
		memset(arr,0 ,sizeof(arr));
		memset(tree,0,sizeof(tree));
		for(int i=0; i<n ;i++){
			cin>>arr[i];
		}
		
		
		
		init(1, 0,n-1);
		
		solve(0,n-1);
		
		
		
		cout<<ans<<endl;
		
	}
	
	
	
	
	
	
	
	
	return 0;
}
