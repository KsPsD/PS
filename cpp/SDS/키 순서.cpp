#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;



int  n,m;
int arr[501][501];

int main(){
	fastio;
	
	cin>>n>>m;
	for(int i=0; i< m;i ++){
		int a,b;cin>>a>>b;
		arr[a][b]=1;
	}
	
	for(int k =1; k<=n; k++)
		for(int i =1; i<=n; i++)
			for(int j=1; j<=n;j++){
				if(arr[i][k] &&arr[k][j])
					arr[i][j] =1;
			}
			
			
	int ans=0;
	
	for(int i=1;i<=n; i++){
		int cnt=0;
		for(int j=1; j<=n; j++){
			if(i==j) continue;
			if(arr[i][j] ==0 && arr[j][i]==0 )cnt++;
			
 		}
 		if(cnt==0) ans++;
 		
	}
	cout<<ans<<endl;
	
	return 0;
} 

