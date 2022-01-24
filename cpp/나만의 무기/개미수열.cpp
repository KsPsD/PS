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


string NextNumber(const string& s){
	string res;
	for(int i=0; i<s.size() ;i++){
		int count =1;
		while(i+1 <s.size() && s[i] ==s[i+1]){
			++i; ++count;
		}
		res+= s[i]+to_string(count);
	}
	return res;
}
string LookAndSay(int n){
	string s="1";
	for(int i= 1; i< n; i++){
		s= NextNumber(s);
	}
	return s;
} 




int main(){
	
	cout<<LookAndSay(3)<<endl;
	
	
}
