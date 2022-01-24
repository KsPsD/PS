#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define INF 1000001

using namespace std;

vector<int> v;
vector<pii> tracking;
int arr[INF];

int main(){
	fastio;
	int n, data;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	v.push_back(arr[0]);
	tracking.resize(n,{0,0});
	tracking[0] = {0,arr[0]};
	for(int i=1; i<n; i++){
		if(v.back() < arr[i]) {
			v.push_back(arr[i]);
			tracking[i] = pii(v.size()-1,arr[i]);
		}
		else{
			auto it = lower_bound(v.begin(),v.end() , arr[i]);
			*it = arr[i];
			int idx= it-v.begin();
			tracking[i] = pii(idx, arr[i]);
		}
	}
	cout<<v.size()<<endl;
//	
//	stack<int>  st;
//	int tmp = v.size()-1;
//	for(int i=n-1;i>=0; i--){
//		if(tmp == tracking[i].first){
//			st.push(tracking[i].second);
//			tmp--;
//		}
//	}
//	
//	cout<<st.size()<<endl;
//	while(!st.empty()){
//		cout<<st.top()<<" ";
//		st.pop();
//	}
//	
//	
//	
//	
	return 0;
} 
