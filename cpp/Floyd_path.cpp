#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define INF 987654321

int n,m;
vector<vector<int> > v(104, vector<int>(104,INF));
vector<vector<int> > nxt(104, vector<int>(104,INF));

int main(){
ios::sync_with_stdio(0);
  cin.tie(0);
	cin>>n>>m;
	
	
	for(int i= 0;i<m ;i++){
		int a,b,c;cin>>a>>b>>c;
		v[a][b] = min(v[a][b], c);
        nxt[a][b] = b;
	}
    
	for(int i=1 ;i<=n; i++){
		v[i][i] =0;
	}
	for(int k =1; k<=n;k++){
		for(int i=1 ;i<=n ;i++){
			for(int j=1; j<=n ;j++){
				if(v[i][j] > v[i][k]+ v[k][j]) {
					v[i][j] = v[i][k]+ v[k][j];	
					nxt[i][j] = nxt[i][k];
					
				}
			}
		}
	}

	for(int i=1; i<=n ;i++){
		for(int j=1 ;j<=n; j++){
			if(v[i][j] == INF) cout<<"0"<<" ";
			else cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(v[i][j] == 0 || v[i][j] == INF){
        cout << "0"<<endl;;
        continue;
      }
    vector<int> path;
    
      int st = i;
      while(st != j){
        path.push_back(st);
        st = nxt[st][j];
      }
      path.push_back(j);
      cout << path.size() << ' ';
      for(auto x : path) cout << x << ' ';
      cout << endl;
    }
  }
	
	

	return 0;
	
}



