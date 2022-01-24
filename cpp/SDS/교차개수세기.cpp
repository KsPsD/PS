#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<int ,int> 
using namespace std;

#define INF 100000009

const int MAX = 2001;


ll ans;
int tree[2001];
vector<pii> edge;
int n,m,a,b;

void update(int idx,int val){
	while(idx<=n){
		tree[idx] +=val;
		idx+=(idx & -idx);
	}
}

int query(int idx){
	int ret = 0;
	while(idx){
		ret+=tree[idx];
		idx-= (idx & -idx);
		
	}
	return ret;
}
 


int main(){
	
	fastio;
	cin>>n>>m;
		
	
	for(int i=0; i<m; i++){
		cin>>a>>b;
		edge.push_back({a,b});
		
	}
	sort(edge.begin(), edge.end());
	
	for(int i= m-1; i>=0; i--){
		ans+=query(edge[i].second);
		cout<<"i: " <<i <<"ans: " <<ans<<endl;
		update(edge[i].second+1,1);
	}
	
	cout<<ans<<endl;
	return 0;
} 
