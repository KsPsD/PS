#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

int n,m;

vector<int> v[32001];
int indegree[32001];



int main(){
	
	fastio;
	
	cin>>n>>m;
	for(int i=0 ;i<m; i++){
		int a,b;cin>>a>>b;
		
		v[a].push_back(b);
		indegree[b]++;
	}
	
	
	int res[32001];
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	
	for(int i=1; i<=n; i++){
		if(q.empty()){
			return 0 ;
		}
		
		int tmp = q.front();
		q.pop();
		res[i] = tmp;
		for(int i=0; i<v[tmp].size(); i++){
			int y= v[tmp][i] ;
			if(--indegree[y]==0){
				q.push(y);
			}
		}
	}
	
	for(int i=1;i<=n; i++){
		cout<<res[i]<< " ";
	}
	cout<<endl;
	
	
	
	return 0;
} 
