#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;


struct Edge{
	int e;
	int val;
	Edge(int a, int b){
		e=a;
		val=b;
	}
	bool operator<(const Edge &b)const{
		return val>b.val;
	}
};
int ch[1001];

int main(){
	fastio;
	
	int n, m;
	cin>>n>>m;	
	
	priority_queue<Edge> pq;
	vector<pair<int, int>> v[1001];
	
	
	for(int i=1; i<=m; i++){
		int a,b,c;cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));

	}
	int res=0;
	
	
	pq.push(Edge(1,0));
	while(!pq.empty()){
		Edge tmp = pq.top();
		pq.pop();
		int node =tmp.e;
		int val = tmp.val;
		if(ch[node] ==1) continue;
		res+=val;
		ch[node]=1;
		for(int i=0; i<v[node].size(); i++){
			if(ch[v[node][i].first] ==1) continue;
			pq.push(Edge(v[node][i].first,v[node][i].second));
		}
		
		
	}
	
	cout<<res<<endl;
	
	return 0;
}
