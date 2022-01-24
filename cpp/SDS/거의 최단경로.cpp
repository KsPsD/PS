#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;
const int MAX =INT_MAX;

struct Edge{
	int vex;
	int dis;
	Edge(int a,int b){
		vex=a;
		dis=b;
	}
	
	bool operator < (const Edge &b) const{
		return dis > b.dis;
	}
};

vector<pair<int,int> > arr[501];
int len[501];
vector<int> parent[501];
int ch[505];


void dijkstra(int s) {
	
	len[s]= 0;
	priority_queue<Edge> pq;
	pq.push(Edge(s,0));
		
		while(!pq.empty()){
			int cur = pq.top().vex;
			int cost = pq.top().dis;
			pq.pop();
			if(cost> len[cur]) continue;
			for(int i=0 ;i<arr[cur].size(); i++){
				if (arr[cur][i].second == -1)continue;// µÎ ¹ø
				int next= arr[cur][i].first;
				int nextcost = arr[cur][i].second+cost;
				if(nextcost< len[next]) {
					
					len[next] =nextcost;
					parent[next].clear();
					pq.push(Edge(next,nextcost));
					
					parent[next].push_back(cur);
					
				}
				else if(nextcost==len[next]){
						parent[next].push_back(cur);
				}
				else continue;
			}
		}
		
		
	
}

void init() {
    memset(arr, 0, sizeof(arr));
    memset(parent, 0, sizeof(parent));
        memset(len, MAX, sizeof(len));

    memset(ch, false, sizeof(ch));
}

int main(){
	
	fastio;
	while(1){
		int n,m;
		init();
			cin>>n>>m;
				if(n==0 && m==0) break;
		int s,d;cin>>s>>d;
		for(int i=0; i<m; i++){
			int a,b,c;cin>>a>>b>>c;
			arr[a].push_back({b,c});
			
		}
		fill_n(len, n, MAX);
		
		dijkstra(s);
		
		queue<int>q;
		q.push(d);
		while(!q.empty()){
			int tmp = q.front();
			q.pop();
			if(ch[tmp] == 1) continue;
			ch[tmp]=1;
			for(int i=0; i<parent[tmp].size();i++){
				int prev= parent[tmp][i];
			
				for(int j=0; j<arr[prev].size(); j++){
					if(arr[prev][j].first==tmp) arr[prev][j].second = -1;
				}
				q.push(prev);
			}
		}
	
		fill_n(len, n, MAX);
		
		dijkstra(s);
		
		
		
//		for(auto e:len) cout<<e<<endl;
		if(len[d] == MAX) cout<<-1<<endl;
		else cout<<len[d]<<endl;
//		
	}
	
	return 0;

}

