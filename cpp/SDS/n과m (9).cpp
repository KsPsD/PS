#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;
int ans[10];
int ch[10];
int tmp[10] ;

void go(int idx, int n ,int m){
	
	if(idx==m){		
	
		for(int i=0; i<m; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		return;
	}
	int prev = 0;
	for(int i=0; i<n ;i++){
		if(ch[i]) continue;
//		if(idx>0 && ans[idx-1] > tmp[i] ) continue; //이런식으로 해도 되고. 
		
		if(prev !=tmp[i]){
			ch[i]=1;
			ans[idx] = tmp[i];
			prev=tmp[i];
			go(idx+1, n, m);
			ch[i] =0;
		}
		
	}
}


int main(){
	
	fastio;
	int n,m;cin>>n>>m;
	

	for(int i=0; i< n; i++){
		cin>>tmp[i];
	}
	sort(tmp,tmp+n);
	
	go(0, n,m);
	
	
	return 0;
}
