#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;


int arr[1025][1025];
int psum[1025][1025] ;

int main(){
	fastio;
	int n,m;cin>>n>>m;
	
	for(int i =1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			psum[i][j] = psum[i-1][j] +psum[i][j-1] - psum[i-1][j-1] +arr[i][j];
	}
	

	for(int i=1; i<=m; i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1] <<endl; 
		
	}
	
	return 0;
	
}
