#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;


int n,m;
vector<int> v;
ll ans=0;
bool ch(ll val){
	ll sum=0;
	for(int i=0 ;i<v.size(); i++){
		if(val>=v[i]) continue;
		else sum+= (v[i] -val); 
	}	
	if(sum >= m) return true;
	else return false;
	
}

int main(){
	fastio;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int a;cin>>a;
		v.push_back(a);
	}
	
	sort(v.begin() ,v.end());
	int s=0;
	int e= v[v.size()-1];
	ll mid =0;
	
	while(s<=e){
		mid = (s+e)/2;
		if(ch(mid)){
			ans = max(ans,mid);
			s=mid+1;
		}
		
		else e=mid-1;
	}
	
	cout<<ans<<endl;
	
	return 0;
} 
