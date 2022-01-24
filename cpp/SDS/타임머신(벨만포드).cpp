#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define INF INT_MAX
using namespace std;

int n,m;
vector<pair<pair<int,int> ,int>> ed;
ll dis[501];

int main(){
	fastio;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a,b,c;cin>>a>>b>>c;
		ed.push_back(make_pair(make_pair(a,b),c));
		
	}
	
	fill_n(dis, n+1 ,INF);
	
	
	dis[1] =0;
	
	for(int i=1; i<=n-1; i++){
		for(int j=0; j<ed.size(); j++){
			int s= ed[j].first.first;
			int e= ed[j].first.second;
			int c= ed[j].second;
			if (dis[s] == INF) continue;
			if(dis[e] > dis[s] +c) dis[e] = dis[s]+c;
			
		}
	}
	
	
	for (int i = 0; i < ed.size(); i++)
    {
        int s = ed[i].first.first;
        int e = ed[i].first.second;
        int c = ed[i].second;
 
        if (dis[s] == INF) continue;
        if (dis[e] > dis[s] + c)
        {
            cout << -1 << endl;
            return 0;
        }
        
}
for(int i =2; i<=n ;i++){
		if (dis[i] == INF) cout<<-1<<endl;
		else cout<<dis[i]<<endl;
	}
return 0;
} 
