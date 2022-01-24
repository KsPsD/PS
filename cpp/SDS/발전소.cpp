#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>

using namespace std;

#define MAX 16
#define INF 987654321


int n,p ,ans=INF;
int arr[MAX][MAX];
int cost[1<<MAX];
string s;


int count(int state){
	int cnt= 0;
	while(state!=0){
		cnt = cnt + (state &1);
		state = state>>1;
	}
	return cnt;
}

int dfs(int state){
	if(count(state) >= p ) return 0;
	if(cost[state] != -1) return cost[state];
	
	cost[state] =INF;
	for(int i=0; i<n; i++){
		
		if((state & (1<<i)) ==0) continue;
		
		for(int j=0; j<n; j++){
			if((state & (1<<j)) ==0 ){
				int next = state | (1<<j);
				cost[state] = min(cost[state], arr[i][j] + dfs(next));
				
			}
		}
		
	}
	
	return cost[state];
}



int main(){
	
	cin>>n;
	for(int i=0; i<n ; i++){
		for(int j=0; j<n ;j++){
			cin>>arr[i][j];
		}
	}
	
	cin>>s;
	cin>>p;
	
	int State= 0;
	for(int i=0; i<s.length() ;i++){
		if(s[i] =='Y' ) State = State | (1<<i);
		
	}
	memset(cost, -1,sizeof(cost));
	ans = dfs(State);
	
	
	if(ans==INF) cout<<-1<<endl;
	else cout<< ans<<endl;
	
	
	
	
	
	return 0;
} 
