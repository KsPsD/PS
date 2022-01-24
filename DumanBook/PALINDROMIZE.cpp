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

vector<int> getPartialMatch(const string& N){
	int m= N.size();
	vector<int> pi(m,0);
	int begin=1, matched=0;
	while(begin+matched<m){
		if(N[begin+matched] == N[matched]){
			++matched;
			pi[begin+matched-1] = matched;
		}
		
		else{
			if(matched==0) ++begin;
			else{
				begin+= matched- pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	
	return pi;
}

int maxOverlap(const string&a, const string& b){
	int n= a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);
	
	int begin = 0, matched = 0;
	while(begin<n){
		if(matched< m && a[begin+matched] == b[matched]){
			++matched;
			if(begin+matched==n)
			return matched;
		}
		
		else{
			if(matched==0) begin++;
			
			else{
				begin+=matched-pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	
	return 0;
}


int main(){
	int  t;cin>>t;
	for(int i=0;i<t; i++){
		string origin, reversed;
		cin>> origin;
		for(int i=origin.size()-1;i>=0; i--) reversed+=origin[i];
		
		int res= origin.length()*2 -maxOverlap(origin,reversed);
		cout<<res<<endl;
	}
	
}
