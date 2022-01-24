#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)


int main(){
	fastio;
	
	int n,k;cin>>n>>k;
	
	
	if(k==0){
		cout<<1;
		return 0;
	}
	
	int p=1,q=1;
	int ans =1;
	for(int i=1,j=n;i<=k; i++ ,j--){
		ans*=j;
		ans/=i;
	}
	
	cout<<ans<<endl;
} 
