#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>

using namespace std;

const int MAX = 100000001;

int arr[100001];



int main(){
	
	
	
	int n,s;cin>>n>>s;
	
	int ans=MAX;
	
	for(int i=0;i<n; i++){
		cin>>arr[i];
	}
	
	int l=0;int r=0;
	int sum=0;
	
	while(l<= n){
		if(sum>=s){
			
			ans = min(ans,r-l);
			
			sum-=arr[l++];
			
		}
		else if(r>=n)break;
		else{
			sum+=arr[r++];
		}
	}
	
	if(ans!=MAX)cout<<ans<<endl;
	else cout<<0<<endl;
	
	
}
