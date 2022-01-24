#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;


pii unf[100001];
int n,m;


int find(int a){
	if(a==unf[a].first) return a;
	int r= find(unf[a].first);
	unf[a].second+=unf[unf[a].first].second;
	return unf[a].first=r;

}


void Union(int a,int b, int val){
	int aRoot= unf[a].first;
	int bRoot = unf[b].first;
	if(aRoot==bRoot) return;
	
	int newD= unf[a].second+val;
	int originD = unf[b].second;
	unf[bRoot].first=aRoot;
	unf[bRoot].second =newD-originD;
}



int main(){
	
	fastio;
	while(1){
		cin>>n>>m;
		if(n==0 && m==0) break;
		for(int i=1; i<=n; i++){
			unf[i].first =i;
			unf[i].second=0;
		}
		
		for(int i=0 ;i<m; i++){
			char cmd;cin>>cmd;
			int a,b ;cin>>a>>b;
			find(a);
			find(b);
			if(cmd=='!'){
				int val;
				cin>>val;
				Union(a,b,val);
			}
			else {
				if(unf[a].first == unf[b].first) cout<<unf[b].second -unf[a].second<<endl;
				else cout<<"UNKNOWN"<<endl;
				}
			}
		}
		
	
	
	return 0;
}
