#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

const int SWITCH  =10, CLOCK=16;

int linked[SWITCH][CLOCK] = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

void push(vector<int> & clocks, int swt){
	for(int i = 0 ;i<CLOCK; i++){
		if(linked[swt][i] == 1){
			clocks[i]+=3;
		}
		
		if(clocks[i]==15) clocks[i]=3;
	}
}

bool check(vector<int> & clocks){
	for(int i=0 ;i<CLOCK; i++){
		if(clocks[i] !=12) return false;
	}
	return true;
}


int solve(vector<int> & clocks, int swt){
	if(swt == SWITCH) return check(clocks) ? 0 :INF;
	
	int ret =INF;
	for(int cnt=0 ; cnt<4 ; cnt++){
		ret =  min(ret, cnt+solve(clocks, swt+1));
		push(clocks ,swt);
	}
	
	return ret;
	
}




int main(){

	
	
	int t;cin>>t;
	while(t--){
		vector<int> clock(CLOCK,0);
		for(int i=0 ;i<CLOCK; i++){
			cin>>clock[i];
		}
		int ans =solve(clock,0);
		
		if(ans == INF) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	
	
	
	
	return 0;
}
