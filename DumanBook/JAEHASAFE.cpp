#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;

#define vi vector<int>
#define vipii vector<pair<int,int> >
#define pii  pair<int,int>
#define vvi vector<vi >
#define MOD 1000000007


vector<int> getPartialMatch(const string&N){
	int m= N.size();
	vector<int> pi(m,0);
	int begin=1, matched=0;
	while(begin+matched<m){
		if(N[begin+matched] == N[matched]){
			++matched;
			pi[begin+matched-1] =matched;
		}
		else{
			if(matched==0) begin++;
			else{
				begin+=matched-pi[matched];
				matched=pi[matched-1];
			}
		}
	}
	
	return pi;
}

vector<int> kmpSearch(const string & H, const string &N){
	int n= H.size(), m= N.size();
	vector<int> res;
	vector<int> pi = getPartialMatch(N);
	int begin= 0,matched=0;
	while(begin<=n-m){
		if(matched< m && H[begin+matched] == N[matched]){
			++matched;
			if(matched==m)
			res.push_back(begin);
		}
		else{
			if(matched==0) ++begin;
			else{
				begin+=matched-pi[matched-1];
				matched = pi[matched-1];
			}
		}
		
		
		
	}
	
	
	return res;
}

int shift(const string & origin, const string & target){
	return kmpSearch(origin + origin, target)[0];
}

int main(){
	
	int t;cin>>t;
	
	for(int i=0 ;i<t;i++){
		int n;cin>>n;
		vector<int>dial;
		
		
		for(int i= 0; i<=n; i++){
			string tmp;
			cin>>tmp;
			dial.push_back(tmp);
		}
		
		int res= 0;
		for(int i=0 ;i<n;i++){
			int clockwise= i%2;
			
			if(clockwise) res += shift(dial[i], dial[i+1]);
			else res += shift(dial[i+1], dial[i]);
		}
	}
	
}
