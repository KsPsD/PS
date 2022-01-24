#include<bits/stdc++.h>
#define ll long long
using namespace std;


int n;
vector<int> v[200001];
int m;
int timer[200001];
int t=0;
queue<int> q;
int main(){
	
	cin>>n;
	
	for(int i=1; i<= n; i++){
		while(1){
		int a;
		cin>>a;
		if (a ==0) break;
			v[i].push_back(a);
		}
		
	}	
	memset(timer,-1,sizeof(timer));
	cin>>m;

	for(int i=1; i<=m ;i++){
		int k;
		cin>>k;
	
		q.push(k);
		timer[k] =t;
	}
	 

	while(!q.empty()){
		int person= q.front();
		q.pop();
		
		for(ll i=0; i<v[person].size(); i++){
			if(timer[v[person][i]]> -1) continue;
			
			int cnt=0;
			int cur_p =v[person][i];
			for(ll j=0; j<v[cur_p].size(); j++){
				if(-1<timer[v[cur_p][j]] && timer[v[cur_p][j]] <=timer[person]){
					cnt++;
				}
				
			}
			
			if(cnt>=(double)v[cur_p].size() /2){
				timer[cur_p]  = timer[person] +1;
				q.push(cur_p);
			}
			
			
		}
	
	}
	
for(int i=1; i<=n; i++){
	cout<<timer[i]<<" ";
}
	
	
	
	
	
	
	return 0;
}
