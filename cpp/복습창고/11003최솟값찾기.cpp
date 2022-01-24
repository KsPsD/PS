#include<bits/stdc++.h>

 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;


int n,l;

int arr[5000001];

int main(){
	
	cin>>n>>l;
	
	deque<pii> dq;
	
	
	
	int a=0;
	for(int i=0; i<n; i++){
		while(!dq.empty() && dq.front().first <= i-l) dq.pop_front();
		cin>>a;
		while(!dq.empty() && dq.front().second >= a) dq.pop_back();
		dq.push_back({i,a});
		cout<<dq.front().second<<" ";
	}
	 
	
	
	
	
	
	
	return 0;
}
