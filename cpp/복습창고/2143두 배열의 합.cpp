#include<bits/stdc++.h>

 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"

using namespace std;


int t;
int n;
int m;
int a[1001];
int b[1001];


int main(){
	
	
	cin>>t;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1; i<=m; i++){
		cin>>b[i];
	}
	
	vector<ll> va;
	vector<ll> vb;
	
	
	
	for(int i=1; i<=n; i++){
		ll psum=a[i];
		va.push_back(psum);
		for(int j=i+1; j<=n; j++){
			psum+= a[j];
			va.push_back(psum);
		}
		
	}
	
	for(int i=1; i<=m; i++){
		ll psum=b[i];
		vb.push_back(psum);
		for(int j=i+1; j<=m; j++){
			psum+= b[j];
			vb.push_back(psum);
		}
		
	}	
	sort(va.begin(),va.end());
	sort(vb.begin(), vb.end());
	
	ll ans= 0;
	for(int i=0; i<va.size(); i++){
		int low = lower_bound(vb.begin() ,vb.end() , t-va[i]) - vb.begin();
		int high = upper_bound(vb.begin(), vb.end(), t-va[i]) - vb.begin();
		ans+= high- low;
	}
	
	
	cout<<ans<<endl;
	
	
	
	
	
	
	
	
	return 0;
}
