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


int main(){
	
	fastio;
	int n, l, num; cin >> n >> l;
    priority_queue<pair<int, int> > pq; //value, idx
    for(int i = 0; i < n; ++i) {
        cin >> num;
        pq.push({-num, i});
        if(i >= l){
            while(pq.top().second < i-l+1)
                pq.pop();
        }
        cout << -pq.top().first << " ";
    }
    
    return 0;
} 
