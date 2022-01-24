#include<bits/stdc++.h>

#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

#define MAX 2000
int n,m;
vector<int> v;
int cache[MAX+1][MAX+1];


int palin(int s, int e){
	if(s>=e)
		return 1;
	int &res = cache[s][e];
	
	if(res!=-1)
		return res;
	if(v[s]!=v[e])
		return res=0;
		
	return res= palin(s+1,e-1);
}


int main(){
	fastio;
	cin>>n;
	v.resize(MAX+1,0);
	
	for(int i=1; i<=n; i++){
		cin>>v[i];
		
	}
	 cin>>m;
	 memset(cache ,-1, sizeof(cache));
	 for(int i=0; i<m ;i++){
	 	int s,e;
	 	cin>>s>>e;
	 	cout<<palin(s,e)<<endl;
	 }
	 
	
	
	
	
	return 0;
}
