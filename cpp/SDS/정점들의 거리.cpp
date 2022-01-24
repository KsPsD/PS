#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;
typedef pair<int, int> pii;

int N, K;
const int TMAX = 100000;
// dist max ; 10^5 < 2^17
const int DMAX = 18;

int depth[TMAX];
int parent[TMAX][DMAX];

vector<pii> arr[TMAX];

int value[TMAX][DMAX];

void dfs(int cur){
	for(auto next: arr[cur]){
		int town= next.first;
		int val = next.second;
		if(depth[town] ==-1){
			parent[town][0] = cur;
			depth[town] = depth[cur]+1;
			value[town][0] = val;
			dfs(town);
		}
	} 
}




int main(){	
	cin>>N;	
	fastio;
	for(int i=0; i<N-1; i++){
		int s,e,val;
		cin>>s>>e>>val;
		s--;e--;
		arr[s].push_back({e,val});
		arr[e].push_back({s,val});
	}
	
	memset(parent, -1, sizeof(parent));
	fill(depth, depth+N, -1);
	depth[0]=0;
	
	dfs(0);
	
	
	
	for(int i=0; i<DMAX-1; i++){
		for(int j=1; j<N; j++){
			int ances = parent[j][i];
			if(ances !=-1){
				parent[j][i+1] = parent[ances][i];
				value[j][i+1] = value[ances][i]+value[j][i];
			}
		}
	}
	
	cin>>K;
	for(int i=0 ;i<K; i++){
		int u,v;cin>>u>>v;
		u--;v--;
		if(depth[u]<depth[v]) swap(u,v);
		int diff=depth[u] - depth[v] ;
		int sum=0;
		for(int j=0; diff; j++){
			if(diff%2){
				sum+=value[u][j];
				u =parent[u][j];
			}
			diff/=2;
		}
		
		
		if(u!=v){
			for(int j=DMAX-1; j>=0; j--){
				if(parent[u][j] != -1 && parent[u][j] !=parent[v][j]){
					sum+=(value[u][j] +value[v][j]);
					u=parent[u][j];
					v=parent[v][j];
				}
			
			
			
			}
			
			sum+=(value[u][0]+ value[v][0]);
			u=parent[u][0];
			
		}
		
		
		
		cout<<sum<<endl;
	}
	
	
	
	
}
