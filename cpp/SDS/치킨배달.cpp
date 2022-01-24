#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define INF 1000000009
using namespace std;

int n,m;
int arr[51][51];
vector<pair<int ,int>> chi ;
vector<pair<int, int> > home;
int ans=0;
int ch[14];
void go(int idx, int cnt){
	if(cnt==m){
		int sum=0;
		for(int i=0; i<home.size(); i++){
			int dis = INF;
			for(int j=0; j<chi.size(); j++){
				if(ch[j]==1){
				dis = min(dis, abs(home[i].first - chi[j].first ) + abs(home[i].second- chi[j].second));
				}
				
			}
			sum+=dis;
		}
		ans=min(sum,ans);
	
		return;	
	}
	
	if(idx ==chi.size()) return;
	
	
	
		ch[idx] =1;
		go(idx+1, cnt+1);
		ch[idx] =0;
		go(idx+1, cnt);
}



int main(){
	
cin>>n>>m;

for(int i=0; i<n; i++){
	for(int j=0 ;j<n; j++){
		cin>>arr[i][j];
		if(arr[i][j]==2) {
			chi.push_back({i,j});
		}
		else if(arr[i][j]==1){
			home.push_back({i,j});
		}
	}
}	
	go(0,0);
	
	
	return 0;
} 
