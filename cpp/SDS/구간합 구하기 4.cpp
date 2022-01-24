#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

int psum[100001];
int arr[100001];
int n,m; 

int main(){
	fastio;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
//	psum[1] = arr[1];
	for(int i=1; i<=n; i++){
		psum[i] = psum[i-1] + arr[i]; 
	}
	
	for(int i=1; i<=m; i++){
		int a,b;
		cin>>a>>b;
		cout<<psum[b] - psum[a-1] <<endl;
	}
		
	
	return 0;
}
