#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

int t,n,m;

int a[1001];
int b[1001]; 


int main(){
	
	cin>>t;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>b[i];
	}
	vector<ll> va;
	vector<ll> vb;
	
	for(int i=0 ;i<n; i++){
		ll sum=a[i];
		va.push_back(sum);
		for(int j=i+1; j<n; j++){
			sum+=a[j];
			va.push_back(sum);
		}
	}
	for(int i=0 ;i<m; i++){
		ll sum=b[i];
		vb.push_back(sum);
		for(int j=i+1; j<m; j++){
			sum+=b[j];
			vb.push_back(sum);
		}
	}
	
	
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());
	
	ll ans =0;
	for(int i=0; i<va.size(); i++){
		int low = lower_bound(vb.begin() ,vb.end(), t-va[i]) - vb.begin();
		int high = upper_bound(vb.begin(), vb.end(), t-va[i]) -vb.begin();
		
		ans += high-low;
	}
	
	
	cout<<ans<<endl;
	
	
	return 0;
}
