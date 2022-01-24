#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;
const int MAX = 18; // roundup log(2, 100000)
 
int N, M;
int parent[100000][MAX]; // parent[i][k]: i의 2^k번째 부모
int depth[100000]; // 정점의 깊이 (루트의 깊이: 0)
vector<int> arr[100000]; // 인접 리스트

void dfs(int cur){
	for(auto e: arr[cur]){
		if(depth[e] == -1){
			parent[e][0] = cur;
			depth[e] =depth[cur]+1;
			dfs(e);
		}
	}
}

int main(){
	
	cin>>N;
	for(int i=0; i<N-1; i++){
		int a,b;cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);	
	}
	
	memset(depth, -1,sizeof(depth));
	memset(parent ,-1, sizeof(parent));
	
	depth[0] =0;
	dfs(0);
	
	for(int i=0; i<MAX-1; i++){
		for(int j=1; j<N; j++){
			if(parent[j][i] !=-1){
				parent[j][i+1] =  parent[parent[j][i]][i];
			}
		}
	}
	
	cin>>M;
	
	for(int i=0; i<M; i++){
		int  u,v;cin>>u>>v;
		u--;v--;
		if(depth[u]<depth[v]) swap(u,v);
		int diff= depth[u] -depth[v];
		
		for(int j=0; diff;j++){
			if(diff%2) u=parent[u][j];
			diff/=2;	
		}
		if(u != v){
		for(int j= MAX-1; j>=0; j--){
			if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
				u=parent[u][j];
				v=parent[v][j];
			} 	
		}
		u=parent[u][0];
		
		
	}
	cout<<u+1<<endl;
		
	}
	
	return 0;
}
