#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>

using namespace std;


vector<int> v;
int dp[5][5][100000];

int move(int from, int to){
	if(from ==to )return 1;
	switch(from){
		case 0: return 2;
		case 1: return to == 3 ? 4 : 3;
		case 2: return to==4 ? 4:3;
		case 3 : return to==1 ? 4:3;
		case 4 : return to==2 ? 4:3;
	}
}


int go(int l,int r,int n){
	if(n==v.size() ) return 0;
	int &ret =dp[l][r][n];
	
	if(ret != 0 ) return ret;
	return ret = min(move(l,v[n])+ go(v[n], r,n+1) ,move(r,v[n]) + go(l, v[n], n+1));
}


int main(){
	
	
	while(1){
		int num;cin>>num;
		if(num==0) break;
		v.push_back(num);
	}
	
	
	cout<<go(0,0,0);
	
	
	
	
	return 0;
}
