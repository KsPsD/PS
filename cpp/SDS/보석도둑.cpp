#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;
priority_queue<pair<int ,int> > pq;
multiset<int> bag;
int ch[300001];
ll val=0;


int main(){
	fastio;
	
	

	
	int n,k;cin>>n>>k;
	
	for(int i=0; i<n; i++){
		int m,v;cin>>m>>v;
		pq.push({v,m});
		
	}
	
	
	
	for(int i=0; i<k ;i++){
		int c;cin>>c;
		bag.insert(c);
	}
	
	while(!pq.empty()){
		
		pair<int,int> cur = pq.top();
		pq.pop();
		
		auto it = bag.lower_bound(cur.second);
		
		if(it != bag.end()){
			bag.erase(it);
			val+=cur.first;
		}
		if(bag.empty()) break;
		
	}
	
	
	
	
	cout<<val<<endl;
	
	
	
	
	return 0;
} 
