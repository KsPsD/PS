#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;
#define MAX 1001


struct Edge{
	int node;
	int cost;
	Edge(int a,int b){
		node =a;
		cost= b;
	}
	
	bool operator < (const Edge & b) const{
		return cost> b.cost;
	}
};


int n,m,k;
vector<pii> v[MAX];
priority_queue<int> dist[MAX];


int main(){
	fastio;
	cin>>n>>m>>k;
	
	for(int i=0; i< m; i++){
		int a,b,c;cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
	
	priority_queue<Edge> pq;
	pq.push(Edge(1,0));
	dist[1].push(0);	
	while(!pq.empty()){
		int cur = pq.top().node;
		int cost = pq.top().cost;
		pq.pop();
	
		
		for(auto e: v[cur]){
			int next= e.first;
			int nextcost = e.second+cost;
			
			if(dist[next].size() <k){
				dist[next].push(nextcost);
				pq.push(Edge(next, nextcost));
				}
			else if(dist[next].top() > nextcost){
				
				dist[next].pop();
				dist[next].push(nextcost);
				pq.push(Edge(next,nextcost));
				
				}
			
			}
		
		}
	
	
	for(int i=1; i<=n; i++){
		dist[i].size()==k?cout<<dist[i].top()<<endl : cout<<-1<<endl;
	}
	
	
	
	
	
	return 0;
}
