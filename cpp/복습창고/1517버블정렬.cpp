#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define pii pair<int,int>
#define ll long long

using namespace std;

const int MAX = 500001;
int tree[MAX];
int arr[MAX];
int n;
vector<pii> edge;


void update(int idx, int val){
	while(idx<=n){
		tree[idx] +=val;
		idx+=(idx & -idx);
	}
}


ll query(int idx){
	ll ret = 0;
	while(idx){
		ret+=tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}


int main(){
	
	
	cin>>n;
	
	ll ans=0;
	for(int i=0; i<n; i++){
		int v;cin>>v;
		edge.push_back({v,i+1});
	}
	
	
	sort(edge.begin(), edge.end());
	
	for(int i=edge.size()-1; i>=0; i--){
		ans+=query(edge[i].second);
		update(edge[i].second, 1);
	}
	
	
	cout<<ans<<endl;
	
	
	return 0;
} 
