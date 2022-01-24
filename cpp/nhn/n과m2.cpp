#include<bits/stdc++.h>


using namespace std;


#define endl "\n"

int n,m;
int ch[9];
vector<int> v;

void dfs(int s, int level){
	if(level==m+1){
		for(int i=1; i<=m; i++){
				cout<<ch[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	
	for(int i=s; i<=n; i++){
		ch[level]= i;
		dfs(i+1, level+1);
	}
	
}



int main(){
	
	
	cin>>n>>m;
	
	dfs(1,1);
	
	
	
	
	
	return 0;
}
