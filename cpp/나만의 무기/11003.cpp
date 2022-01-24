#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;

struct info{
	int idx, val;
};

struct cmp{
	bool operator()(info &a, info &b){
		return a.val > b.val;
	}
};

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);	

	int n,l;
	cin>>n>>l;
		int a;
	deque<pair<int,int>>dq;
	for(int i=0; i<n; i++){
		while(!dq.empty() && dq.front().first + l <= i){
			dq.pop_front();
		}
		cin>>a;
		while(!dq.empty() &&dq.back().second  >=a){
			dq.pop_back();
		}
		dq.push_back({i,a});
		cout<<dq.front().second<<endl;
	}

	
}
