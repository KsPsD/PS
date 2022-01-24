#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;
typedef pair<int, int> pii;

const int TMAX = 100000;
// dist max ; 10^5 < 2^17
const int DMAX = 18;

int N, K, depth[TMAX+1];
// parent[i][k] : i의  2^k 번째 조상번호
int parent[TMAX+1][DMAX+1];
// Value[i][k] : i의 2^k번째 조상까지의 pair< 작은길이, 큰길이 >
pii value[TMAX+1][DMAX+1];
// < 연결된 도시 , 연결길이 > 
vector<pii> arr[TMAX+1];

void dfs(int curr){
    for(pii next: arr[curr]){
    	int town = next.first;		
		int val = next.second;
        if(depth[town] == -1){
         parent[town][0] = curr;
         depth[town] = depth[curr]+1;
		// 바로 부모까지 작은길이 = 큰길이 
			value[town][0] = pii(val,val);
		dfs(town); 
        }
    }
}


int main(){
	fastio;
	cin>>N;
	
	for(int i=0; i<N-1; ++i){
	int a, b, w;

	cin >> a >> b >> w;
	a--;b--;
	arr[a].push_back(pii(b,w));
	arr[b].push_back(pii(a,w));
}
	
	memset(parent, -1, sizeof(parent));
    fill(depth, depth+N, -1);
    depth[0] = 0;
    
    dfs(0);
    
    
   
    
    for(int k=0; k<=DMAX; ++k){
	for(int i=1; i<N; ++i){
		int Father = parent[i][k];
		if(Father != -1){
			parent[i][k+1] = parent[Father][k];
			// 작은길이 업데이트
			value[i][k+1].first = min(value[i][k].first, value[Father][k].first);
			// 큰길이 업데이트
			value[i][k+1].second = max(value[i][k].second, value[Father][k].second);
		} 			
	}
}


cin>>K;
for(int i=0; i<K ;i++){
	int u,v; cin>>u>>v;
	u--;v--;
	int mini = 1000000;
	int maxi = -1;
	if(depth[u] <depth[v]) swap(u,v);
	int diff=depth[u] - depth[v];
	
	for(int j=0; diff; j++){
		if(diff %2) {
			mini = min(mini, value[u][j].first);
			maxi = max(maxi, value[u][j].second);
			u = parent[u][j];	
		}
		diff/=2;
		
	}
	
	
	if(u!=v){
		 for(int j=DMAX-1; j>=0; j--){
		 	 if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
		 	 		mini = min(mini, value[u][j].first);
					maxi = max(maxi, value[u][j].second);
                    u = parent[u][j];
                    
                    mini = min(mini, value[v][j].first);
					maxi = max(maxi, value[v][j].second);
					v = parent[v][j];
                }
		 	
		 	
		 	
		 }
		mini = min(mini, value[u][0].first);
		maxi = max(maxi, value[u][0].second);
		mini = min(mini, value[v][0].first);
		maxi = max(maxi, value[v][0].second);
		u=parent[u][0];
		 
	}
	
	cout<<mini << " "<<maxi<<endl;
	
}

}
