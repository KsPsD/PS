#include<bits/stdc++.h>


using namespace std;


#define endl "\n"
int n, m;


int ch[9];
vector<int> v;
void dfs(int level){
	
	if(level==m){
		for(int i=0; i<v.size() ;i++){
				cout<<v[i]<<" " ;
		}
		cout<<endl;
		
		return ;
	}
	
	for(int i=1; i<=n ;i++){
		if(ch[i] ==0){
			ch[i]=1;
			v.push_back(i);
			dfs(level+1);
			v.pop_back();
			ch[i] =0;
		}
	}
	
	
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


	cin>>n>>m;
	
	
	dfs(0);
	
	
	
	
	
	
	return 0;
}
