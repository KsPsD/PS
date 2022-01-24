#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define INF INT_MAX
using namespace std;
vector<vector<int> > v(104, vector<int>(104, 100001 ));


int main(){
	
	int n,m;cin>>n>>m;
	
	for(int i=0; i< m; i++){
		int a,b,c;cin>>a>>b>>c;
		v[a][b] = min(v[a][b],c);
	}
	
	for(int i=1 ;i<=n; i++){
		v[i][i] =0;
	}
	
	for(int k =1; k<=n;k++){	
		for(int i=1 ;i<=n ;i++){
			for(int j=1; j<=n ;j++){
				if(v[i][j] > v[i][k]+ v[k][j])  v[i][j] = v[i][k]+ v[k][j];
			}
		}
	}
	
	for(int i=1; i<=n ;i++){
		for(int j=1 ;j<=n; j++){
			if(v[i][j] == 100001) cout<<"0"<<" ";
			else cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
} 
