#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"
#define pii pair<int,int>

using namespace std;

int n,k;

priority_queue<int> pq;
vector<int> bag;
pii jewel[300000];


int main(){
fastio;
	cin>>n>>k;
		
	
	for(int i=0; i<n; i++){
		int m,v;
		cin>>m>>v;
		jewel[i]={m,v};
	}
	
		
	for(int i=0 ;i<k; i++){
		int c;cin>>c;
		bag.push_back(c);
	}
	sort(bag.begin(), bag.end());
	sort(jewel, jewel+n);
	
	int idx= 0;
	ll res=0;
	for(int i=0;i<k; i++){
		while(idx<n && jewel[idx].first<=bag[i])
			pq.push(jewel[idx++].second);
		if(!pq.empty()){
			res +=pq.top();
			pq.pop();
		}
	}
	
	
	cout<<res<<endl; 
	
	
	
	
	
	return 0;
} 
