#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>

using namespace std;
#define MAXV 100010


int V, E, counter=0, discovered[MAXV]; bool isCutVertex[MAXV]; vector<pair<int, int> > edge;


int dfs(int node, int parent){
	discovered[node] = ++counter;
	int ret = discovered[node];
	
	for(int i=0; i<graph[node].size(); i++){
		int next= graph[node][i];
		if(next ==parent) continue;
		
		if(!discovered[next]){
			int low =dfs(next,node);
			if(low> discovered[node]){
				edge.push_back({min(node,next), max(node,next) });
				
				
			}
			ret= min(ret,low);
		}
		else{
			ret=min(ret,discovered[next]);
		}
	}
	return ret;
}



int main(){
	fastio;
	cin>>V>>E;
	
	for(int i=1; i<=E; i++){
		int a,b;cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		
	}
	
	dfs(1,0);
	
	sort(edge.begin(), edge.end());
	cout<<edge.size()<<endl;
	
	for(int i=0 ; i<edge.size(); i++){
		cout<<edge[i].first<<" " <<edge[i].second<<endl;
	}
	
	return 0;
} 

