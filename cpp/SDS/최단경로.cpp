#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define INF INT_MAX
using namespace std;

struct Edge{
	int vex;
	int dis;
	Edge(int a,int b){
		vex=a;
		dis=b;
	}
	
	bool operator < (const  Edge &b) const {
		return dis> b.dis;
	}
	
};


int main(){
	
	int v,e;
	
	cin>>v>>e;
	int k;cin>>k;
	priority_queue<Edge> q;
	vector<pair<int,int>> arr[20001];
	vector<int> dis(v+1, INF);
	
	for(int i=1; i<=e; i++){
		int a, b,c;cin>>a>>b>>c;
		arr[a].push_back({b,c});
	}
	
	q.push(Edge(k,0));
	dis[k]=0;
	
	while(!q.empty()){
		int now =q.top().vex;
		int val = q.top().dis;
		q.pop();
		if(val> dis[now] ) continue;
		for(int i=0; i<arr[now].size(); i++){
			int next = arr[now][i].first;
			int nextcost = arr[now][i].second;
			if(dis[next]>nextcost){
				dis[next] =nextcost;
				q.push(Edge(next,nextcost));
			}
		}
	}
	
	for(int i=1 ;i<=v ;i++){
		if(dis[i] ==INF) cout<<"INF"<<endl;
		else cout<<dis[i]<<endl;
	}
	
	return 0;
} 
