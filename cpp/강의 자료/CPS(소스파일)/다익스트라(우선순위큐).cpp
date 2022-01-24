#include<bits/stdc++.h>

using namespace std;



struct Edge{
	int vex;
	int dis;
	
	Edge(int a, int b){
		vex=a;
		dis=b;
	}
	bool operator < (const Edge &b)const{
		return dis>b.dis; //최소힙으로 
	}
};


int main(){
	
	ios_base::sync_with_stdio(false);
	
	priority_queue <Edge> pq;
	
	 
	int n, m;
	cin>>n>>m;
	vector<pair<int,int> > graph[30];
	vector<int> dis(n+1, numeric_limits<int>::max());
	for(int i=1; i<=m ;i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back(make_pair(b,c));
	}
	
	pq.push(Edge(1,0));
	dis[1] =0;
	
	while(!pq.empty()){
		int now = pq.top().vex;
		int cost = pq.top().dis;
		pq.pop();
		if(cost > dis[now]) continue;
		for(int i=0 ;i<graph[now].size() ;i++){
			int next = graph[now][i].first ;
			int nextcost = cost+ graph[now][i].second;
			if(dis[next] > nextcost){
				dis[next] = nextcost;
				pq.push(Edge(next,nextcost));
			}
		}
	}
	
	for(int i=2; i<=n ;i++){
		if(dis[i] == numeric_limits<int>::max()) cout<<-1<<endl;
		else cout<<dis[i]<<endl;
	}
	
	
	
	
	
	
	
	
	
	return 0;
} 
