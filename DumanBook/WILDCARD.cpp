#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

int cache[101][101];
string W,S;


bool go(int w, int s){
	int &ret = cache[w][s];
	if(ret != -1) return ret;
	if(s<S.size() && w<W.size() && (W[w] == '?' || W[w] == S[s])){
		return ret =go(w+1,s+1);
	}
	
	if(w == W.size()){
		return ret = (s==S.size());
	}
	
	if(W[w] == '*'){
		if(go(w+1,s) || (s<S.size() && go(w,s+1)))
			return ret=1;
		}
		
	return false;
}


int main(){
	
	int c;cin>>c;
	for(int i=0 ;i<c ;i++){
		vector<string> res;
		cin>>W;
		int num;cin>>num;
		for(int j= 0; j< num ;j++){
			
			memset(cache,-1,sizeof(cache));
			cin>>S;
			
			if(go(0,0)==true){
				res.push_back(S);
			}
		
			
		}
		sort(res.begin(), res.end());
		for(auto & e: res){
			cout<<e<<endl;
		}
		
	}
	
	
	
}
