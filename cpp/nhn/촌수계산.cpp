#include<bits/stdc++.h>

using namespace std;




vector<int> v[101]; 
int n, a,b,m;
bool flag =false;
int ch[101];

bool dfs(int cur,int cnt){
	if(cur==b){
		cout<<cnt<<endl;
		return flag=true;
	}
	
	for(int i=0; i<v[cur].size(); i++){
		if(ch[v[cur][i]] ==0){
			ch[v[cur][i]] =1;
			if(dfs(v[cur][i] , cnt+1))
				return flag;
			ch[v[cur][i]]=0;
		}
	}
	
	return flag;
}


int main(){
	cin>>n>>a>>b>>m;
	
	
	for(int i=0; i<m; i++){
		int p, c;
		cin>>p>>c;
		v[p].push_back(c);
		v[c].push_back(p);
	}
	
	ch[a]=1;
	if(dfs(a, 0))
		return 0;
	else
		cout<<-1<<endl;
	
	
	
	
	return 0;
}
