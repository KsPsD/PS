#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;


int main(){
	
	fastio;
	int n,l;cin>>n>>l;
	int a;	
	
	deque<pair<int,int> > dq;
	for(int i=0 ;i<n ;i++){
		while(!dq.empty() && dq.front().first<=i-l)
			dq.pop_front();
		cin>>a;
		while(!dq.empty() && dq.back().second >=a)
			dq.pop_back();
		dq.push_back({i,a});
		cout<<dq.front().second<<" ";
	}
	
	
	return 0;
} 


//우선순위 큐
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int idx, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		return a.val > b.val;
	}
};

int main() {
	fastio;
	int num, len, val;
	cin >> num >> len;
	priority_queue<info,vector<info>,cmp> pq;
	for (int i = 0; i < num; i++) {
		cin >> val;
		pq.push({ i,val });
		if (pq.size() >= len) {
			while (!pq.empty()) {
				if (pq.top().idx + len <= i) pq.pop();
				else break;
			}
		}
		cout << pq.top().val << " ";
	}
	return 0;
} 

