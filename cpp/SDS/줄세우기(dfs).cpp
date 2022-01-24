#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

vector<int> v[32001];
int n,m;
int ch[32001];
vector<int> order;
void dfs(int cur){
	ch[cur] =1;
	for(int i=0 ;i<v[cur].size(); i++){
		if(ch[v[cur][i]])continue;
		dfs(v[cur][i]);
	}
	order.push_back(cur);
}


int main(){
	
	cin>>n>>m;
	
	
	for(int i =1; i<=m ;i++){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
	}
	
	for(int i=1;i<=n; i++){
		if(ch[i]==1)continue;
		dfs(i);
	}
	
	
	reverse(order.begin(),order.end());
	
	for(auto e:order){
		cout<<e<<" ";
	}
	cout<<endl;
	
	return 0;
}
